/**
 * @file tst_Vector4.cpp
 *
 * @brief Test suite for the Vector4 class
 */

#include <gtest/gtest.h>
#include "Vector4.hpp"

TEST(Vector4, XYZWConstructor) {
    gltkmath::Vector4 vector{ 1, 2, 3, 4 };
    EXPECT_EQ(vector.x, 1);
    EXPECT_EQ(vector.y, 2);
    EXPECT_EQ(vector.z, 3);
    EXPECT_EQ(vector.w, 4);
}
