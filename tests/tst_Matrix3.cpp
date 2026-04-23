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
    EXPECT_FLOAT_EQ(matrix(0, 0), 0.0f);
    EXPECT_FLOAT_EQ(matrix(0, 1), 0.0f);
    EXPECT_FLOAT_EQ(matrix(0, 2), 0.0f);
    EXPECT_FLOAT_EQ(matrix(1, 0), 0.0f);
    EXPECT_FLOAT_EQ(matrix(1, 1), 0.0f);
    EXPECT_FLOAT_EQ(matrix(1, 2), 0.0f);
    EXPECT_FLOAT_EQ(matrix(2, 0), 0.0f);
    EXPECT_FLOAT_EQ(matrix(2, 1), 0.0f);
    EXPECT_FLOAT_EQ(matrix(2, 2), 0.0f);

    gltkmath::Matrix3<std::size_t> sizeMatrix{};
    EXPECT_EQ(sizeMatrix(0, 0), 0);
    EXPECT_EQ(sizeMatrix(0, 1), 0);
    EXPECT_EQ(sizeMatrix(0, 2), 0);
    EXPECT_EQ(sizeMatrix(1, 0), 0);
    EXPECT_EQ(sizeMatrix(1, 1), 0);
    EXPECT_EQ(sizeMatrix(1, 2), 0);
    EXPECT_EQ(sizeMatrix(2, 0), 0);
    EXPECT_EQ(sizeMatrix(2, 1), 0);
    EXPECT_EQ(sizeMatrix(2, 2), 0);
}

TEST(Matrix3_Constructors, ComponentWise) {
    gltkmath::Matrix3 matrix{
        1.0f, 2.0f, 3.0f,
        4.0f, 5.0f, 6.0f,
        7.0f, 8.0f, 9.0f
    };
    EXPECT_FLOAT_EQ(matrix(0, 0), 1.0f);
    EXPECT_FLOAT_EQ(matrix(0, 1), 4.0f);
    EXPECT_FLOAT_EQ(matrix(0, 2), 7.0f);
    EXPECT_FLOAT_EQ(matrix(1, 0), 2.0f);
    EXPECT_FLOAT_EQ(matrix(1, 1), 5.0f);
    EXPECT_FLOAT_EQ(matrix(1, 2), 8.0f);
    EXPECT_FLOAT_EQ(matrix(2, 0), 3.0f);
    EXPECT_FLOAT_EQ(matrix(2, 1), 6.0f);
    EXPECT_FLOAT_EQ(matrix(2, 2), 9.0f);
}

TEST(Matrix3_Operators, Addition) {
    gltkmath::Matrix3 matrix{
        1.0f, 2.0f, 3.0f,
        4.0f, 5.0f, 6.0f,
        7.0f, 8.0f, 9.0f
    };
    gltkmath::Matrix3 result = matrix + matrix;
    EXPECT_FLOAT_EQ(result(0, 0), 2.0f);
    EXPECT_FLOAT_EQ(result(0, 1), 4.0f);
    EXPECT_FLOAT_EQ(result(0, 2), 6.0f);
    EXPECT_FLOAT_EQ(result(1, 0), 8.0f);
    EXPECT_FLOAT_EQ(result(1, 1), 10.0f);
    EXPECT_FLOAT_EQ(result(1, 2), 12.0f);
    EXPECT_FLOAT_EQ(result(2, 0), 14.0f);
    EXPECT_FLOAT_EQ(result(2, 1), 16.0f);
    EXPECT_FLOAT_EQ(result(2, 2), 18.0f);
}

