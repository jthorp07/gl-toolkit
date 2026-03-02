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

    Vector4() = default;

    Vector4(T x, T y, T z, T w):
        x(x), y(y), z(z), w(w) {};

    /**
     * @brief Component-wise addition
     * @param other Vector to add
     * @return Vector whose components are the sum of this and other
     */
    template<typename U>
        requires std::is_arithmetic_v<U>
    constexpr inline Vector4<std::common_type_t<T, U>> operator+(const Vector4<U>& other) const {
        using ResultType = std::common_type_t<T, U>;
        return Vector4(
            static_cast<ResultType>(x) + static_cast<ResultType>(other.x),
            static_cast<ResultType>(y) + static_cast<ResultType>(other.y),
            static_cast<ResultType>(z) + static_cast<ResultType>(other.z),
            static_cast<ResultType>(w) + static_cast<ResultType>(other.w)
        );
    }

    /**
     * @brief Component-wise subtraction
     * @param other Vector to add
     * @return Vector whose components are the sum of this and other
     */
    template<typename U>
        requires std::is_arithmetic_v<U>
    constexpr inline Vector4<std::common_type_t<T, U>> operator-(const Vector4<U>& other) const {
        using ResultType = std::common_type_t<T, U>;
        return Vector4(
            static_cast<ResultType>(x) - static_cast<ResultType>(other.x),
            static_cast<ResultType>(y) - static_cast<ResultType>(other.y),
            static_cast<ResultType>(z) - static_cast<ResultType>(other.z),
            static_cast<ResultType>(w) - static_cast<ResultType>(other.w)
        );
    }

    /**
     * @brief Unary subtraction (negation)
     * @return Vector whose components are the negation of this vector's components
     */
    constexpr inline Vector4 operator-() const {
        return Vector4(-x, -y, -z, -w);
    }

    /**
     * @brief Scalar multiplication
     * @param scalar Value to scale by
     * @return Vector whose components are scaled by scalar
     */
    template<typename U>
        requires std::is_arithmetic_v<U>
    constexpr inline Vector4<std::common_type_t<T, U>> operator*(U scalar) const {
        using ResultType = std::common_type_t<T, U>;
        return Vector4<ResultType>(
            static_cast<ResultType>(x) * static_cast<ResultType>(scalar),
            static_cast<ResultType>(y) * static_cast<ResultType>(scalar),
            static_cast<ResultType>(z) * static_cast<ResultType>(scalar),
            static_cast<ResultType>(w) * static_cast<ResultType>(scalar)
        );
    }

    /**
     * @brief Scalar division
     * @param divisor Value to divide by
     * @return Vector whose components are divided by divisor
     */
    template<typename U>
        requires std::is_arithmetic_v<U>
    constexpr inline Vector4<std::common_type_t<T, U>> operator/(U divisor) const {
        using ResultType = std::common_type_t<T, U>;
        return Vector4<ResultType>(
            static_cast<ResultType>(x) / static_cast<ResultType>(divisor),
            static_cast<ResultType>(y) / static_cast<ResultType>(divisor),
            static_cast<ResultType>(z) / static_cast<ResultType>(divisor),
            static_cast<ResultType>(w) / static_cast<ResultType>(divisor)
        );
    }

    /**
     * @brief Component-wise addition assignment
     * @param other Vector to add to this
     * @return This
     */
    template<typename U>
        requires std::is_arithmetic_v<U>
    constexpr inline Vector4& operator+=(const Vector4<U>& other) {
        x += other.x;
        y += other.y;
        z += other.z;
        w += other.w;
        return *this;
    }

    /**
     * @brief Component-wise subtraction assignment
     * @param other Vector to subtract from this
     * @return This
     */
    template<typename U>
        requires std::is_arithmetic_v<U>
    constexpr inline Vector4& operator-=(const Vector4<U>& other) {
        x -= other.x;
        y -= other.y;
        z -= other.z;
        w -= other.w;
        return *this;
    }

    /**
     * @brief Scalar multiplication assignment
     * @param scalar Value to scale by
     * @return This
     */
    template<typename U>
        requires std::is_arithmetic_v<U>
    constexpr inline Vector4& operator*=(U scalar) {
        x *= scalar;
        y *= scalar;
        z *= scalar;
        w *= scalar;
        return *this;
    }
};

// Type deduction
template<typename T>
Vector4(T, T, T, T) -> Vector4<T>;

} // namespace gltkmath

#endif // VECTOR4_HPP
