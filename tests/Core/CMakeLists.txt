file(GLOB CORE_TEST_SRC
    CONFIGURE_DEPENDS
    "*.cpp"
)

add_executable(CoreTests ${CORE_TEST_SRC})

target_link_libraries(CoreTests
    PRIVATE
    GTest::gtest_main
    Core
)

gtest_discover_tests(CoreTests
    PROPERTIES LABELS "core"
)

add_custom_target(test_core
    COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure -L core
    DEPENDS CoreTests
    USES_TERMINAL
)
