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
};

} // namespace gltkmath

#endif
