/**
 * @file tst_Vector4.cpp
 *
 * @brief Test suite for the Vector4 class
 */

#include <gtest/gtest.h>
#include "Vector4.hpp"

TEST(Vector4_Constructors, Default) {
    gltkmath::Vector4<int> vector{};
    EXPECT_EQ(vector.x, 0);
    EXPECT_EQ(vector.y, 0);
    EXPECT_EQ(vector.z, 0);
    EXPECT_EQ(vector.w, 0);
}

TEST(Vector4_Constructors, XYZW) {
    gltkmath::Vector4 vector{ 1, 2, 3, 4 };
    EXPECT_EQ(vector.x, 1);
    EXPECT_EQ(vector.y, 2);
    EXPECT_EQ(vector.z, 3);
    EXPECT_EQ(vector.w, 4);
}

TEST(Vector4_Operators, Addition) {
    gltkmath::Vector4 vector{ 1.0f, 2.0f, 3.0f, 4.0f };
    gltkmath::Vector4 result = vector + vector;
    EXPECT_FLOAT_EQ(result.x, 2.0f);
    EXPECT_FLOAT_EQ(result.y, 4.0f);
    EXPECT_FLOAT_EQ(result.z, 6.0f);
    EXPECT_FLOAT_EQ(result.w, 8.0f);
}

TEST(Vector4_Operators, Subtraction) {
    gltkmath::Vector4 vector{ 1.0f, 2.0f, 3.0f, 4.0f };
    gltkmath::Vector4 vectorTwo{ 4.0f, 3.0f, 2.0f, 1.0f };
    gltkmath::Vector4 result = vector - vectorTwo;
    EXPECT_FLOAT_EQ(result.x, -3.0f);
    EXPECT_FLOAT_EQ(result.y, -1.0f);
    EXPECT_FLOAT_EQ(result.z, 1.0f);
    EXPECT_FLOAT_EQ(result.w, 3.0f);
}

TEST(Vector4_Operators, UnarySubtraction) {
    gltkmath::Vector4 vector{ 1, -2, -3, 4 };
    gltkmath::Vector4 negatedVector = -vector;
    EXPECT_EQ(negatedVector.x, -1);
    EXPECT_EQ(negatedVector.y, 2);
    EXPECT_EQ(negatedVector.z, 3);
    EXPECT_EQ(negatedVector.w, -4);
}

TEST(Vector4_Operators, ScalarMultiplication) {
    gltkmath::Vector4 intVector{ 1, 2, 3, 4 };
    gltkmath::Vector4 floatVector{ 1.0f, 2.0f, 3.0f, 4.0f };

    // Vector4<int> * int = int
    gltkmath::Vector4 intIntResult = intVector * 2;
    EXPECT_EQ(intIntResult.x, 2);
    EXPECT_EQ(intIntResult.y, 4);
    EXPECT_EQ(intIntResult.z, 6);
    EXPECT_EQ(intIntResult.w, 8);

    // Vector4<int> * float = float
    gltkmath::Vector4 intFloatResult = intVector * 2.5f;
    EXPECT_FLOAT_EQ(intFloatResult.x, 2.5f);
    EXPECT_FLOAT_EQ(intFloatResult.y, 5.0f);
    EXPECT_FLOAT_EQ(intFloatResult.z, 7.5f);
    EXPECT_FLOAT_EQ(intFloatResult.w, 10.0f);

    // Vector4<float> * int = float
    gltkmath::Vector4 floatIntResult = intVector * 2.5f;
    EXPECT_FLOAT_EQ(floatIntResult.x, 2.5f);
    EXPECT_FLOAT_EQ(floatIntResult.y, 5.0f);
    EXPECT_FLOAT_EQ(floatIntResult.z, 7.5f);
    EXPECT_FLOAT_EQ(floatIntResult.w, 10.0f);
}

TEST(Vector4_Operators, ScalarDivision) {
    gltkmath::Vector4 intVector{ 6, 4, 2, 4 };
    gltkmath::Vector4 floatVector{ 2.0f, 4.0f, 5.0f, 4.0f };

    // Vector4<int> / int
    gltkmath::Vector4 intIntResult = intVector / 2;
    EXPECT_EQ(intIntResult.x, 3);
    EXPECT_EQ(intIntResult.y, 2);
    EXPECT_EQ(intIntResult.z, 1);
    EXPECT_EQ(intIntResult.w, 2);

    // Vector4<float> / int
    gltkmath::Vector4 floatIntResult = floatVector / 2;
    EXPECT_FLOAT_EQ(floatIntResult.x, 1.0f);
    EXPECT_FLOAT_EQ(floatIntResult.y, 2.0f);
    EXPECT_FLOAT_EQ(floatIntResult.z, 2.5f);
    EXPECT_FLOAT_EQ(floatIntResult.w, 2.0f);
}

TEST(Vector4_Operators, AdditionAssignment) {
    gltkmath::Vector4 vectorOne{ 1, 2, 3, 4 };
    gltkmath::Vector4 vectorTwo{ 3, 2, 1, 0 };
    vectorOne += vectorTwo;
    EXPECT_EQ(vectorOne.x, 4);
    EXPECT_EQ(vectorOne.y, 4);
    EXPECT_EQ(vectorOne.z, 4);
    EXPECT_EQ(vectorOne.w, 4);
}

TEST(Vector4_Operators, SubtractionAssignment) {
    gltkmath::Vector4 vectorOne{ 6, 6, 6, 6 };
    gltkmath::Vector4 vectorTwo{ 3, 2, 1, -1 };
    vectorOne -= vectorTwo;
    EXPECT_EQ(vectorOne.x, 3);
    EXPECT_EQ(vectorOne.y, 4);
    EXPECT_EQ(vectorOne.z, 5);
    EXPECT_EQ(vectorOne.w, 7);
}

TEST(Vector4_Operators, ScalarMultiplicationAssignment) {
    gltkmath::Vector4 vector{ 1, 2, 3, 4 };
    vector *= 2.0f;
    EXPECT_EQ(vector.x, 2);
    EXPECT_EQ(vector.y, 4);
    EXPECT_EQ(vector.z, 6);
    EXPECT_EQ(vector.w, 8);
}

TEST(Vector4_Operators, ScalarDivisionAssignment) {
    gltkmath::Vector4 vector{ 10.0f, 5.0f, 3.6f, 7.0f };
    vector /= 2;
    EXPECT_FLOAT_EQ(vector.x, 5.0f);
    EXPECT_FLOAT_EQ(vector.y, 2.5f);
    EXPECT_FLOAT_EQ(vector.z, 1.8f);
    EXPECT_FLOAT_EQ(vector.w, 3.5f);
}

TEST(Vector4, magnitude) {
    EXPECT_FLOAT_EQ(gltkmath::Vector4(3.0f, 0.0f, -4.0f, 0.0f).magnitude(), 5.0f);
    EXPECT_FLOAT_EQ(gltkmath::Vector4(0.0f, 0.0f, 10.0f, 0.0f).magnitude(), 10.0f);
    gltkmath::Vector4 vector{ 0.0, 3.0, 4.0, 12.0 };
    EXPECT_DOUBLE_EQ(vector.magnitude(), 13.0);
}
