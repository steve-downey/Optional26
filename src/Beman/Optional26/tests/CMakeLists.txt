# cmake-format: off
# src/Beman/Optional26/tests/CMakeLists.txt -*-makefile-*-
# SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
# cmake-format: on

include(GoogleTest)

# Tests
add_executable(
  beman_optional26_test
  detail/iterator.t.cpp optional_monadic.t.cpp optional_range_support.t.cpp
  optional_ref_monadic.t.cpp optional_ref.t.cpp optional.t.cpp)

target_link_libraries(beman_optional26_test beman_optional26 GTest::gtest
                      GTest::gtest_main)

# Issue #32: Re-enable ASAN run CI/clang-19.
#
# Note: clang-19 + gtest_discover_tests + Asan setup causes errors on some
# platforms. Temporary switch to gtest_add_tests and skip some Asan checks.
# Change also applied for CI flows.
gtest_add_tests(TARGET beman_optional26_test "" AUTO)
