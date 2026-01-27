cmake_minimum_required(VERSION 4.0)

project(GLToolkit LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_subdirectory(GLTKMath)
add_subdirectory(Core)
add_subdirectory(GLTKEditor)
add_subdirectory(tests)
