cmake_minimum_required(VERSION 4.0)

project(GLTKMath LANGUAGES CXX)

add_library(GLTKMath STATIC
  gltkmath.cpp
  gltkmath.hpp
  Vector3.hpp
  Vector4.hpp
  Matrix3.hpp
)

target_include_directories(GLTKMath PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_compile_definitions(GLTKMath PRIVATE GLTKMATH_LIBRARY)
