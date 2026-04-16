/**
 * @file Matrix3.hpp
 *
 * @brief Include file for the Matrix3 class
 */

#ifndef MATRIX3_HPP
#define MATRIX3_HPP

#include "Vector3.hpp"
#include "mathdefs.hpp"

#include <cmath>
#include <type_traits>

namespace gltkmath {

template<typename T>
    requires std::is_arithmetic_v<T>
class Matrix3 {
public:

    T c0r0; T c0r1; T c0r2;
    T c1r0; T c1r1; T c1r2;
    T c2r0; T c2r1; T c2r2;

    /**
     * @brief Default constructor - Initializes all components to zero
     */
    constexpr Matrix3() = default;

    /**
     * @brief Component-wise constructor - Explicitly initializes with 9
     *        components
     * 
     * @param c0r0 First column, first row component
     * @param c0r1 First column, second row component
     * @param c0r2 First column, third row component
     * @param c1r0 Second column, first row component
     * @param c1r1 Second column, second row component
     * @param c1r2 Second column, third row component
     * @param c2r0 Third column, first row component
     * @param c2r1 Third column, second row component
     * @param c2r2 Third column, third row component
     */
    constexpr Matrix3(
        T c0r0, T c1r0, T c2r0,
        T c0r1, T c1r1, T c2r1,
        T c0r2, T c1r2, T c2r2
    ) : c0r0(c0r0), c0r1(c0r1), c0r2(c0r2),
        c1r0(c1r0), c1r1(c1r1), c1r2(c1r2),
        c2r0(c2r0), c2r1(c2r1), c2r2(c2r2) {};

    /**
     * @brief Component-wise addition
     * 
     * @param other Matrix to add
     * 
     * @return Matrix whose components are the sum of this and other
     */
    template<typename U>
        requires std::is_arithmetic_v<U>
    constexpr inline Matrix3<std::common_type_t<T, U>> operator+(const Matrix3<U>& other) const {
        using ResultType = std::common_type_t<T, U>;
        return Matrix3{
            static_cast<ResultType>(c0r0) + static_cast<ResultType>(other.c0r0),
            static_cast<ResultType>(c0r1) + static_cast<ResultType>(other.c0r1),
            static_cast<ResultType>(c0r2) + static_cast<ResultType>(other.c0r2),
            static_cast<ResultType>(c1r0) + static_cast<ResultType>(other.c1r0),
            static_cast<ResultType>(c1r1) + static_cast<ResultType>(other.c1r1),
            static_cast<ResultType>(c1r2) + static_cast<ResultType>(other.c1r2),
            static_cast<ResultType>(c2r0) + static_cast<ResultType>(other.c2r0),
            static_cast<ResultType>(c2r1) + static_cast<ResultType>(other.c2r1),
            static_cast<ResultType>(c2r2) + static_cast<ResultType>(other.c2r2)
        };
    }

    /**
     * @brief Component-wise subtraction
     * 
     * @param other Matrix to subtract
     * 
     * @return Matrix whose components are the difference of this and other
     */
    template<typename U>
        requires std::is_arithmetic_v<U>
    constexpr inline Matrix3<std::common_type_t<T, U>> operator-(const Matrix3<U>& other) const {
        using ResultType = std::common_type_t<T, U>;
        return Matrix3{
            static_cast<ResultType>(c0r0) - static_cast<ResultType>(other.c0r0),
            static_cast<ResultType>(c0r1) - static_cast<ResultType>(other.c0r1),
            static_cast<ResultType>(c0r2) - static_cast<ResultType>(other.c0r2),
            static_cast<ResultType>(c1r0) - static_cast<ResultType>(other.c1r0),
            static_cast<ResultType>(c1r1) - static_cast<ResultType>(other.c1r1),
            static_cast<ResultType>(c1r2) - static_cast<ResultType>(other.c1r2),
            static_cast<ResultType>(c2r0) - static_cast<ResultType>(other.c2r0),
            static_cast<ResultType>(c2r1) - static_cast<ResultType>(other.c2r1),
            static_cast<ResultType>(c2r2) - static_cast<ResultType>(other.c2r2)
        };
    }

    /**
     * @brief Unary subtraction (negation)
     * 
     * @return Matrix whose components are the negation of this
     */
    constexpr inline Matrix3 operator-() const requires std::is_signed_v<T> {
        return Matrix3{
            -c0r0, -c0r1, -c0r2,
            -c1r0, -c1r1, -c1r2,
            -c2r0, -c2r1, -c2r2
        };
    }

