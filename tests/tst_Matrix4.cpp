/**
 * @file tst_Matrix4.cpp
 * 
 * @brief Test cases for the Matrix4 class
 */

#include <gtest/gtest.h>
#include "Matrix4.hpp"
#include "Vector4.hpp"

#include <array>
#include <tuple>
#include <utility>

TEST(Matrix4_Constructors, Default) {
    gltkmath::Matrix4<float> matrix{};
    for (std::size_t column = 0; column < 4; ++column) {
        for (std::size_t row = 0; row < 4; ++row) {
            EXPECT_FLOAT_EQ(matrix(column, row), 0.0f);
        }
    }

    gltkmath::Matrix4<std::size_t> sizeMatrix{};
    for (std::size_t column = 0; column < 4; ++column) {
        for (std::size_t row = 0; row < 4; ++row) {
            EXPECT_EQ(sizeMatrix(column, row), 0);
        }
    }
}
