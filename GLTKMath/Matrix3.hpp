/**
 * @file Matrix3.hpp
 *
 * @brief Include file for the Matrix3 class
 */

#ifndef MATRIX3_HPP
#define MATRIX3_HPP

#include "Vector3.hpp"
#include "mathdefs.hpp"
#include "errordefs.hpp"

#include <array>
#include <cmath>
#include <stdexcept>
#include <type_traits>

namespace gltkmath {

template<typename T>
    requires std::is_arithmetic_v<T>
class Matrix3 {
private:
    std::array<T, 9> data;
public:

    /**
     * @brief Default constructor - Initializes all components to zero
     */
    constexpr Matrix3() : data{} {};

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
    ) : data({c0r0, c0r1, c0r2, c1r0, c1r1, c1r2, c2r0, c2r1, c2r2}) {}

    /**
     * @brief Explicit array constructor - Initializes with an array of
     *        9 components in column-major order
     * 
     * @param components Array of 9 components in column-major order
     */
    constexpr explicit Matrix3(const std::array<T, 9>& components) : data(components) {}

    /**
     * @brief Explicit array constructor - Initializes with an array of
     *        9 components in column-major order by move
     * 
     * @param components Array of 9 components in column-major order
     */
    constexpr explicit Matrix3(std::array<T, 9>&& components) : data(std::move(components)) {}

    /**
     * @brief Accessor for the component at the specified column and row
     * 
     * @param column Column index
     * @param row Row index
     * 
     * @return Reference to the component at the specified location
     */
    constexpr inline T& operator()(std::size_t column, std::size_t row) noexcept {
        if (column >= 3 || row >= 3) [[unlikely]] {
            gltkmath::Error::Fatal("Matrix3 indices out of bounds");
        }
        return data[column * 3 + row];
    }

