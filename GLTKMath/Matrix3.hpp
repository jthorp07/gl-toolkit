/**
 * @file Matrix3.hpp
 *
 * @brief Include file for the Matrix3 class
 */

#ifndef MATRIX3_HPP
#define MATRIX3_HPP

#include <cmath>

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
     * @brief Component-wise constructor - Explicitly initializes with 9 components
     */
    constexpr Matrix3(
        T c0r0, T c0r1, T c0r2,
        T c1r0, T c1r1, T c1r2,
        T c2r0, T c2r1, T c2r2
    ) : c0r0(c0r0), c0r1(c0r1), c0r2(c0r2),
        c1r0(c1r0), c1r1(c1r1), c1r2(c1r2),
        c2r0(c2r0), c2r1(c2r1), c2r2(c2r2) {};
        
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
