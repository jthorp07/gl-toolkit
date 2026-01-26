/**
 * @file tst_Vector3.cpp
 *
 * @brief Test cases for the Vector3 class
 */

#include <gtest/gtest.h>
#include "Vector3.hpp"

TEST(Vector3, DefaultConstructor) {
    gltkmath::Vector3 vector{};
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

TEST(Vector3, Operators_UnaryAddition) {
    gltkmath::Vector3 vector{ 1.0f, 2.0f, 3.0f };
    gltkmath::Vector3 result = vector + vector;
    EXPECT_FLOAT_EQ(result.x, 2.0f);
    EXPECT_FLOAT_EQ(result.y, 4.0f);
    EXPECT_FLOAT_EQ(result.z, 6.0f);
}
