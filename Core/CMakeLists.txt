cmake_minimum_required(VERSION 4.0)

project(Core LANGUAGES CXX)

add_library(Core STATIC
  core.cpp
  core.hpp
)

target_include_directories(Core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_compile_definitions(Core PRIVATE CORE_LIBRARY)