    /**
     * @brief Read-only accessor for the component at the specified column and row
     * 
     * @param column Column index
     * @param row Row index
     * 
     * @return Reference to the component at the specified location
     */
    constexpr inline const T& operator()(std::size_t column, std::size_t row) const noexcept {
        if (column >= 3 || row >= 3) [[unlikely]] {
            gltkmath::Error::Fatal("Matrix3 indices out of bounds");
        }
        return data[column * 3 + row];
    }

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
            static_cast<ResultType>(data[0]) + static_cast<ResultType>(other.data[0]),
            static_cast<ResultType>(data[1]) + static_cast<ResultType>(other.data[1]),
            static_cast<ResultType>(data[2]) + static_cast<ResultType>(other.data[2]),
            static_cast<ResultType>(data[3]) + static_cast<ResultType>(other.data[3]),
            static_cast<ResultType>(data[4]) + static_cast<ResultType>(other.data[4]),
            static_cast<ResultType>(data[5]) + static_cast<ResultType>(other.data[5]),
            static_cast<ResultType>(data[6]) + static_cast<ResultType>(other.data[6]),
            static_cast<ResultType>(data[7]) + static_cast<ResultType>(other.data[7]),
            static_cast<ResultType>(data[8]) + static_cast<ResultType>(other.data[8])
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
            static_cast<ResultType>(data[0]) - static_cast<ResultType>(other.data[0]),
            static_cast<ResultType>(data[1]) - static_cast<ResultType>(other.data[1]),
            static_cast<ResultType>(data[2]) - static_cast<ResultType>(other.data[2]),
            static_cast<ResultType>(data[3]) - static_cast<ResultType>(other.data[3]),
            static_cast<ResultType>(data[4]) - static_cast<ResultType>(other.data[4]),
            static_cast<ResultType>(data[5]) - static_cast<ResultType>(other.data[5]),
            static_cast<ResultType>(data[6]) - static_cast<ResultType>(other.data[6]),
            static_cast<ResultType>(data[7]) - static_cast<ResultType>(other.data[7]),
            static_cast<ResultType>(data[8]) - static_cast<ResultType>(other.data[8])
        };
    }

    /**
     * @brief Unary subtraction (negation)
     * 
     * @return Matrix whose components are the negation of this
     */
    constexpr inline Matrix3 operator-() const requires std::is_signed_v<T> {
        return Matrix3{
            -data[0], -data[1], -data[2],
            -data[3], -data[4], -data[5],
            -data[6], -data[7], -data[8]
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
            static_cast<ResultType>(data[0]) * static_cast<ResultType>(scalar),
            static_cast<ResultType>(data[1]) * static_cast<ResultType>(scalar),
            static_cast<ResultType>(data[2]) * static_cast<ResultType>(scalar),
            static_cast<ResultType>(data[3]) * static_cast<ResultType>(scalar),
            static_cast<ResultType>(data[4]) * static_cast<ResultType>(scalar),
            static_cast<ResultType>(data[5]) * static_cast<ResultType>(scalar),
            static_cast<ResultType>(data[6]) * static_cast<ResultType>(scalar),
            static_cast<ResultType>(data[7]) * static_cast<ResultType>(scalar),
            static_cast<ResultType>(data[8]) * static_cast<ResultType>(scalar)
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
            static_cast<ResultType>(matrix.data[0]) * static_cast<ResultType>(scalar),
            static_cast<ResultType>(matrix.data[1]) * static_cast<ResultType>(scalar),
            static_cast<ResultType>(matrix.data[2]) * static_cast<ResultType>(scalar),
            static_cast<ResultType>(matrix.data[3]) * static_cast<ResultType>(scalar),
            static_cast<ResultType>(matrix.data[4]) * static_cast<ResultType>(scalar),
            static_cast<ResultType>(matrix.data[5]) * static_cast<ResultType>(scalar),
            static_cast<ResultType>(matrix.data[6]) * static_cast<ResultType>(scalar),
            static_cast<ResultType>(matrix.data[7]) * static_cast<ResultType>(scalar),
            static_cast<ResultType>(matrix.data[8]) * static_cast<ResultType>(scalar)
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
            (static_cast<ResultType>(data[0]) * static_cast<ResultType>(vector.x)) +
            (static_cast<ResultType>(data[3]) * static_cast<ResultType>(vector.y)) +
            (static_cast<ResultType>(data[6]) * static_cast<ResultType>(vector.z)),

            (static_cast<ResultType>(data[1]) * static_cast<ResultType>(vector.x)) +
            (static_cast<ResultType>(data[4]) * static_cast<ResultType>(vector.y)) +
            (static_cast<ResultType>(data[7]) * static_cast<ResultType>(vector.z)),

            (static_cast<ResultType>(data[2]) * static_cast<ResultType>(vector.x)) +
            (static_cast<ResultType>(data[5]) * static_cast<ResultType>(vector.y)) +
            (static_cast<ResultType>(data[8]) * static_cast<ResultType>(vector.z))
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
            static_cast<ResultType>(data[0]) * static_cast<ResultType>(other.data[0]) +
            static_cast<ResultType>(data[3]) * static_cast<ResultType>(other.data[1]) +
            static_cast<ResultType>(data[6]) * static_cast<ResultType>(other.data[2]),

            static_cast<ResultType>(data[0]) * static_cast<ResultType>(other.data[3]) +
            static_cast<ResultType>(data[3]) * static_cast<ResultType>(other.data[4]) +
            static_cast<ResultType>(data[6]) * static_cast<ResultType>(other.data[5]),

            static_cast<ResultType>(data[0]) * static_cast<ResultType>(other.data[6]) +
            static_cast<ResultType>(data[3]) * static_cast<ResultType>(other.data[7]) +
            static_cast<ResultType>(data[6]) * static_cast<ResultType>(other.data[8]),

            static_cast<ResultType>(data[1]) * static_cast<ResultType>(other.data[0]) +
            static_cast<ResultType>(data[4]) * static_cast<ResultType>(other.data[1]) +
            static_cast<ResultType>(data[7]) * static_cast<ResultType>(other.data[2]),

            static_cast<ResultType>(data[1]) * static_cast<ResultType>(other.data[3]) +
            static_cast<ResultType>(data[4]) * static_cast<ResultType>(other.data[4]) +
            static_cast<ResultType>(data[7]) * static_cast<ResultType>(other.data[5]),

            static_cast<ResultType>(data[1]) * static_cast<ResultType>(other.data[6]) +
            static_cast<ResultType>(data[4]) * static_cast<ResultType>(other.data[7]) +
            static_cast<ResultType>(data[7]) * static_cast<ResultType>(other.data[8]),

            static_cast<ResultType>(data[2]) * static_cast<ResultType>(other.data[0]) +
            static_cast<ResultType>(data[5]) * static_cast<ResultType>(other.data[1]) +
            static_cast<ResultType>(data[8]) * static_cast<ResultType>(other.data[2]),

            static_cast<ResultType>(data[2]) * static_cast<ResultType>(other.data[3]) +
            static_cast<ResultType>(data[5]) * static_cast<ResultType>(other.data[4]) +
            static_cast<ResultType>(data[8]) * static_cast<ResultType>(other.data[5]),

            static_cast<ResultType>(data[2]) * static_cast<ResultType>(other.data[6]) +
            static_cast<ResultType>(data[5]) * static_cast<ResultType>(other.data[7]) +
            static_cast<ResultType>(data[8]) * static_cast<ResultType>(other.data[8])
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
        data[0] += static_cast<T>(other.data[0]);
        data[1] += static_cast<T>(other.data[1]);
        data[2] += static_cast<T>(other.data[2]);
        data[3] += static_cast<T>(other.data[3]);
        data[4] += static_cast<T>(other.data[4]);
        data[5] += static_cast<T>(other.data[5]);
        data[6] += static_cast<T>(other.data[6]);
        data[7] += static_cast<T>(other.data[7]);
        data[8] += static_cast<T>(other.data[8]);

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
        data[0] -= static_cast<T>(other.data[0]);
        data[1] -= static_cast<T>(other.data[1]);
        data[2] -= static_cast<T>(other.data[2]);
        data[3] -= static_cast<T>(other.data[3]);
        data[4] -= static_cast<T>(other.data[4]);
        data[5] -= static_cast<T>(other.data[5]);
        data[6] -= static_cast<T>(other.data[6]);
        data[7] -= static_cast<T>(other.data[7]);
        data[8] -= static_cast<T>(other.data[8]);

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
        data[0] *= static_cast<T>(scalar);
        data[1] *= static_cast<T>(scalar);
        data[2] *= static_cast<T>(scalar);
        data[3] *= static_cast<T>(scalar);
        data[4] *= static_cast<T>(scalar);
        data[5] *= static_cast<T>(scalar);
        data[6] *= static_cast<T>(scalar);
        data[7] *= static_cast<T>(scalar);
        data[8] *= static_cast<T>(scalar);

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
            static_cast<NewType>(data[0]), static_cast<NewType>(data[3]), static_cast<NewType>(data[6]),
            static_cast<NewType>(data[1]), static_cast<NewType>(data[4]), static_cast<NewType>(data[7]),
            static_cast<NewType>(data[2]), static_cast<NewType>(data[5]), static_cast<NewType>(data[8])
        };
    }

    /**
     * @brief The determinant of the matrix
     */
    [[nodiscard]] constexpr inline T determinant() const requires std::is_signed_v<T> {
        return (data[index(0, 0)] * cofactor(0, 0)) +
               (data[index(1, 0)] * cofactor(1, 0)) +
               (data[index(2, 0)] * cofactor(2, 0));
    }

    /**
     * @brief Transpose of the matrix
     */
    [[nodiscard]] constexpr inline Matrix3 transpose() const {
        return Matrix3{
            data[0], data[1], data[2],
            data[3], data[4], data[5],
            data[6], data[7], data[8]
        };
    }

    /**
     * @brief Cofactor of the matrix at the given row and column
     * 
     * @param row Row of the cofactor (0, 1, or 2)
     * @param column Column of the cofactor (0, 1, or 2)
     */
    [[nodiscard]] constexpr inline T cofactor(std::size_t row, std::size_t column) const requires std::is_signed_v<T> {

        T sign = static_cast<T>(1);
        if ((row + column) % 2 != 0) {
            sign = static_cast<T>(-1);
        }

        std::pair<T, T> rowMinors;
        switch (row) {
            case 0:
                rowMinors = { static_cast<T>(1), static_cast<T>(2) };
                break;
            case 1:
                rowMinors = { static_cast<T>(0), static_cast<T>(2) };
                break;
            case 2:
                rowMinors = { static_cast<T>(0), static_cast<T>(1) };
                break;
            default:
                throw std::out_of_range("Row and column must be 0, 1, or 2");
        }

        std::pair<T, T> columnMinors;
        switch (column) {
            case 0:
                columnMinors = { static_cast<T>(1), static_cast<T>(2) };
                break;
            case 1:
                columnMinors = { static_cast<T>(0), static_cast<T>(2) };
                break;
            case 2:
                columnMinors = { static_cast<T>(0), static_cast<T>(1) };
                break;
            default:
                throw std::out_of_range("Row and column must be 0, 1, or 2");
        }

        return sign * (data[columnMinors.first * 3 + rowMinors.first] * data[columnMinors.second * 3 + rowMinors.second] -
                       data[columnMinors.first * 3 + rowMinors.second] * data[columnMinors.second * 3 + rowMinors.first]);
    }

    [[nodiscard]] constexpr inline Matrix3 inverse() const requires std::is_signed_v<T> {

        const T det = determinant();
        if (det == static_cast<T>(0)) [[unlikely]] {
            throw std::runtime_error("Matrix is not invertible");
        }

        Matrix3 cofactorMatrix = allCofactors();
        return Matrix3{
            cofactorMatrix(0, 0) / det, cofactorMatrix(1, 0) / det, cofactorMatrix(2, 0) / det,
            cofactorMatrix(0, 1) / det, cofactorMatrix(1, 1) / det, cofactorMatrix(2, 1) / det,
            cofactorMatrix(0, 2) / det, cofactorMatrix(1, 2) / det, cofactorMatrix(2, 2) / det
        };
    }

