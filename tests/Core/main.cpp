/**
 * @file tests/Core/main.cpp
 *
 * @brief Driver for the Core test suite
 */

#include <gtest/gtest.h>

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