TEST(Matrix3_Operators, Subtraction) {
    gltkmath::Matrix3 matrix{
        1.0f, 2.0f, 3.0f,
        4.0f, 5.0f, 6.0f,
        7.0f, 8.0f, 9.0f
    };
    gltkmath::Matrix3 result = matrix - matrix;
    EXPECT_FLOAT_EQ(result(0, 0), 0.0f);
    EXPECT_FLOAT_EQ(result(0, 1), 0.0f);
    EXPECT_FLOAT_EQ(result(0, 2), 0.0f);
    EXPECT_FLOAT_EQ(result(1, 0), 0.0f);
    EXPECT_FLOAT_EQ(result(1, 1), 0.0f);
    EXPECT_FLOAT_EQ(result(1, 2), 0.0f);
    EXPECT_FLOAT_EQ(result(2, 0), 0.0f);
    EXPECT_FLOAT_EQ(result(2, 1), 0.0f);
    EXPECT_FLOAT_EQ(result(2, 2), 0.0f);
}

TEST(Matrix3_Operators, UnarySubtraction) {
    gltkmath::Matrix3 matrix{
        1.0f, -2.0f, 3.0f,
        -4.0f, 5.0f, -6.0f,
        7.0f, -8.0f, 9.0f
    };
    gltkmath::Matrix3 result = -matrix;
    EXPECT_FLOAT_EQ(result(0, 0), -1.0f);
    EXPECT_FLOAT_EQ(result(0, 1), 2.0f);
    EXPECT_FLOAT_EQ(result(0, 2), -3.0f);
    EXPECT_FLOAT_EQ(result(1, 0), 4.0f);
    EXPECT_FLOAT_EQ(result(1, 1), -5.0f);
    EXPECT_FLOAT_EQ(result(1, 2), 6.0f);
    EXPECT_FLOAT_EQ(result(2, 0), -7.0f);
    EXPECT_FLOAT_EQ(result(2, 1), 8.0f);
    EXPECT_FLOAT_EQ(result(2, 2), -9.0f);
}

TEST(Matrix3_Operators, ScalarMultiplication) {
    gltkmath::Matrix3 matrix{
        1.0f, 2.0f, 3.0f,
        4.0f, 5.0f, 6.0f,
        7.0f, 8.0f, 9.0f
    };
    gltkmath::Matrix3 result = matrix * 2.0f;
    EXPECT_FLOAT_EQ(result(0, 0), 2.0f);
    EXPECT_FLOAT_EQ(result(0, 1), 4.0f);
    EXPECT_FLOAT_EQ(result(0, 2), 6.0f);
    EXPECT_FLOAT_EQ(result(1, 0), 8.0f);
    EXPECT_FLOAT_EQ(result(1, 1), 10.0f);
    EXPECT_FLOAT_EQ(result(1, 2), 12.0f);
    EXPECT_FLOAT_EQ(result(2, 0), 14.0f);
    EXPECT_FLOAT_EQ(result(2, 1), 16.0f);
    EXPECT_FLOAT_EQ(result(2, 2), 18.0f);
}

