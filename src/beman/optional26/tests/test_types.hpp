// src/beman/optional26/tests/test_types.h -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef BEMAN_OPTIONAL26_TESTS_TEST_TYPES_HPP
#define BEMAN_OPTIONAL26_TESTS_TEST_TYPES_HPP

#include <compare>

namespace beman::optional26::tests {
// Classes used in the tests.

// Empty class helper.
struct empty {};

// No default constructor class helper.
struct no_default_ctor {
    no_default_ctor()                                  = delete;
    no_default_ctor(const no_default_ctor&)            = default;
    no_default_ctor(no_default_ctor&&)                 = default;
    no_default_ctor& operator=(const no_default_ctor&) = default;
    no_default_ctor& operator=(no_default_ctor&&)      = default;
    constexpr no_default_ctor(empty) {};
};

struct int_ctor {
    int i_;
    int_ctor() = delete;
    constexpr int_ctor(int i) : i_(i) {}
};

// Base class helper.
struct base {
    int m_i;
    constexpr base() : m_i(0) {}
    constexpr base(int i) : m_i(i) {}

    bool operator!=(const base&) const  = default;
    auto operator<=>(const base&) const = default;
};

// Derived class helper.
struct derived : public base {
    int m_j;
    constexpr derived() : base(), m_j(0) {}
    constexpr derived(int i, int j) : base(i), m_j(j) {}

    bool operator!=(const derived&) const  = default;
    auto operator<=>(const derived&) const = default;
};

struct move_detector {
    move_detector() = default;
    constexpr move_detector(move_detector&& rhs) { rhs.been_moved = true; }
    bool been_moved = false;
};

struct copyable_move_detector {
    constexpr copyable_move_detector()                            = default;
    constexpr copyable_move_detector(const copyable_move_detector&) = default;
    constexpr copyable_move_detector(copyable_move_detector&& rhs) { rhs.been_moved = true; }
    constexpr copyable_move_detector& operator=(const copyable_move_detector&) = default;
    constexpr copyable_move_detector& operator=(copyable_move_detector&& rhs) { rhs.been_moved = true; return *this;}

    bool been_moved = false;
};

class Point {
    int x_;
    int y_;

  public:
    constexpr Point() : x_(0), y_(0) {}
    constexpr Point(int x, int y) : x_(x), y_(y) {}
    auto operator<=>(const Point&) const = default;
    bool operator==(const Point&) const  = default;
};

struct immovable {
    explicit immovable()                   = default;
    immovable(const immovable&)            = delete;
    immovable& operator=(const immovable&) = delete;
};

struct copyable_from_non_const_lvalue_only {
    explicit copyable_from_non_const_lvalue_only()                                              = default;
    copyable_from_non_const_lvalue_only(copyable_from_non_const_lvalue_only&)                   = default;
    copyable_from_non_const_lvalue_only(const copyable_from_non_const_lvalue_only&)             = delete;
    copyable_from_non_const_lvalue_only(copyable_from_non_const_lvalue_only&&)                  = delete;
    copyable_from_non_const_lvalue_only(const copyable_from_non_const_lvalue_only&&)            = delete;
    copyable_from_non_const_lvalue_only& operator=(copyable_from_non_const_lvalue_only&)        = default;
    copyable_from_non_const_lvalue_only& operator=(const copyable_from_non_const_lvalue_only&)  = delete;
    copyable_from_non_const_lvalue_only& operator=(copyable_from_non_const_lvalue_only&&)       = delete;
    copyable_from_non_const_lvalue_only& operator=(const copyable_from_non_const_lvalue_only&&) = delete;
};

struct explicitly_convertible_from_non_const_lvalue_only {
    explicit operator copyable_from_non_const_lvalue_only() & { return copyable_from_non_const_lvalue_only{}; }
    explicit operator copyable_from_non_const_lvalue_only() const&  = delete;
    explicit operator copyable_from_non_const_lvalue_only() &&      = delete;
    explicit operator copyable_from_non_const_lvalue_only() const&& = delete;
};

struct copyable_from_const_lvalue_only {
    explicit copyable_from_const_lvalue_only()                                          = default;
    copyable_from_const_lvalue_only(copyable_from_const_lvalue_only&)                   = delete;
    copyable_from_const_lvalue_only(const copyable_from_const_lvalue_only&)             = default;
    copyable_from_const_lvalue_only(copyable_from_const_lvalue_only&&)                  = delete;
    copyable_from_const_lvalue_only(const copyable_from_const_lvalue_only&&)            = delete;
    copyable_from_const_lvalue_only& operator=(copyable_from_const_lvalue_only&)        = delete;
    copyable_from_const_lvalue_only& operator=(const copyable_from_const_lvalue_only&)  = default;
    copyable_from_const_lvalue_only& operator=(copyable_from_const_lvalue_only&&)       = delete;
    copyable_from_const_lvalue_only& operator=(const copyable_from_const_lvalue_only&&) = delete;
};

struct explicitly_convertible_from_const_lvalue_only {
    explicit operator copyable_from_const_lvalue_only() & = delete;
    explicit operator copyable_from_const_lvalue_only() const& { return copyable_from_const_lvalue_only{}; }
    explicit operator copyable_from_const_lvalue_only() &&      = delete;
    explicit operator copyable_from_const_lvalue_only() const&& = delete;
};

} // namespace beman::optional26::tests

#endif // BEMAN_OPTIONAL26_TESTS_TEST_TYPES_HPP
