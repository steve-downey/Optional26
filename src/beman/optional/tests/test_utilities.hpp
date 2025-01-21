// src/beman/optional/tests/test_utilities.hpp                      -*-C++-*-
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef BEMAN_OPTIONAL_TESTS_TEST_UTILITIES_HPP
#define BEMAN_OPTIONAL_TESTS_TEST_UTILITIES_HPP

namespace beman::optional::tests {
/***
 * Evaluate and return an expression in a consteval context for testing
 * constexpr correctness.
 */
auto consteval constify(auto expr) { return (expr); }
} // namespace beman::optional::tests

#endif
