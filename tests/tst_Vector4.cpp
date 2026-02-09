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