    /**
     * @brief Scalar multiplication
     * 
     * @param scalar Value to scale by
     * 
     * @return Matrix whose components are scaled by scalar
     */
    template<typename U>
        requires std::is_arithmetic_v<U>
    constexpr inline Matrix3<std::common_type_t<T, U>> operator*(U scalar) const {
        using ResultType = std::common_type_t<T, U>;
        return Matrix3{
            static_cast<ResultType>(c0r0) * static_cast<ResultType>(scalar),
            static_cast<ResultType>(c0r1) * static_cast<ResultType>(scalar),
            static_cast<ResultType>(c0r2) * static_cast<ResultType>(scalar),
            static_cast<ResultType>(c1r0) * static_cast<ResultType>(scalar),
            static_cast<ResultType>(c1r1) * static_cast<ResultType>(scalar),
            static_cast<ResultType>(c1r2) * static_cast<ResultType>(scalar),
            static_cast<ResultType>(c2r0) * static_cast<ResultType>(scalar),
            static_cast<ResultType>(c2r1) * static_cast<ResultType>(scalar),
            static_cast<ResultType>(c2r2) * static_cast<ResultType>(scalar)
        };
    }

    /**
     * @brief Matrix-scalar multiplication with scalar on the left
     * 
     * @param scalar Value to scale by
     * @param matrix Matrix to scale
     * 
     * @return Matrix whose components are scaled by scalar
     */
    template<typename U>
        requires std::is_arithmetic_v<U>
    friend constexpr inline Matrix3<std::common_type_t<T, U>> operator*(U scalar, const Matrix3<T>& matrix) {
        using ResultType = std::common_type_t<T, U>;
        return Matrix3{
            static_cast<ResultType>(matrix.c0r0) * static_cast<ResultType>(scalar),
            static_cast<ResultType>(matrix.c0r1) * static_cast<ResultType>(scalar),
            static_cast<ResultType>(matrix.c0r2) * static_cast<ResultType>(scalar),
            static_cast<ResultType>(matrix.c1r0) * static_cast<ResultType>(scalar),
            static_cast<ResultType>(matrix.c1r1) * static_cast<ResultType>(scalar),
            static_cast<ResultType>(matrix.c1r2) * static_cast<ResultType>(scalar),
            static_cast<ResultType>(matrix.c2r0) * static_cast<ResultType>(scalar),
            static_cast<ResultType>(matrix.c2r1) * static_cast<ResultType>(scalar),
            static_cast<ResultType>(matrix.c2r2) * static_cast<ResultType>(scalar)
        };
    }

    /**
     * @brief Matrix-vector multiplication
     * 
     * @param vector Vector to multiply by
     * 
     * @return Vector resulting from the multiplication
     */
    template<typename U>
        requires std::is_arithmetic_v<U>
    constexpr inline Vector3<std::common_type_t<T, U>> operator*(Vector3<U> vector) const {
        using ResultType = std::common_type_t<T, U>;
        return Vector3<ResultType>(
            (static_cast<ResultType>(c0r0) * static_cast<ResultType>(vector.x)) +
            (static_cast<ResultType>(c1r0) * static_cast<ResultType>(vector.y)) +
            (static_cast<ResultType>(c2r0) * static_cast<ResultType>(vector.z)),

            (static_cast<ResultType>(c0r1) * static_cast<ResultType>(vector.x)) +
            (static_cast<ResultType>(c1r1) * static_cast<ResultType>(vector.y)) +
            (static_cast<ResultType>(c2r1) * static_cast<ResultType>(vector.z)),

            (static_cast<ResultType>(c0r2) * static_cast<ResultType>(vector.x)) +
            (static_cast<ResultType>(c1r2) * static_cast<ResultType>(vector.y)) +
            (static_cast<ResultType>(c2r2) * static_cast<ResultType>(vector.z))
        );
    }

    /**
     * @brief Matrix multiplication
     * 
     * @param other Matrix to multiply by
     * 
     * @return Matrix resulting from the multiplication
     */
    template<typename U>
        requires std::is_arithmetic_v<U>
    constexpr inline Matrix3<std::common_type_t<T, U>> operator*(const Matrix3<U>& other) const {
        using ResultType = std::common_type_t<T, U>;
        return Matrix3{
            static_cast<ResultType>(c0r0) * static_cast<ResultType>(other.c0r0) +
            static_cast<ResultType>(c1r0) * static_cast<ResultType>(other.c0r1) +
            static_cast<ResultType>(c2r0) * static_cast<ResultType>(other.c0r2),

            static_cast<ResultType>(c0r0) * static_cast<ResultType>(other.c1r0) +
            static_cast<ResultType>(c1r0) * static_cast<ResultType>(other.c1r1) +
            static_cast<ResultType>(c2r0) * static_cast<ResultType>(other.c1r2),

            static_cast<ResultType>(c0r0) * static_cast<ResultType>(other.c2r0) +
            static_cast<ResultType>(c1r0) * static_cast<ResultType>(other.c2r1) +
            static_cast<ResultType>(c2r0) * static_cast<ResultType>(other.c2r2),

            static_cast<ResultType>(c0r1) * static_cast<ResultType>(other.c0r0) +
            static_cast<ResultType>(c1r1) * static_cast<ResultType>(other.c0r1) +
            static_cast<ResultType>(c2r1) * static_cast<ResultType>(other.c0r2),

            static_cast<ResultType>(c0r1) * static_cast<ResultType>(other.c1r0) +
            static_cast<ResultType>(c1r1) * static_cast<ResultType>(other.c1r1) +
            static_cast<ResultType>(c2r1) * static_cast<ResultType>(other.c1r2),

            static_cast<ResultType>(c0r1) * static_cast<ResultType>(other.c2r0) +
            static_cast<ResultType>(c1r1) * static_cast<ResultType>(other.c2r1) +
            static_cast<ResultType>(c2r1) * static_cast<ResultType>(other.c2r2),

            static_cast<ResultType>(c0r2) * static_cast<ResultType>(other.c0r0) +
            static_cast<ResultType>(c1r2) * static_cast<ResultType>(other.c0r1) +
            static_cast<ResultType>(c2r2) * static_cast<ResultType>(other.c0r2),

            static_cast<ResultType>(c0r2) * static_cast<ResultType>(other.c1r0) +
            static_cast<ResultType>(c1r2) * static_cast<ResultType>(other.c1r1) +
            static_cast<ResultType>(c2r2) * static_cast<ResultType>(other.c1r2),

            static_cast<ResultType>(c0r2) * static_cast<ResultType>(other.c2r0) +
            static_cast<ResultType>(c1r2) * static_cast<ResultType>(other.c2r1) +
            static_cast<ResultType>(c2r2) * static_cast<ResultType>(other.c2r2)
        };
    }

