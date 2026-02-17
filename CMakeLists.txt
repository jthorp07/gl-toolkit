cmake_minimum_required(VERSION 4.0)

project(GLToolkit LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(GLTKMath)
add_subdirectory(Core)

find_package(Qt6 QUIET COMPONENTS Widgets)
if(Qt6_FOUND)
    add_subdirectory(GLTKEditor)
else()
    find_package(Qt5 QUIET COMPONENTS Widgets)
    if(Qt5_FOUND)
        add_subdirectory(GLTKEditor)
    else()
        message(STATUS "Qt not found, skipping GLTKEditor")
    endif()
endif()

add_subdirectory(tests)
