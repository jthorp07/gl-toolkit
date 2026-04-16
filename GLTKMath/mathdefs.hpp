/**
 * @file mathdefs.hpp
 * 
 * @brief Common internal definitions and utilities for GLTKMath
 */

#ifndef MATHDEFS_HPP
#define MATHDEFS_HPP

#include <concepts>

namespace gltkmath {

/**
 * @brief Concept for constraining to types that can losslessly
 *        implicitly convert to another type
 * 
 * @tparam From Type to convert from
 * @tparam To Type to convert to
 */
template<typename From, typename To>
concept lossless_convertible_to = requires(From from) {
    To{ from };
};

} // namespace gltkmath

#endif // MATHDEFS_HPP
