/**
 * @file Vector3.hpp
 *
 * @brief Include file for the Vector3 class
 */

#ifndef VECTOR3_HPP
#define VECTOR3_HPP

#include <type_traits>

namespace gltkmath {

/**
 * @brief A vector with 3 arithmetic components
 */
template<typename T>
    requires std::is_arithmetic_v<T>
class Vector3 {
public:

    T x = 0.0;
    T y = 0.0;
    T z = 0.0;

    constexpr Vector3() = default;

    Vector3(T x, T y, T z):
        x(x), y(y), z(z) {};

    constexpr inline Vector3 operator+(const Vector3& other) const {
        return Vector3(x + other.x, y + other.y, z + other.z);
    }

    constexpr inline Vector3 operator-(const Vector3& other) const {
        return Vector3(x - other.x, y - other.y, z - other.z);
    }

    constexpr inline Vector3 operator-() const {
        return Vector3(-x, -y, -z);
    }

    template<typename U>
        requires std::is_arithmetic_v<U>
    constexpr inline Vector3<std::common_type_t<T, U>> operator*(U scalar) const {
        using ResultType = std::common_type_t<T, U>;
        return Vector3<ResultType>(
            static_cast<ResultType>(x) * static_cast<ResultType>(scalar),
            static_cast<ResultType>(y) * static_cast<ResultType>(scalar),
            static_cast<ResultType>(z) * static_cast<ResultType>(scalar)
        );
    }
};

// Type deduction
template <typename T>
Vector3(T, T, T) -> Vector3<T>;

} // namespace gltkmath

#endif // VECTOR3_HPP
