/*
stdlib.h

Copyright (c) 23 Yann BOUCHER (yann)

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
#ifndef L_STDLIB_H
#define L_STDLIB_H 1

#include <sys/cdefs.h>

#include <stdint.h>

#include "liballoc/liballoc.h"

//#define malloc kmalloc
//#define free kfree

#ifdef __cplusplus
extern "C" {
#endif

__attribute__((__noreturn__))
void abort_impl(const char* file, size_t line, const char* fun);

__attribute__((__noreturn__))
void _abort();

#define abort() abort_impl(__FILE__, __LINE__, __PRETTY_FUNCTION__)

#ifdef __cplusplus
}
#endif

#endif
