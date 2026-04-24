/**
 * @file tst_Application.cpp
 * 
 * @brief Test cases for the Application class
 */

#include <gtest/gtest.h>
#include "Application.hpp"

TEST(Application, ParseArguments) {
    const char* argv[] = {"app", "arg1", "arg2"};
    int argc = sizeof(argv) / sizeof(argv[0]);

    gltk::ApplicationArguments args = gltk::Application::parseArguments(argc, const_cast<char**>(argv));

    ASSERT_EQ(args.arguments.size(), 3);
    EXPECT_EQ(args.arguments[0], "app");
    EXPECT_EQ(args.arguments[1], "arg1");
    EXPECT_EQ(args.arguments[2], "arg2");
}

TEST(Application, Constructor) {

    class Foo : public gltk::Application {
    public:
        explicit Foo(gltk::ApplicationArguments args) : gltk::Application(std::move(args)) {}
        void tick(float deltaSeconds) override {}
    };

    gltk::ApplicationArguments args;
    args.arguments = {"app", "arg1", "arg2"};

    Foo app(args);
}
