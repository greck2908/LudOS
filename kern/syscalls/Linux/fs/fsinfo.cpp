/*
fsinfo.cpp

Copyright (c) 13 Yann BOUCHER (yann)

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/

#include "syscalls/Linux/syscalls.hpp"

#include "tasking/process.hpp"
#include "tasking/process_data.hpp"
#include "utils/user_ptr.hpp"
#include "errno.h"

#include "fs/vfs.hpp"

int sys_getcwd(user_ptr<char> buf, unsigned long size)
{
    if (!buf.check())
    {
        return -EFAULT;
    }

    if (size == 0)
    {
        return -EINVAL;
    }

    kpp::string pwd = Process::current().data->pwd->path();

    if (pwd.size() + 1 > size)
    {
        return -ERANGE;
    }

    std::copy(pwd.begin(), pwd.end(), buf.get());
    buf.get()[pwd.size()] = '\0';

    return EOK;
}
