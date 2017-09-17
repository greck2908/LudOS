// -*- C++ -*-
//===----------------------- initializer_list -----------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#ifndef _LIBCPP_INITIALIZER_LIST
#define _LIBCPP_INITIALIZER_LIST

/*
    initializer_list synopsis

namespace std
{

template<class E>
class initializer_list
{
public:
    typedef E        value_type;
    typedef const E& reference;
    typedef const E& const_reference;
    typedef size_t   size_type;

    typedef const E* iterator;
    typedef const E* const_iterator;

    initializer_list() noexcept; // constexpr in C++14

    size_t   size()  const noexcept; // constexpr in C++14
    const E* begin() const noexcept; // constexpr in C++14
    const E* end()   const noexcept; // constexpr in C++14
};

template<class E> const E* begin(initializer_list<E> il) noexcept; // constexpr in C++14
template<class E> const E* end(initializer_list<E> il) noexcept; // constexpr in C++14

}  // std

*/

#include "__config.hpp"
#include <stddef.h>

#if !defined(_LIBCPP_HAS_NO_PRAGMA_SYSTEM_HEADER)
#pragma GCC system_header
#endif

namespace std  // purposefully not versioned
{

#ifndef _LIBCPP_CXX03_LANG

template<class _Ep>
class _LIBCPP_TEMPLATE_VIS initializer_list
{
    const _Ep* __begin_;
    size_t    __size_;

    _LIBCPP_ALWAYS_INLINE
    _LIBCPP_CONSTEXPR_AFTER_CXX11
    initializer_list(const _Ep* __b, size_t __s) _NOEXCEPT
        : __begin_(__b),
          __size_(__s)
        {}
public:
    typedef _Ep        value_type;
    typedef const _Ep& reference;
    typedef const _Ep& const_reference;
    typedef size_t    size_type;

    typedef const _Ep* iterator;
    typedef const _Ep* const_iterator;

    _LIBCPP_ALWAYS_INLINE
    _LIBCPP_CONSTEXPR_AFTER_CXX11
    initializer_list() _NOEXCEPT : __begin_(nullptr), __size_(0) {}

    _LIBCPP_ALWAYS_INLINE
    _LIBCPP_CONSTEXPR_AFTER_CXX11
    size_t    size()  const _NOEXCEPT {return __size_;}

    _LIBCPP_ALWAYS_INLINE
    _LIBCPP_CONSTEXPR_AFTER_CXX11
    const _Ep* begin() const _NOEXCEPT {return __begin_;}

    _LIBCPP_ALWAYS_INLINE
    _LIBCPP_CONSTEXPR_AFTER_CXX11
    const _Ep* end()   const _NOEXCEPT {return __begin_ + __size_;}
};

template<class _Ep>
inline _LIBCPP_INLINE_VISIBILITY
_LIBCPP_CONSTEXPR_AFTER_CXX11
const _Ep*
begin(initializer_list<_Ep> __il) _NOEXCEPT
{
    return __il.begin();
}

template<class _Ep>
inline _LIBCPP_INLINE_VISIBILITY
_LIBCPP_CONSTEXPR_AFTER_CXX11
const _Ep*
end(initializer_list<_Ep> __il) _NOEXCEPT
{
    return __il.end();
}

#endif  // !defined(_LIBCPP_CXX03_LANG)

}  // std

#endif  // _LIBCPP_INITIALIZER_LIST