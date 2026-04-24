/**
 * @file tst_Vector3.cpp
 *
 * @brief Test cases for the Vector3 class
 */

#include <gtest/gtest.h>
#include "Vector3.hpp"

TEST(Vector3_Constructors, Default) {
    gltkmath::Vector3<float> vector{};
    EXPECT_FLOAT_EQ(vector.x, 0.0f);
    EXPECT_FLOAT_EQ(vector.y, 0.0f);
    EXPECT_FLOAT_EQ(vector.z, 0.0f);
}

TEST(Vector3_Constructors, XYZ) {
    gltkmath::Vector3 vector{ 1.0f, 2.0f, 3.0f };
    EXPECT_FLOAT_EQ(vector.x, 1.0f);
    EXPECT_FLOAT_EQ(vector.y, 2.0f);
    EXPECT_FLOAT_EQ(vector.z, 3.0f);
}

TEST(Vector3_Constructors, Vector4) {
    gltkmath::Vector4 vec4{ 1, 2, 3, 4 };
    gltkmath::Vector3 vec3{ vec4 };
    EXPECT_EQ(vec3.x, 1);
    EXPECT_EQ(vec3.y, 2);
    EXPECT_EQ(vec3.z, 3);
}

TEST(Vector3_Operators, Addition) {
    gltkmath::Vector3 vector{ 1.0f, 2.0f, 3.0f };
    gltkmath::Vector3 result = vector + vector;
    EXPECT_FLOAT_EQ(result.x, 2.0f);
    EXPECT_FLOAT_EQ(result.y, 4.0f);
    EXPECT_FLOAT_EQ(result.z, 6.0f);
}

TEST(Vector3_Operators, Subtraction) {
    gltkmath::Vector3 vector{ 1.0f, 2.0f, 3.0f };
    gltkmath::Vector3 result = vector - vector;
    EXPECT_FLOAT_EQ(result.x, 0.0f);
    EXPECT_FLOAT_EQ(result.y, 0.0f);
    EXPECT_FLOAT_EQ(result.z, 0.0f);
}

TEST(Vector3_Operators, UnarySubtraction) {
    gltkmath::Vector3 vector{ 1.0f, 2.0f, 3.0f };
    gltkmath::Vector3 result = -vector;
    EXPECT_FLOAT_EQ(result.x, -1.0f);
    EXPECT_FLOAT_EQ(result.y, -2.0f);
    EXPECT_FLOAT_EQ(result.z, -3.0f);
}