TEST(Matrix3_Operators, ScalarMultiplicationLeft) {
    gltkmath::Matrix3 matrix{
        1.0f, 2.0f, 3.0f,
        4.0f, 5.0f, 6.0f,
        7.0f, 8.0f, 9.0f
    };
    gltkmath::Matrix3 result = 2.0f * matrix;
    EXPECT_FLOAT_EQ(result(0, 0), 2.0f);
    EXPECT_FLOAT_EQ(result(0, 1), 4.0f);
    EXPECT_FLOAT_EQ(result(0, 2), 6.0f);
    EXPECT_FLOAT_EQ(result(1, 0), 8.0f);
    EXPECT_FLOAT_EQ(result(1, 1), 10.0f);
    EXPECT_FLOAT_EQ(result(1, 2), 12.0f);
    EXPECT_FLOAT_EQ(result(2, 0), 14.0f);
    EXPECT_FLOAT_EQ(result(2, 1), 16.0f);
    EXPECT_FLOAT_EQ(result(2, 2), 18.0f);
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
    EXPECT_FLOAT_EQ(resultAB(0, 0), -6.0f);
    EXPECT_FLOAT_EQ(resultAB(0, 1), -12.0f);
    EXPECT_FLOAT_EQ(resultAB(0, 2), -18.0f);
    EXPECT_FLOAT_EQ(resultAB(1, 0),  12.0f);
    EXPECT_FLOAT_EQ(resultAB(1, 1),  27.0f);
    EXPECT_FLOAT_EQ(resultAB(1, 2),  42.0f);
    EXPECT_FLOAT_EQ(resultAB(2, 0), -18.0f);
    EXPECT_FLOAT_EQ(resultAB(2, 1), -42.0f);
    EXPECT_FLOAT_EQ(resultAB(2, 2), -66.0f);

    /*
        | -1   4  -7 |   | 1  2  3 |   | -34  -38  -42 |
        |  2  -5   8 | * | 4  5  6 | = |  38   43   48 |
        | -3   6  -9 |   | 7  8  9 |   | -42  -48  -54 |
    */
    EXPECT_FLOAT_EQ(resultBA(0, 0), -34.0f);
    EXPECT_FLOAT_EQ(resultBA(0, 1),  38.0f);
    EXPECT_FLOAT_EQ(resultBA(0, 2), -42.0f);
    EXPECT_FLOAT_EQ(resultBA(1, 0), -38.0f);
    EXPECT_FLOAT_EQ(resultBA(1, 1),  43.0f);
    EXPECT_FLOAT_EQ(resultBA(1, 2), -48.0f);
    EXPECT_FLOAT_EQ(resultBA(2, 0), -42.0f);
    EXPECT_FLOAT_EQ(resultBA(2, 1),  48.0f);
    EXPECT_FLOAT_EQ(resultBA(2, 2), -54.0f);
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
    EXPECT_FLOAT_EQ(matrix(0, 0), 2.0f);
    EXPECT_FLOAT_EQ(matrix(0, 1), 8.0f);
    EXPECT_FLOAT_EQ(matrix(0, 2), 14.0f);
    EXPECT_FLOAT_EQ(matrix(1, 0), 4.0f);
    EXPECT_FLOAT_EQ(matrix(1, 1), 10.0f);
    EXPECT_FLOAT_EQ(matrix(1, 2), 16.0f);
    EXPECT_FLOAT_EQ(matrix(2, 0), 6.0f);
    EXPECT_FLOAT_EQ(matrix(2, 1), 12.0f);
    EXPECT_FLOAT_EQ(matrix(2, 2), 18.0f);
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
    EXPECT_FLOAT_EQ(matrix(0, 0), 0.0f);
    EXPECT_FLOAT_EQ(matrix(0, 1), 0.0f);
    EXPECT_FLOAT_EQ(matrix(0, 2), 0.0f);
    EXPECT_FLOAT_EQ(matrix(1, 0), 0.0f);
    EXPECT_FLOAT_EQ(matrix(1, 1), 0.0f);
    EXPECT_FLOAT_EQ(matrix(1, 2), 0.0f);
    EXPECT_FLOAT_EQ(matrix(2, 0), 0.0f);
    EXPECT_FLOAT_EQ(matrix(2, 1), 0.0f);
    EXPECT_FLOAT_EQ(matrix(2, 2), 0.0f);
}

TEST(Matrix3_Operators, ScalarMultiplicationAssignment) {
    gltkmath::Matrix3 matrix{
        1.0f, 2.0f, 3.0f,
        4.0f, 5.0f, 6.0f,
        7.0f, 8.0f, 9.0f
    };
    matrix *= 2.0f;
    EXPECT_FLOAT_EQ(matrix(0, 0), 2.0f);
    EXPECT_FLOAT_EQ(matrix(0, 1), 8.0f);
    EXPECT_FLOAT_EQ(matrix(0, 2), 14.0f);
    EXPECT_FLOAT_EQ(matrix(1, 0), 4.0f);
    EXPECT_FLOAT_EQ(matrix(1, 1), 10.0f);
    EXPECT_FLOAT_EQ(matrix(1, 2), 16.0f);
    EXPECT_FLOAT_EQ(matrix(2, 0), 6.0f);
    EXPECT_FLOAT_EQ(matrix(2, 1), 12.0f);
    EXPECT_FLOAT_EQ(matrix(2, 2), 18.0f);
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
    EXPECT_FLOAT_EQ(matrix(0, 0), -6.0f);
    EXPECT_FLOAT_EQ(matrix(0, 1), -12.0f);
    EXPECT_FLOAT_EQ(matrix(0, 2), -18.0f);
    EXPECT_FLOAT_EQ(matrix(1, 0), 12.0f);
    EXPECT_FLOAT_EQ(matrix(1, 1), 27.0f);
    EXPECT_FLOAT_EQ(matrix(1, 2), 42.0f);
    EXPECT_FLOAT_EQ(matrix(2, 0), -18.0f);
    EXPECT_FLOAT_EQ(matrix(2, 1), -42.0f);
    EXPECT_FLOAT_EQ(matrix(2, 2), -66.0f);
}

