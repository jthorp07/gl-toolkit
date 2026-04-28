cmake_minimum_required(VERSION 4.0)

project(GLTKMath LANGUAGES CXX)

file(GLOB_RECURSE MATH_SRC
  CONFIGURE_DEPENDS
  "*.cpp")

file(GLOB_RECURSE MATH_INCLUDE
  CONFIGURE_DEPENDS
  "*.hpp")

add_library(GLTKMath STATIC
  ${MATH_SRC}
  ${MATH_INCLUDE}
)

target_include_directories(GLTKMath PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_compile_definitions(GLTKMath PRIVATE GLTKMATH_LIBRARY)
