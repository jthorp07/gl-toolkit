/**
 * @file Matrix4.hpp
 * 
 * @brief Include file for the Matrix4 class
 */

#ifndef GLTKMATH_MATRIX4_HPP
#define GLTKMATH_MATRIX4_HPP

#include "Vector4.hpp"
#include "mathdefs.hpp"
#include "errordefs.hpp"

#include <array>
#include <cmath>

namespace gltkmath {

template<typename T>
    requires std::is_arithmetic_v<T>
class Matrix4 {
private:
    std::array<T, 16> data;
public:

    /**
     * @brief Default constructor - Initializes all components to zero
     */
    constexpr Matrix4() : data{} {};

    /**
     * @brief Component-wise constructor - Explicitly initializes with 16
     *        components
     *
     * @param c0r0 First column, first row component
     * @param c0r1 First column, second row component
     * @param c0r2 First column, third row component
     * @param c0r3 First column, fourth row component
     * 
     * @param c1r0 Second column, first row component
     * @param c1r1 Second column, second row component
     * @param c1r2 Second column, third row component
     * @param c1r3 Second column, fourth row component
     *
     * @param c2r0 Third column, first row component
     * @param c2r1 Third column, second row component
     * @param c2r2 Third column, third row component
     * @param c2r3 Third column, fourth row component
     *
     * @param c3r0 Fourth column, first row component
     * @param c3r1 Fourth column, second row component
     * @param c3r2 Fourth column, third row component
     * @param c3r3 Fourth column, fourth row component
     */
    constexpr Matrix4(
        T c0r0, T c1r0, T c2r0, T c3r0,
        T c0r1, T c1r1, T c2r1, T c3r1,
        T c0r2, T c1r2, T c2r2, T c3r2,
        T c0r3, T c1r3, T c2r3, T c3r3
    ) : data({
        c0r0, c0r1, c0r2, c0r3,
        c1r0, c1r1, c1r2, c1r3,
        c2r0, c2r1, c2r2, c2r3,
        c3r0, c3r1, c3r2, c3r3
    }) {}

    /**
     * @brief Explicit array constructor - Initializes with an array of
     *        16 components in column-major order
     *
     * @param components Array of 16 components in column-major order
     */
    constexpr explicit Matrix4(const std::array<T, 16>& components)
        : data(components) {}

    /**
     * @brief Explicit array constructor - Initializes with an array of
     *        16 components in column-major order by move
     */
    constexpr explicit Matrix4(std::array<T, 16>&& components)
        : data(std::move(components)) {}

    /**
     * @brief Accessor for the component at the specified column and row
     * 
     * @param column Column index
     * @param row Row index
     * 
     * @return Reference to the component at the specified location
     */
    [[nodiscard]] constexpr inline T& operator()(std::size_t column, std::size_t row) noexcept {
        if (column >= 4 || row >= 4) [[unlikely]] {
            gltkmath::Error::Fatal("Matrix4 indices out of bounds");
        }
        return data[column * 4 + row];
    }

    /**
     * @brief Read-only accessor for the component at the specified column and row
     * 
     * @param column Column index
     * @param row Row index
     * 
     * @return Reference to the component at the specified location
     */
    [[nodiscard]] constexpr inline const T& operator()(std::size_t column, std::size_t row) const noexcept {
        if (column >= 4 || row >= 4) [[unlikely]] {
            gltkmath::Error::Fatal("Matrix4 indices out of bounds");
        }
        return data[column * 4 + row];
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
    [[nodiscard]] constexpr inline Matrix4<std::common_type_t<T, U>> operator+(const Matrix4<U>& other) const {
        using ResultType = std::common_type_t<T, U>;
        return Matrix4{
            static_cast<ResultType>(data[ 0]) + static_cast<ResultType>(other.data[ 0]),
            static_cast<ResultType>(data[ 1]) + static_cast<ResultType>(other.data[ 1]),
            static_cast<ResultType>(data[ 2]) + static_cast<ResultType>(other.data[ 2]),
            static_cast<ResultType>(data[ 3]) + static_cast<ResultType>(other.data[ 3]),
            static_cast<ResultType>(data[ 4]) + static_cast<ResultType>(other.data[ 4]),
            static_cast<ResultType>(data[ 5]) + static_cast<ResultType>(other.data[ 5]),
            static_cast<ResultType>(data[ 6]) + static_cast<ResultType>(other.data[ 6]),
            static_cast<ResultType>(data[ 7]) + static_cast<ResultType>(other.data[ 7]),
            static_cast<ResultType>(data[ 8]) + static_cast<ResultType>(other.data[ 8]),
            static_cast<ResultType>(data[ 9]) + static_cast<ResultType>(other.data[ 9]),
            static_cast<ResultType>(data[10]) + static_cast<ResultType>(other.data[10]),
            static_cast<ResultType>(data[11]) + static_cast<ResultType>(other.data[11]),
            static_cast<ResultType>(data[12]) + static_cast<ResultType>(other.data[12]),
            static_cast<ResultType>(data[13]) + static_cast<ResultType>(other.data[13]),
            static_cast<ResultType>(data[14]) + static_cast<ResultType>(other.data[14]),
            static_cast<ResultType>(data[15]) + static_cast<ResultType>(other.data[15])
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
    [[nodiscard]] constexpr inline Matrix4<std::common_type_t<T, U>> operator-(const Matrix4<U>& other) const {
        using ResultType = std::common_type_t<T, U>;
        return Matrix4{
            static_cast<ResultType>(data[ 0]) - static_cast<ResultType>(other.data[ 0]),
            static_cast<ResultType>(data[ 1]) - static_cast<ResultType>(other.data[ 1]),
            static_cast<ResultType>(data[ 2]) - static_cast<ResultType>(other.data[ 2]),
            static_cast<ResultType>(data[ 3]) - static_cast<ResultType>(other.data[ 3]),
            static_cast<ResultType>(data[ 4]) - static_cast<ResultType>(other.data[ 4]),
            static_cast<ResultType>(data[ 5]) - static_cast<ResultType>(other.data[ 5]),
            static_cast<ResultType>(data[ 6]) - static_cast<ResultType>(other.data[ 6]),
            static_cast<ResultType>(data[ 7]) - static_cast<ResultType>(other.data[ 7]),
            static_cast<ResultType>(data[ 8]) - static_cast<ResultType>(other.data[ 8]),
            static_cast<ResultType>(data[ 9]) - static_cast<ResultType>(other.data[ 9]),
            static_cast<ResultType>(data[10]) - static_cast<ResultType>(other.data[10]),
            static_cast<ResultType>(data[11]) - static_cast<ResultType>(other.data[11]),
            static_cast<ResultType>(data[12]) - static_cast<ResultType>(other.data[12]),
            static_cast<ResultType>(data[13]) - static_cast<ResultType>(other.data[13]),
            static_cast<ResultType>(data[14]) - static_cast<ResultType>(other.data[14]),
            static_cast<ResultType>(data[15]) - static_cast<ResultType>(other.data[15])
        };
    }
};

// Type deduction
template<typename T>
Matrix4(
    T, T, T, T,
    T, T, T, T,
    T, T, T, T,
    T, T, T, T
) -> Matrix4<T>;

template<typename T>
Matrix4(const std::array<T, 16>&) -> Matrix4<T>;

} // namespace gltkmath

#endif
