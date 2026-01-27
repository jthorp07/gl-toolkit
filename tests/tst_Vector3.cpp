/**
 * @file tst_Vector3.cpp
 *
 * @brief Test cases for the Vector3 class
 */

#include <gtest/gtest.h>
#include "Vector3.hpp"

TEST(Vector3, DefaultConstructor) {
    gltkmath::Vector3<float> vector{};
    EXPECT_FLOAT_EQ(vector.x, 0.0f);
    EXPECT_FLOAT_EQ(vector.y, 0.0f);
    EXPECT_FLOAT_EQ(vector.z, 0.0f);
}

TEST(Vector3, XYZConstructor) {
    gltkmath::Vector3 vector{ 1.0f, 2.0f, 3.0f };
    EXPECT_FLOAT_EQ(vector.x, 1.0f);
    EXPECT_FLOAT_EQ(vector.y, 2.0f);
    EXPECT_FLOAT_EQ(vector.z, 3.0f);
}

TEST(Vector3, Operators_Addition) {
    gltkmath::Vector3 vector{ 1.0f, 2.0f, 3.0f };
    gltkmath::Vector3 result = vector + vector;
    EXPECT_FLOAT_EQ(result.x, 2.0f);
    EXPECT_FLOAT_EQ(result.y, 4.0f);
    EXPECT_FLOAT_EQ(result.z, 6.0f);
}

TEST(Vector3, Operators_Subtraction) {
    gltkmath::Vector3 vector{ 1.0f, 2.0f, 3.0f };
    gltkmath::Vector3 result = vector - vector;
    EXPECT_FLOAT_EQ(result.x, 0.0f);
    EXPECT_FLOAT_EQ(result.y, 0.0f);
    EXPECT_FLOAT_EQ(result.z, 0.0f);
}

TEST(Vector3, Operators_UnarySubtraction) {
    gltkmath::Vector3 vector{ 1.0f, 2.0f, 3.0f };
    gltkmath::Vector3 result = -vector;
    EXPECT_FLOAT_EQ(result.x, -1.0f);
    EXPECT_FLOAT_EQ(result.y, -2.0f);
    EXPECT_FLOAT_EQ(result.z, -3.0f);
}

TEST(Vector3, Operators_ScalarMultiplication) {
    gltkmath::Vector3 intVector{ 1, 2, 3 };
    gltkmath::Vector3 floatVector{ 1.0f, 2.0f, 3.0f };

    // Vector3<int> * int = int
    gltkmath::Vector3 intIntResult = intVector * 2;
    EXPECT_EQ(intIntResult.x, 2);
    EXPECT_EQ(intIntResult.y, 4);
    EXPECT_EQ(intIntResult.z, 6);

    // Vector3<int> * float = float
    gltkmath::Vector3 intFloatResult = intVector * 2.5f;
    EXPECT_FLOAT_EQ(intFloatResult.x, 2.5f);
    EXPECT_FLOAT_EQ(intFloatResult.y, 5.0f);
    EXPECT_FLOAT_EQ(intFloatResult.z, 7.5f);

    // Vector3<float> * int = float
    gltkmath::Vector3 floatIntResult = intVector * 2.5f;
    EXPECT_FLOAT_EQ(floatIntResult.x, 2.5f);
    EXPECT_FLOAT_EQ(floatIntResult.y, 5.0f);
    EXPECT_FLOAT_EQ(floatIntResult.z, 7.5f);
}

TEST(Vector3, Operators_ScalarDivision) {
    gltkmath::Vector3 intVector{ 6, 4, 2 };
    gltkmath::Vector3 floatVector{ 2.0f, 4.0f, 5.0f };

    // Vector3<int> / int
    gltkmath::Vector3 intIntResult = intVector / 2;
    EXPECT_EQ(intIntResult.x, 3);
    EXPECT_EQ(intIntResult.y, 2);
    EXPECT_EQ(intIntResult.z, 1);

    // Vector3<float> / int
    gltkmath::Vector3 floatIntResult = floatVector / 2;
    EXPECT_FLOAT_EQ(floatIntResult.x, 1.0f);
    EXPECT_FLOAT_EQ(floatIntResult.y, 2.0f);
    EXPECT_FLOAT_EQ(floatIntResult.z, 2.5f);
}

TEST(Vector3, Operators_AdditionAssignment) {
    gltkmath::Vector3 vectorOne{ 1, 2, 3 };
    gltkmath::Vector3 vectorTwo{ 3, 2, 1 };
    vectorOne += vectorTwo;
    EXPECT_EQ(vectorOne.x, 4);
    EXPECT_EQ(vectorOne.y, 4);
    EXPECT_EQ(vectorOne.z, 4);
}

TEST(Vector3, Operators_SubtractionAssignment) {
    gltkmath::Vector3 vectorOne{ 6, 6, 6 };
    gltkmath::Vector3 vectorTwo{ 3, 2, 1 };
    vectorOne -= vectorTwo;
    EXPECT_EQ(vectorOne.x, 3);
    EXPECT_EQ(vectorOne.y, 4);
    EXPECT_EQ(vectorOne.z, 5);
}

TEST(Vector3, Operators_ScalarMultiplicationAssignment) {
    gltkmath::Vector3 vector{ 1, 2, 3 };
    vector *= 2.0f;
    EXPECT_EQ(vector.x, 2);
    EXPECT_EQ(vector.y, 4);
    EXPECT_EQ(vector.z, 6);
}

TEST(Vector3, Operators_ScalarDivisionAssignment) {
    gltkmath::Vector3 vector{ 10.0f, 5.0f, 3.6f };
    vector /= 2;
    EXPECT_FLOAT_EQ(vector.x, 5.0f);
    EXPECT_FLOAT_EQ(vector.y, 2.5f);
    EXPECT_FLOAT_EQ(vector.z, 1.8f);
}

TEST(Vector3, magnitude) {
    EXPECT_DOUBLE_EQ(gltkmath::Vector3(3.0, 4.0, 0.0).magnitude(), 5.0);
    gltkmath::Vector3 vector{ 3, 4, 12 };
    EXPECT_DOUBLE_EQ(vector.magnitude(), 13.0);
}

TEST(Vector3, cast) {
    gltkmath::Vector3 intVector{ 1, 2, 3 };
    gltkmath::Vector3 doubleVector = intVector.cast<double>();
    ::testing::StaticAssertTypeEq<decltype(intVector), gltkmath::Vector3<int>>();
    ::testing::StaticAssertTypeEq<decltype(doubleVector), gltkmath::Vector3<double>>();
    ::testing::StaticAssertTypeEq<decltype(gltkmath::Vector3(1, 2, 3).cast<float>()),
                                  gltkmath::Vector3<float>>();
}

/**
 * @todo Add more cases to this
 */
TEST(Vector3, normal) {
    gltkmath::Vector3 xAxisNormal = gltkmath::Vector3(5.0, 0.0, 0.0).normal();
    EXPECT_DOUBLE_EQ(xAxisNormal.x, 1.0);
    EXPECT_DOUBLE_EQ(xAxisNormal.y, 0.0);
    EXPECT_DOUBLE_EQ(xAxisNormal.z, 0.0);
}
