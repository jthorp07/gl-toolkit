cmake_minimum_required(VERSION 4.0)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

file(GLOB_RECURSE TEST_SOURCES
    "*.cpp"
)

add_executable(GLTKTests ${TEST_SOURCES})

target_link_libraries(GLTKTests
    PRIVATE
    GTest::gtest_main
    GLTKMath
    Core
)

include(GoogleTest)
gtest_discover_tests(GLTKTests)

add_custom_target(run_tests
    COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
    DEPENDS GLTKTests
)
