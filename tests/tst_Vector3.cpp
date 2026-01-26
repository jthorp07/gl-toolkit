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
