cmake_minimum_required(VERSION 4.0)

project(Core LANGUAGES CXX)

file(GLOB_RECURSE CORE_SRC
  "*.cpp")

file(GLOB_RECURSE CORE_INCLUDE
  "*.hpp")

add_library(Core STATIC
  ${CORE_SRC}
  ${CORE_INCLUDE}
)

target_include_directories(Core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_compile_definitions(Core PRIVATE CORE_LIBRARY)
