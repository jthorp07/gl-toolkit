/**
 * @file errordefs.hpp
 * 
 * @brief Include file for error definitions and exception classes
 */

#ifndef GLTKMATH_ERRORDEFS_HPP
#define GLTKMATH_ERRORDEFS_HPP

#include <cstdio>
#include <cstdlib>
#include <string>

namespace gltkmath {

class Error {
public:

    // Not constructible, copyable, movable, or assignable
    Error() = delete;
    ~Error() = delete;
    Error(const Error&) = delete;
    Error& operator=(const Error&) = delete;
    Error(Error&&) = delete;
    Error& operator=(Error&&) = delete;

    /**
     * @brief Prints a fatal error message and terminates the program
     * 
     * @param message Error message to print
     */
    [[noreturn]] static inline void Fatal(const std::string& message) {

        std::fprintf(
            stderr,
            "[GLTKMATH][FATAL] %s\n",
            message.c_str()
        );
        std::fflush(stderr);
        std::abort();
    }
};

} // namespace gltkmath

#endif