TEST(Vector3_Operators, ScalarMultiplication) {
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

TEST(Vector3_Operators, ScalarDivision) {
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

TEST(Vector3_Operators, AdditionAssignment) {
    gltkmath::Vector3 vectorOne{ 1, 2, 3 };
    gltkmath::Vector3 vectorTwo{ 3, 2, 1 };
    vectorOne += vectorTwo;
    EXPECT_EQ(vectorOne.x, 4);
    EXPECT_EQ(vectorOne.y, 4);
    EXPECT_EQ(vectorOne.z, 4);
}

TEST(Vector3_Operators, SubtractionAssignment) {
    gltkmath::Vector3 vectorOne{ 6, 6, 6 };
    gltkmath::Vector3 vectorTwo{ 3, 2, 1 };
    vectorOne -= vectorTwo;
    EXPECT_EQ(vectorOne.x, 3);
    EXPECT_EQ(vectorOne.y, 4);
    EXPECT_EQ(vectorOne.z, 5);
}

TEST(Vector3_Operators, ScalarMultiplicationAssignment) {
    gltkmath::Vector3 vector{ 1, 2, 3 };
    vector *= 2.0f;
    EXPECT_EQ(vector.x, 2);
    EXPECT_EQ(vector.y, 4);
    EXPECT_EQ(vector.z, 6);
}

TEST(Vector3_Operators, ScalarDivisionAssignment) {
    gltkmath::Vector3 vector{ 10.0f, 5.0f, 3.6f };
    vector /= 2;
    EXPECT_FLOAT_EQ(vector.x, 5.0f);
    EXPECT_FLOAT_EQ(vector.y, 2.5f);
    EXPECT_FLOAT_EQ(vector.z, 1.8f);
}

TEST(Vector3, magnitude) {
    EXPECT_FLOAT_EQ(gltkmath::Vector3(3.0f, 4.0f, 0.0f).magnitude(), 5.0f);
    gltkmath::Vector3 vector{ 3.0, 4.0, 12.0 };
    EXPECT_DOUBLE_EQ(vector.magnitude(), 13.0);
}

TEST(Vector3, magnitudeSquared) {
    EXPECT_EQ(gltkmath::Vector3(1, 2, 3).magnitudeSquared(), 14);
    gltkmath::Vector3 vector{ 3.0, 5.0, 4.0 };
    EXPECT_DOUBLE_EQ(vector.magnitudeSquared(), 50.0);
}

TEST(Vector3, cast) {
    gltkmath::Vector3 intVector{ 1, 2, 3 };
    gltkmath::Vector3 doubleVector = intVector.cast<double>();
    EXPECT_DOUBLE_EQ(doubleVector.x, 1.0);
    EXPECT_DOUBLE_EQ(doubleVector.y, 2.0);
    EXPECT_DOUBLE_EQ(doubleVector.z, 3.0);
    std::ignore = doubleVector;
    ::testing::StaticAssertTypeEq<decltype(intVector), gltkmath::Vector3<int>>();
    ::testing::StaticAssertTypeEq<decltype(doubleVector), gltkmath::Vector3<double>>();
    ::testing::StaticAssertTypeEq<decltype(gltkmath::Vector3(1, 2, 3).cast<float>()),
                                  gltkmath::Vector3<float>>();
}

TEST(Vector3, normal) {
    gltkmath::Vector3 xAxisNormal = gltkmath::Vector3(5.0, 0.0, 0.0).normal();
    EXPECT_DOUBLE_EQ(xAxisNormal.x, 1.0);
    EXPECT_DOUBLE_EQ(xAxisNormal.y, 0.0);
    EXPECT_DOUBLE_EQ(xAxisNormal.z, 0.0);
    gltkmath::Vector3 xyzVector = gltkmath::Vector3(3.0, 4.0, 12.0).normal();
    EXPECT_DOUBLE_EQ(xyzVector.x, 3.0 / 13.0);
    EXPECT_DOUBLE_EQ(xyzVector.y, 4.0 / 13.0);
    EXPECT_DOUBLE_EQ(xyzVector.z, 12.0 / 13.0);
}

TEST(Vector3, dot) {
    gltkmath::Vector3 intVector{ 1, 2, 3 };
    gltkmath::Vector3 floatVector{ 1.0f, 2.0f, 3.0f };
    EXPECT_FLOAT_EQ(intVector.dot(floatVector), 14.0f);
    EXPECT_EQ(intVector.dot(intVector), 14);
    gltkmath::Vector3 doubleVector{ 2.0, 5.0, -7.0 };
    EXPECT_DOUBLE_EQ(doubleVector.dot(gltkmath::Vector3(2.0, -3.0, -1.0)), -4.0);
}

TEST(Vector3, cross) {
    gltkmath::Vector3 first{ 1.0, 2.0, 3.0 };
    gltkmath::Vector3 second{ 4.0, 5.0, 6.0 };
    gltkmath::Vector3 firstCrossSecond = first.cross(second);
    EXPECT_DOUBLE_EQ(firstCrossSecond.x, -3.0);
    EXPECT_DOUBLE_EQ(firstCrossSecond.y, 6.0);
    EXPECT_DOUBLE_EQ(firstCrossSecond.z, -3.0);

    gltkmath::Vector3 third{ 3.0f, 4.0f, -12.0f };
    gltkmath::Vector3 fourth{ 1.0f, 0.0f, -1.0f };
    gltkmath::Vector3 thirdCrossFourth = third.cross(fourth);
    EXPECT_FLOAT_EQ(thirdCrossFourth.x, -4.0f);
    EXPECT_FLOAT_EQ(thirdCrossFourth.y, -9.0f);
    EXPECT_FLOAT_EQ(thirdCrossFourth.z, -4.0f);
}
