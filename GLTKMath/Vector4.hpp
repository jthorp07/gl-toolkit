/**
 * @file Vector4.hpp
 *
 * @brief Include file for the Vector4 class
 */

#ifndef VECTOR4_HPP
#define VECTOR4_HPP

#include <type_traits>

namespace gltkmath {

/**
 * @brief A vector with 4 arithmetic components
 */
template<typename T>
    requires std::is_arithmetic_v<T>
class Vector4 {
public:

    T x = 0.0;
    T y = 0.0;
    T z = 0.0;
    T w = 0.0;

    Vector4(T x, T y, T z, T w):
        x(x), y(y), z(z), w(w) {};
};

// Type deduction
template<typename T>
Vector4(T, T, T, T) -> Vector4<T>;

} // namespace gltkmath

#endif // VECTOR4_HPP
