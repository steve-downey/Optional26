// include/Beman/Optional26/detail/stl_interfaces/config.hpp -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

// Copyright (C) 2020 T. Zachary Laine
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
#ifndef BEMAN_OPTIONAL26_DETAIL_STL_INTERFACES_CONFIG_HPP
#define BEMAN_OPTIONAL26_DETAIL_STL_INTERFACES_CONFIG_HPP

// Included for definition of __cpp_lib_concepts.
#include <iterator>

#if defined(__cpp_lib_concepts) && defined(__cpp_lib_ranges) && \
    !defined(BEMAN_OPTIONAL26_DETAIL_STL_INTERFACES_DISABLE_CONCEPTS)
#define BEMAN_OPTIONAL26_DETAIL_STL_INTERFACES_USE_CONCEPTS 1
#else
#define BEMAN_OPTIONAL26_DETAIL_STL_INTERFACES_USE_CONCEPTS 0
#endif

#if defined(__cpp_explicit_this_parameter) && BEMAN_OPTIONAL26_DETAIL_STL_INTERFACES_USE_CONCEPTS && \
    !defined(BEMAN_OPTIONAL26_DETAIL_STL_INTERFACES_DISABLE_DEDUCED_THIS)
#define BEMAN_OPTIONAL26_DETAIL_STL_INTERFACES_USE_DEDUCED_THIS 1
#else
#define BEMAN_OPTIONAL26_DETAIL_STL_INTERFACES_USE_DEDUCED_THIS 0
#endif

// The inline namespaces v1, v2, and v3 represent C++14, C++20, and C++23 and
// later, respectively.  v1 is inline for standards before C++20, and v2 is
// inline for C++20 and later.  Note that this only applies to code for which
// multiple vI namespace alternatives exist.  For example, some instances of
// the v1 namespace may still be inline, if there is no v2 version of its
// contents.
#if !BEMAN_OPTIONAL26_DETAIL_STL_INTERFACES_USE_CONCEPTS && !BEMAN_OPTIONAL26_DETAIL_STL_INTERFACES_USE_DEDUCED_THIS
#define BEMAN_OPTIONAL26_DETAIL_STL_INTERFACES_NAMESPACE_V1 inline namespace v1
#define BEMAN_OPTIONAL26_DETAIL_STL_INTERFACES_NAMESPACE_V2 namespace v2
#define BEMAN_OPTIONAL26_DETAIL_STL_INTERFACES_NAMESPACE_V3 namespace v3
#elif BEMAN_OPTIONAL26_DETAIL_STL_INTERFACES_USE_CONCEPTS && !BEMAN_OPTIONAL26_DETAIL_STL_INTERFACES_USE_DEDUCED_THIS
#define BEMAN_OPTIONAL26_DETAIL_STL_INTERFACES_NAMESPACE_V1 namespace v1
#define BEMAN_OPTIONAL26_DETAIL_STL_INTERFACES_NAMESPACE_V2 inline namespace v2
#define BEMAN_OPTIONAL26_DETAIL_STL_INTERFACES_NAMESPACE_V3 namespace v3
#else
#define BEMAN_OPTIONAL26_DETAIL_STL_INTERFACES_NAMESPACE_V1 namespace v1
#define BEMAN_OPTIONAL26_DETAIL_STL_INTERFACES_NAMESPACE_V2 namespace v2
#define BEMAN_OPTIONAL26_DETAIL_STL_INTERFACES_NAMESPACE_V3 inline namespace v3
#endif

#endif