private:

    constexpr inline Matrix3 allCofactors() const requires std::is_signed_v<T> {
        return Matrix3{
             (data[index(1, 1)] * data[index(2, 2)] - data[index(2, 1)] * data[index(1, 2)]),
            -(data[index(0, 1)] * data[index(2, 2)] - data[index(2, 1)] * data[index(0, 2)]),
             (data[index(0, 1)] * data[index(1, 2)] - data[index(1, 1)] * data[index(0, 2)]),

            -(data[index(1, 0)] * data[index(2, 2)] - data[index(2, 0)] * data[index(1, 2)]),
             (data[index(0, 0)] * data[index(2, 2)] - data[index(2, 0)] * data[index(0, 2)]),
            -(data[index(0, 0)] * data[index(1, 2)] - data[index(1, 0)] * data[index(0, 2)]),

             (data[index(1, 0)] * data[index(2, 1)] - data[index(2, 0)] * data[index(1, 1)]),
            -(data[index(0, 0)] * data[index(2, 1)] - data[index(2, 0)] * data[index(0, 1)]),
             (data[index(0, 0)] * data[index(1, 1)] - data[index(1, 0)] * data[index(0, 1)])
        };
    }

    static consteval inline std::size_t index(std::size_t row, std::size_t column) {
        return column * 3 + row;
    }
};

// Type deduction
template <typename T>
Matrix3(
    T, T, T,
    T, T, T,
    T, T, T
) -> Matrix3<T>;

template<typename T>
Matrix3(const std::array<T, 9>&) -> Matrix3<T>;

} // namespace gltkmath

#endif // MATRIX3_HPP
