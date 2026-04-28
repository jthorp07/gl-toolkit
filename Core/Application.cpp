/**
 * @file Application.cpp
 * 
 * @brief Implementation file for the Application class
 */

#include "Application.hpp"

namespace gltk {

ApplicationArguments Application::parseArguments(int argc, char** argv) {
    ApplicationArguments args;
    for (int i = 0; i < argc; ++i) {
        args.arguments.emplace_back(argv[i]);
    }
    return args;
}

Application::Application(ApplicationArguments args) : arguments(std::move(args)) {}

void Application::preInitialize() {}

void Application::postInitialize() {}

void Application::preShutdown() {}

void Application::postShutdown() {}

}
