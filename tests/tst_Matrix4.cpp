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

TEST(Matrix4_Constructors, ComponentWise) {
    gltkmath::Matrix4 matrix{
         1.0f,  2.0f,  3.0f,  4.0f,
         5.0f,  6.0f,  7.0f,  8.0f,
         9.0f, 10.0f, 11.0f, 12.0f,
        13.0f, 14.0f, 15.0f, 16.0f
    };
    EXPECT_FLOAT_EQ(matrix(0, 0), 1.0f);
    EXPECT_FLOAT_EQ(matrix(0, 1), 5.0f);
    EXPECT_FLOAT_EQ(matrix(0, 2), 9.0f);
    EXPECT_FLOAT_EQ(matrix(0, 3), 13.0f);
    EXPECT_FLOAT_EQ(matrix(1, 0), 2.0f);
    EXPECT_FLOAT_EQ(matrix(1, 1), 6.0f);
    EXPECT_FLOAT_EQ(matrix(1, 2), 10.0f);
    EXPECT_FLOAT_EQ(matrix(1, 3), 14.0f);
    EXPECT_FLOAT_EQ(matrix(2, 0), 3.0f);
    EXPECT_FLOAT_EQ(matrix(2, 1), 7.0f);
    EXPECT_FLOAT_EQ(matrix(2, 2), 11.0f);
    EXPECT_FLOAT_EQ(matrix(2, 3), 15.0f);
    EXPECT_FLOAT_EQ(matrix(3, 0), 4.0f);
    EXPECT_FLOAT_EQ(matrix(3, 1), 8.0f);
    EXPECT_FLOAT_EQ(matrix(3, 2), 12.0f);
    EXPECT_FLOAT_EQ(matrix(3, 3), 16.0f);
}