    /**
     * @brief Component-wise addition assignment
     * 
     * @param other Matrix to add to this
     * 
     * @return This
     */
    template<typename U>
        requires (std::is_arithmetic_v<U> && lossless_convertible_to<U, T>)
    constexpr inline Matrix3& operator+=(const Matrix3<U>& other) {
        c0r0 += static_cast<T>(other.c0r0);
        c0r1 += static_cast<T>(other.c0r1);
        c0r2 += static_cast<T>(other.c0r2);
        c1r0 += static_cast<T>(other.c1r0);
        c1r1 += static_cast<T>(other.c1r1);
        c1r2 += static_cast<T>(other.c1r2);
        c2r0 += static_cast<T>(other.c2r0);
        c2r1 += static_cast<T>(other.c2r1);
        c2r2 += static_cast<T>(other.c2r2);

        return *this;
    }

    /**
     * @brief Component-wise subtraction assignment
     * 
     * @param other Matrix to subtract from this
     * 
     * @return This
     */
    template<typename U>
        requires (std::is_arithmetic_v<U> && lossless_convertible_to<U, T>)
    constexpr inline Matrix3& operator-=(const Matrix3<U>& other) {
        c0r0 -= static_cast<T>(other.c0r0);
        c0r1 -= static_cast<T>(other.c0r1);
        c0r2 -= static_cast<T>(other.c0r2);
        c1r0 -= static_cast<T>(other.c1r0);
        c1r1 -= static_cast<T>(other.c1r1);
        c1r2 -= static_cast<T>(other.c1r2);
        c2r0 -= static_cast<T>(other.c2r0);
        c2r1 -= static_cast<T>(other.c2r1);
        c2r2 -= static_cast<T>(other.c2r2);

        return *this;
    }

    /**
     * @brief Scalar multiplication assignment
     * 
     * @param scalar Value to scale by
     * 
     * @return This
     */
    template<typename U>
        requires (std::is_arithmetic_v<U> && lossless_convertible_to<U, T>)
    constexpr inline Matrix3& operator*=(const U& scalar) {
        c0r0 *= static_cast<T>(scalar);
        c0r1 *= static_cast<T>(scalar);
        c0r2 *= static_cast<T>(scalar);
        c1r0 *= static_cast<T>(scalar);
        c1r1 *= static_cast<T>(scalar);
        c1r2 *= static_cast<T>(scalar);
        c2r0 *= static_cast<T>(scalar);
        c2r1 *= static_cast<T>(scalar);
        c2r2 *= static_cast<T>(scalar);

        return *this;
    }

    /**
     * @brief Matrix multiplication assignment
     * 
     * @param other Matrix to multiply by
     * 
     * @return This
     */
    template<typename U>
        requires (std::is_arithmetic_v<U> && lossless_convertible_to<U, T>)
    constexpr inline Matrix3& operator*=(const Matrix3<U>& other) {
        *this = *this * other;

        return *this;
    }

    /**
     * @brief Copies this matrix's components to a new matrix casted to NewType
     * 
     * @return Copied casted matrix
     */
    template<typename NewType>
        requires std::is_arithmetic_v<NewType>
    [[nodiscard]] constexpr inline Matrix3<NewType> cast() const {
        return Matrix3<NewType>{
            static_cast<NewType>(c0r0), static_cast<NewType>(c1r0), static_cast<NewType>(c2r0),
            static_cast<NewType>(c0r1), static_cast<NewType>(c1r1), static_cast<NewType>(c2r1),
            static_cast<NewType>(c0r2), static_cast<NewType>(c1r2), static_cast<NewType>(c2r2)
        };
    }
};

// Type deduction
template <typename T>
Matrix3(
    T, T, T,
    T, T, T,
    T, T, T
) -> Matrix3<T>;

} // namespace gltkmath

#endif // MATRIX3_HPP
