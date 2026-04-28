/**
 * @file tst_Application.cpp
 * 
 * @brief Test cases for the Application class
 */

#include <gtest/gtest.h>
#include "Application.hpp"

TEST(Application, parseArguments) {
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

TEST(Application, ExternalImplementationLoop) {

    class Foo : public gltk::Application {
        std::size_t tickCount = 0;
        float secondsElapsed = 0.0f;
    public:
        explicit Foo(gltk::ApplicationArguments args) : gltk::Application(std::move(args)) {}
        void tick(float deltaSeconds) override {
            ++tickCount;
            secondsElapsed += deltaSeconds;
        }
        std::size_t getTickCount() const { return tickCount; }
        float getSecondsElapsed() const { return secondsElapsed; }
    };

    gltk::ApplicationArguments args;
    Foo app(args);

    app.preInitialize();
    app.postInitialize();
    float expectedSecondsElapsed = 0.0f;
    for (std::size_t tick = 0; tick < 10; ++tick) {

        const float deltaSeconds = 0.01f * static_cast<float>(tick);
        app.tick(deltaSeconds);
        expectedSecondsElapsed += deltaSeconds;
    }
    app.preShutdown();
    app.postShutdown();

    EXPECT_FLOAT_EQ(app.getSecondsElapsed(), expectedSecondsElapsed);
    EXPECT_EQ(app.getTickCount(), 10);
}