TEST(Matrix3, cast) {
    gltkmath::Matrix3 floatMatrix{
        1.0f, 2.0f, 3.0f,
        4.0f, 5.0f, 6.0f,
        7.0f, 8.0f, 9.0f
    };
    gltkmath::Matrix3 doubleMatrix = floatMatrix.cast<double>();
    std::ignore = doubleMatrix;
    ::testing::StaticAssertTypeEq<decltype(floatMatrix), gltkmath::Matrix3<float>>();
    ::testing::StaticAssertTypeEq<decltype(doubleMatrix), gltkmath::Matrix3<double>>();
    ::testing::StaticAssertTypeEq<
        decltype(gltkmath::Matrix3(1, 2, 3, 4, 5, 6, 7, 8, 9).cast<std::size_t>()),
        gltkmath::Matrix3<std::size_t>
    >();
}

TEST(Matrix3, determinant) {
    gltkmath::Matrix3 matrix{
         3, 4, -7,
         3, 3,  10,
        -1, 4, -5
    };
    EXPECT_EQ(matrix.determinant(), -250);

    gltkmath::Matrix3 matrixTwo{
        -5.5,  0.0,    7.0,
         0.5, -0.333,  6.0,
         0.0,  0.0,   13.2
    };
    EXPECT_DOUBLE_EQ(matrixTwo.determinant(), 24.1758);
}

TEST(Matrix3, transpose) {
    gltkmath::Matrix3 matrix{
        1.0f, 2.0f, 3.0f,
        4.0f, 5.0f, 6.0f,
        7.0f, 8.0f, 9.0f
    };
    gltkmath::Matrix3 transposed = matrix.transpose();
    EXPECT_FLOAT_EQ(transposed(0, 0), 1.0f);
    EXPECT_FLOAT_EQ(transposed(0, 1), 2.0f);
    EXPECT_FLOAT_EQ(transposed(0, 2), 3.0f);
    EXPECT_FLOAT_EQ(transposed(1, 0), 4.0f);
    EXPECT_FLOAT_EQ(transposed(1, 1), 5.0f);
    EXPECT_FLOAT_EQ(transposed(1, 2), 6.0f);
    EXPECT_FLOAT_EQ(transposed(2, 0), 7.0f);
    EXPECT_FLOAT_EQ(transposed(2, 1), 8.0f);
    EXPECT_FLOAT_EQ(transposed(2, 2), 9.0f);
}

TEST(Matrix3, cofactor) {
    gltkmath::Matrix3 matrix{
         3, 4, -7,
         3, 3,  10,
        -1, 4, -5
    };
    EXPECT_EQ(matrix.cofactor(0, 0), -55);
    EXPECT_EQ(matrix.cofactor(0, 1), 5);
    EXPECT_EQ(matrix.cofactor(0, 2), 15);
    EXPECT_EQ(matrix.cofactor(1, 1), -22);
    EXPECT_EQ(matrix.cofactor(1, 0), -8);
    EXPECT_EQ(matrix.cofactor(1, 2), -16);
    EXPECT_EQ(matrix.cofactor(2, 2), -3);
}
