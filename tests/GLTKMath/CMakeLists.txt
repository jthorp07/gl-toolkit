file(GLOB GLTKMATH_TEST_SRC
    CONFIGURE_DEPENDS
    "*.cpp"
)

add_executable(GLTKMathTests ${GLTKMATH_TEST_SRC})

target_link_libraries(GLTKMathTests
    PRIVATE
    GTest::gtest_main
    GLTKMath
)

gtest_discover_tests(GLTKMathTests
    PROPERTIES LABELS "gltkmath"
)

add_custom_target(test_gltkmath
    COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure -L gltkmath
    DEPENDS GLTKMathTests
    USES_TERMINAL
)
