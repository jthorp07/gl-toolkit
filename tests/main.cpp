/**
 * @file tests/main.cpp
 *
 * @brief Driver for the GLToolkit test suite
 */

#include <gtest/gtest.h>

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
