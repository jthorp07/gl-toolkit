/**
 * @file Vector3.cpp
 *
 * @brief implementation file for the Vector3 class
 */

#include "Vector3.hpp"

namespace gltkmath {

Vector3 Vector3::operator+(const Vector3& other) const {
    return Vector3(x + other.x, y + other.y, z + other.z);
}

} // namespace gltkmath
