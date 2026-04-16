/**
 * @file tst_Matrix3.cpp
 * 
 * @brief Test cases for the Matrix3 class
 */

#include <gtest/gtest.h>
#include "Matrix3.hpp"

TEST(Matrix3_Constructors, Default) {
    gltkmath::Matrix3<float> matrix{};
    EXPECT_FLOAT_EQ(matrix.c0r0, 0.0f);
    EXPECT_FLOAT_EQ(matrix.c0r1, 0.0f);
    EXPECT_FLOAT_EQ(matrix.c0r2, 0.0f);
    EXPECT_FLOAT_EQ(matrix.c1r0, 0.0f);
    EXPECT_FLOAT_EQ(matrix.c1r1, 0.0f);
    EXPECT_FLOAT_EQ(matrix.c1r2, 0.0f);
    EXPECT_FLOAT_EQ(matrix.c2r0, 0.0f);
    EXPECT_FLOAT_EQ(matrix.c2r1, 0.0f);
    EXPECT_FLOAT_EQ(matrix.c2r2, 0.0f);

    gltkmath::Matrix3<std::size_t> sizeMatrix{};
    EXPECT_EQ(sizeMatrix.c0r0, 0);
    EXPECT_EQ(sizeMatrix.c0r1, 0);
    EXPECT_EQ(sizeMatrix.c0r2, 0);
    EXPECT_EQ(sizeMatrix.c1r0, 0);
    EXPECT_EQ(sizeMatrix.c1r1, 0);
    EXPECT_EQ(sizeMatrix.c1r2, 0);
    EXPECT_EQ(sizeMatrix.c2r0, 0);
    EXPECT_EQ(sizeMatrix.c2r1, 0);
    EXPECT_EQ(sizeMatrix.c2r2, 0);
}

TEST(Matrix3_Constructors, ComponentWise) {
    gltkmath::Matrix3 matrix{
        1.0f, 2.0f, 3.0f,
        4.0f, 5.0f, 6.0f,
        7.0f, 8.0f, 9.0f
    };
    EXPECT_FLOAT_EQ(matrix.c0r0, 1.0f);
    EXPECT_FLOAT_EQ(matrix.c0r1, 2.0f);
    EXPECT_FLOAT_EQ(matrix.c0r2, 3.0f);
    EXPECT_FLOAT_EQ(matrix.c1r0, 4.0f);
    EXPECT_FLOAT_EQ(matrix.c1r1, 5.0f);
    EXPECT_FLOAT_EQ(matrix.c1r2, 6.0f);
    EXPECT_FLOAT_EQ(matrix.c2r0, 7.0f);
    EXPECT_FLOAT_EQ(matrix.c2r1, 8.0f);
    EXPECT_FLOAT_EQ(matrix.c2r2, 9.0f);
}

TEST(Matrix3_Operators, Addition) {
    gltkmath::Matrix3 matrix{
        1.0f, 2.0f, 3.0f,
        4.0f, 5.0f, 6.0f,
        7.0f, 8.0f, 9.0f
    };
    gltkmath::Matrix3 result = matrix + matrix;
    EXPECT_FLOAT_EQ(result.c0r0, 2.0f);
    EXPECT_FLOAT_EQ(result.c0r1, 4.0f);
    EXPECT_FLOAT_EQ(result.c0r2, 6.0f);
    EXPECT_FLOAT_EQ(result.c1r0, 8.0f);
    EXPECT_FLOAT_EQ(result.c1r1, 10.0f);
    EXPECT_FLOAT_EQ(result.c1r2, 12.0f);
    EXPECT_FLOAT_EQ(result.c2r0, 14.0f);
    EXPECT_FLOAT_EQ(result.c2r1, 16.0f);
    EXPECT_FLOAT_EQ(result.c2r2, 18.0f);
}

TEST(Matrix3_Operators, Subtraction) {
    gltkmath::Matrix3 matrix{
        1.0f, 2.0f, 3.0f,
        4.0f, 5.0f, 6.0f,
        7.0f, 8.0f, 9.0f
    };
    gltkmath::Matrix3 result = matrix - matrix;
    EXPECT_FLOAT_EQ(result.c0r0, 0.0f);
    EXPECT_FLOAT_EQ(result.c0r1, 0.0f);
    EXPECT_FLOAT_EQ(result.c0r2, 0.0f);
    EXPECT_FLOAT_EQ(result.c1r0, 0.0f);
    EXPECT_FLOAT_EQ(result.c1r1, 0.0f);
    EXPECT_FLOAT_EQ(result.c1r2, 0.0f);
    EXPECT_FLOAT_EQ(result.c2r0, 0.0f);
    EXPECT_FLOAT_EQ(result.c2r1, 0.0f);
    EXPECT_FLOAT_EQ(result.c2r2, 0.0f);
}

TEST(Matrix3_Operators, UnarySubtraction) {
    gltkmath::Matrix3 matrix{
        1.0f, -2.0f, 3.0f,
        -4.0f, 5.0f, -6.0f,
        7.0f, -8.0f, 9.0f
    };
    gltkmath::Matrix3 result = -matrix;
    EXPECT_FLOAT_EQ(result.c0r0, -1.0f);
    EXPECT_FLOAT_EQ(result.c0r1, 2.0f);
    EXPECT_FLOAT_EQ(result.c0r2, -3.0f);
    EXPECT_FLOAT_EQ(result.c1r0, 4.0f);
    EXPECT_FLOAT_EQ(result.c1r1, -5.0f);
    EXPECT_FLOAT_EQ(result.c1r2, 6.0f);
    EXPECT_FLOAT_EQ(result.c2r0, -7.0f);
    EXPECT_FLOAT_EQ(result.c2r1, 8.0f);
    EXPECT_FLOAT_EQ(result.c2r2, -9.0f);
}

TEST(Matrix3_Operators, ScalarMultiplication) {
    gltkmath::Matrix3 matrix{
        1.0f, 2.0f, 3.0f,
        4.0f, 5.0f, 6.0f,
        7.0f, 8.0f, 9.0f
    };
    gltkmath::Matrix3 result = matrix * 2.0f;
    EXPECT_FLOAT_EQ(result.c0r0, 2.0f);
    EXPECT_FLOAT_EQ(result.c0r1, 4.0f);
    EXPECT_FLOAT_EQ(result.c0r2, 6.0f);
    EXPECT_FLOAT_EQ(result.c1r0, 8.0f);
    EXPECT_FLOAT_EQ(result.c1r1, 10.0f);
    EXPECT_FLOAT_EQ(result.c1r2, 12.0f);
    EXPECT_FLOAT_EQ(result.c2r0, 14.0f);
    EXPECT_FLOAT_EQ(result.c2r1, 16.0f);
    EXPECT_FLOAT_EQ(result.c2r2, 18.0f);
}
