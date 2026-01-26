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
 * @brief A vector with 3 arithmetic components. Supports interoperability between compatible types
 */
template<typename T>
    requires std::is_arithmetic_v<T>
class Vector3 {
public:

    T x = 0.0;
    T y = 0.0;
    T z = 0.0;

    /**
     * @brief Default constructor - Initializes components to zero
     */
    constexpr Vector3() = default;

    /**
     * @brief Component-wise constructor - Explicitly initializes with XYZ components
     * @param x First component
     * @param y Second component
     * @param z Third component
     */
    Vector3(T x, T y, T z):
        x(x), y(y), z(z) {};

    /**
     * @brief Component-wise addition
     * @param other Vector to add
     * @return Vector whose components are the sum of this and other
     */
    template<typename U>
        requires std::is_arithmetic_v<U>
    constexpr inline Vector3<std::common_type_t<T, U>> operator+(const Vector3<U>& other) const {
        using ResultType = std::common_type_t<T, U>;
        return Vector3(
            static_cast<ResultType>(x) + static_cast<ResultType>(other.x),
            static_cast<ResultType>(y) + static_cast<ResultType>(other.y),
            static_cast<ResultType>(z) + static_cast<ResultType>(other.z)
        );
    }

    /**
     * @brief Component-wise subtraction
     * @param other Vector to add
     * @return Vector whose components are the sum of this and other
     */
    template<typename U>
        requires std::is_arithmetic_v<U>
    constexpr inline Vector3<std::common_type_t<T, U>> operator-(const Vector3<U>& other) const {
        using ResultType = std::common_type_t<T, U>;
        return Vector3(
            static_cast<ResultType>(x) - static_cast<ResultType>(other.x),
            static_cast<ResultType>(y) - static_cast<ResultType>(other.y),
            static_cast<ResultType>(z) - static_cast<ResultType>(other.z)
        );
    }

    /**
     * @brief Unary subtraction (negation)
     * @return Vector whose components are the negation of this vector's components
     */
    constexpr inline Vector3 operator-() const {
        return Vector3(-x, -y, -z);
    }

    /**
     * @brief Scalar multiplication
     * @param scalar Value to scale by
     * @return Vector whose components are scaled by scalar
     */
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

    /**
     * @brief Scalar division
     * @param divisor Value to divide by
     * @return Vector whose components are divided by divisor
     */
    template<typename U>
        requires std::is_arithmetic_v<U>
    constexpr inline Vector3<std::common_type_t<T, U>> operator/(U divisor) const {
        using ResultType = std::common_type_t<T, U>;
        return Vector3<ResultType>(
            static_cast<ResultType>(x) / static_cast<ResultType>(divisor),
            static_cast<ResultType>(y) / static_cast<ResultType>(divisor),
            static_cast<ResultType>(z) / static_cast<ResultType>(divisor)
        );
    }

    /**
     * @brief Component-wise addition assignment
     * @param other Vector to add to this
     * @return This
     */
    template<typename U>
        requires std::is_arithmetic_v<U>
    constexpr inline Vector3& operator+=(Vector3<U> other) {
        x += other.x;
        y += other.y;
        z += other.z;
        return *this;
    }
};

// Type deduction
template <typename T>
Vector3(T, T, T) -> Vector3<T>;

} // namespace gltkmath

#endif // VECTOR3_HPP
