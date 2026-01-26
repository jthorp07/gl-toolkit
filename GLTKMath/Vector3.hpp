/**
 * @file Vector3.hpp
 *
 * @brief Include file for the Vector3 class
 */

#ifndef VECTOR3_HPP
#define VECTOR3_HPP

namespace gltkmath {

class Vector3 {
public:
    double x;
    double y;
    double z;

    Vector3():
        x(0.0f), y(0.0f), z(0.0f) {};

    Vector3(double x, double y, double z):
        x(x), y(y), z(z) {};
};

} // namespace gltkmath

#endif // VECTOR3_HPP
