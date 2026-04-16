/**
 * @file tst_Matrix3.cpp
 * 
 * @brief Test cases for the Matrix3 class
 */

#include <gtest/gtest.h>
#include "Matrix3.hpp"
#include "Vector3.hpp"

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
    EXPECT_FLOAT_EQ(matrix.c0r1, 4.0f);
    EXPECT_FLOAT_EQ(matrix.c0r2, 7.0f);
    EXPECT_FLOAT_EQ(matrix.c1r0, 2.0f);
    EXPECT_FLOAT_EQ(matrix.c1r1, 5.0f);
    EXPECT_FLOAT_EQ(matrix.c1r2, 8.0f);
    EXPECT_FLOAT_EQ(matrix.c2r0, 3.0f);
    EXPECT_FLOAT_EQ(matrix.c2r1, 6.0f);
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

TEST(Matrix3_Operators, ScalarMultiplicationLeft) {
    gltkmath::Matrix3 matrix{
        1.0f, 2.0f, 3.0f,
        4.0f, 5.0f, 6.0f,
        7.0f, 8.0f, 9.0f
    };
    gltkmath::Matrix3 result = 2.0f * matrix;
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

TEST(Matrix3_Operators, VectorMultiplication) {
    gltkmath::Matrix3 matrix{
        2.0f, 2.0f, 2.0f,
        4.0f, 2.0f, 6.0f,
        8.0f, 8.0f, 2.0f
    };
    gltkmath::Vector3 vector{2.0f, 2.0f, 4.0f};
    gltkmath::Vector3 result = matrix * vector;

    EXPECT_FLOAT_EQ(result.x, 16.0f);
    EXPECT_FLOAT_EQ(result.y, 36.0f);
    EXPECT_FLOAT_EQ(result.z, 40.0f);
}

TEST(Matrix3_Operators, MatrixMultiplication) {
    gltkmath::Matrix3 matrixA{
        1.0f, 2.0f, 3.0f,
        4.0f, 5.0f, 6.0f,
        7.0f, 8.0f, 9.0f
    };
    gltkmath::Matrix3 matrixB{
        -1.0f,  4.0f, -7.0f,
         2.0f, -5.0f,  8.0f,
        -3.0f,  6.0f, -9.0f
    };
    gltkmath::Matrix3 resultAB = matrixA * matrixB;
    gltkmath::Matrix3 resultBA = matrixB * matrixA;

    /*
        | 1  2  3 |   | -1   4  -7 |   |  -6  12  -18 |
        | 4  5  6 | * |  2  -5   8 | = | -12  27  -42 |
        | 7  8  9 |   | -3   6  -9 |   | -18  42  -66 |
    */
    EXPECT_FLOAT_EQ(resultAB.c0r0, -6.0f);
    EXPECT_FLOAT_EQ(resultAB.c0r1, -12.0f);
    EXPECT_FLOAT_EQ(resultAB.c0r2, -18.0f);
    EXPECT_FLOAT_EQ(resultAB.c1r0,  12.0f);
    EXPECT_FLOAT_EQ(resultAB.c1r1,  27.0f);
    EXPECT_FLOAT_EQ(resultAB.c1r2,  42.0f);
    EXPECT_FLOAT_EQ(resultAB.c2r0, -18.0f);
    EXPECT_FLOAT_EQ(resultAB.c2r1, -42.0f);
    EXPECT_FLOAT_EQ(resultAB.c2r2, -66.0f);

    /*
        | -1   4  -7 |   | 1  2  3 |   | -34  -38  -42 |
        |  2  -5   8 | * | 4  5  6 | = |  38   43   48 |
        | -3   6  -9 |   | 7  8  9 |   | -42  -48  -54 |
    */
    EXPECT_FLOAT_EQ(resultBA.c0r0, -34.0f);
    EXPECT_FLOAT_EQ(resultBA.c0r1,  38.0f);
    EXPECT_FLOAT_EQ(resultBA.c0r2, -42.0f);
    EXPECT_FLOAT_EQ(resultBA.c1r0, -38.0f);
    EXPECT_FLOAT_EQ(resultBA.c1r1,  43.0f);
    EXPECT_FLOAT_EQ(resultBA.c1r2, -48.0f);
    EXPECT_FLOAT_EQ(resultBA.c2r0, -42.0f);
    EXPECT_FLOAT_EQ(resultBA.c2r1,  48.0f);
    EXPECT_FLOAT_EQ(resultBA.c2r2, -54.0f);
}

TEST(Matrix3_Operators, AdditionAssignment) {
    gltkmath::Matrix3 matrix{
        1.0f, 2.0f, 3.0f,
        4.0f, 5.0f, 6.0f,
        7.0f, 8.0f, 9.0f
    };
    gltkmath::Matrix3 other{
        1.0f, 2.0f, 3.0f,
        4.0f, 5.0f, 6.0f,
        7.0f, 8.0f, 9.0f
    };
    matrix += other;
    EXPECT_FLOAT_EQ(matrix.c0r0, 2.0f);
    EXPECT_FLOAT_EQ(matrix.c0r1, 8.0f);
    EXPECT_FLOAT_EQ(matrix.c0r2, 14.0f);
    EXPECT_FLOAT_EQ(matrix.c1r0, 4.0f);
    EXPECT_FLOAT_EQ(matrix.c1r1, 10.0f);
    EXPECT_FLOAT_EQ(matrix.c1r2, 16.0f);
    EXPECT_FLOAT_EQ(matrix.c2r0, 6.0f);
    EXPECT_FLOAT_EQ(matrix.c2r1, 12.0f);
    EXPECT_FLOAT_EQ(matrix.c2r2, 18.0f);
}

TEST(Matrix3_Operators, SubtractionAssignment) {
    gltkmath::Matrix3 matrix{
        1.0f, 2.0f, 3.0f,
        4.0f, 5.0f, 6.0f,
        7.0f, 8.0f, 9.0f
    };
    gltkmath::Matrix3 other{
        1.0f, 2.0f, 3.0f,
        4.0f, 5.0f, 6.0f,
        7.0f, 8.0f, 9.0f
    };
    matrix -= other;
    EXPECT_FLOAT_EQ(matrix.c0r0, 0.0f);
    EXPECT_FLOAT_EQ(matrix.c0r1, 0.0f);
    EXPECT_FLOAT_EQ(matrix.c0r2, 0.0f);
    EXPECT_FLOAT_EQ(matrix.c1r0, 0.0f);
    EXPECT_FLOAT_EQ(matrix.c1r1, 0.0f);
    EXPECT_FLOAT_EQ(matrix.c1r2, 0.0f);
    EXPECT_FLOAT_EQ(matrix.c2r0, 0.0f);
    EXPECT_FLOAT_EQ(matrix.c2r1, 0.0f);
    EXPECT_FLOAT_EQ(matrix.c2r2, 0.0f);
}

TEST(Matrix3_Operators, ScalarMultiplicationAssignment) {
    gltkmath::Matrix3 matrix{
        1.0f, 2.0f, 3.0f,
        4.0f, 5.0f, 6.0f,
        7.0f, 8.0f, 9.0f
    };
    matrix *= 2.0f;
    EXPECT_FLOAT_EQ(matrix.c0r0, 2.0f);
    EXPECT_FLOAT_EQ(matrix.c0r1, 8.0f);
    EXPECT_FLOAT_EQ(matrix.c0r2, 14.0f);
    EXPECT_FLOAT_EQ(matrix.c1r0, 4.0f);
    EXPECT_FLOAT_EQ(matrix.c1r1, 10.0f);
    EXPECT_FLOAT_EQ(matrix.c1r2, 16.0f);
    EXPECT_FLOAT_EQ(matrix.c2r0, 6.0f);
    EXPECT_FLOAT_EQ(matrix.c2r1, 12.0f);
    EXPECT_FLOAT_EQ(matrix.c2r2, 18.0f);
}

TEST(Matrix3_Operators, MatrixMultiplicationAssignment) {
    gltkmath::Matrix3 matrix{
        1.0f, 2.0f, 3.0f,
        4.0f, 5.0f, 6.0f,
        7.0f, 8.0f, 9.0f
    };
    gltkmath::Matrix3 other{
        -1.0f, 4.0f, -7.0f,
         2.0f, -5.0f, 8.0f,
        -3.0f, 6.0f, -9.0f
    };
    matrix *= other;

    /*
        | 1  2  3 |   | -1   4  -7 |   |  -6  12  -18 |
        | 4  5  6 | * |  2  -5   8 | = | -12  27  -42 |
        | 7  8  9 |   | -3   6  -9 |   | -18  42  -66 |
    */
    EXPECT_FLOAT_EQ(matrix.c0r0, -6.0f);
    EXPECT_FLOAT_EQ(matrix.c0r1, -12.0f);
    EXPECT_FLOAT_EQ(matrix.c0r2, -18.0f);
    EXPECT_FLOAT_EQ(matrix.c1r0, 12.0f);
    EXPECT_FLOAT_EQ(matrix.c1r1, 27.0f);
    EXPECT_FLOAT_EQ(matrix.c1r2, 42.0f);
    EXPECT_FLOAT_EQ(matrix.c2r0, -18.0f);
    EXPECT_FLOAT_EQ(matrix.c2r1, -42.0f);
    EXPECT_FLOAT_EQ(matrix.c2r2, -66.0f);
}
