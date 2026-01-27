/**
 * @file Vector3.hpp
 *
 * @brief Include file for the Vector3 class
 */

#ifndef VECTOR3_HPP
#define VECTOR3_HPP

#include <cmath>
#include <cstdint>
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
    constexpr inline Vector3& operator+=(const Vector3<U>& other) {
        x += other.x;
        y += other.y;
        z += other.z;
        return *this;
    }

    /**
     * @brief Component-wise subtraction assignment
     * @param other Vector to subtract from this
     * @return This
     */
    template<typename U>
        requires std::is_arithmetic_v<U>
    constexpr inline Vector3& operator-=(const Vector3<U>& other) {
        x -= other.x;
        y -= other.y;
        z -= other.z;
        return *this;
    }

    /**
     * @brief Scalar multiplication assignment
     * @param scalar Value to scale by
     * @return This
     */
    template<typename U>
        requires std::is_arithmetic_v<U>
    constexpr inline Vector3& operator*=(U scalar) {
        x *= scalar;
        y *= scalar;
        z *= scalar;
        return *this;
    }

    /**
     * @brief Scalar division assignment
     * @param divisor Value to divide by
     * @return This
     */
    template<typename U>
        requires std::is_arithmetic_v<U>
    constexpr inline Vector3& operator/=(U divisor) {
        x /= divisor;
        y /= divisor;
        z /= divisor;
        return *this;
    }

    /**
     * @brief The scalar magnitude of the vector using 3D Euclidean distance
     *
     * @warning Only usable with floating point vectors
     *
     * @return Magnitude of the vector
     */
    [[nodiscard]] constexpr inline double magnitude() const requires std::floating_point<T> {
        return std::sqrt(
            std::pow(x, 2.0) +
            std::pow(y, 2.0) +
            std::pow(z, 2.0)
        );
    }

    /**
     * @brief Copies this vector's components to a new vector casted to
     *        NewType
     * @return Copied casted vector
     */
    template<typename NewType>
        requires std::is_arithmetic_v<NewType>
    [[nodiscard]] constexpr inline Vector3<NewType> cast() const {
        return Vector3<NewType>(
            static_cast<NewType>(x),
            static_cast<NewType>(y),
            static_cast<NewType>(z)
        );
    }

    /**
     * @brief Makes a vector with magnitude 1 facing the same direction as
     *        this vector
     * @return Normal vector
     */
    [[nodiscard]] constexpr inline Vector3 normal() const requires std::floating_point<T> {
        const auto _magnitude = magnitude();
        return Vector3(
            x / _magnitude,
            y / _magnitude,
            z / _magnitude
        );
    }
};

// Type deduction
template <typename T>
Vector3(T, T, T) -> Vector3<T>;

} // namespace gltkmath

#endif // VECTOR3_HPP
