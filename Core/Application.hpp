/**
 * @file Application.hpp
 * 
 * @brief Include file for the Application class and supporting types
 * 
 * Provides hooks for major engine components and should be used as the main controller of the application
 */

#ifndef GLTK_APPLICATION_HPP
#define GLTK_APPLICATION_HPP

#include <string_view>
#include <vector>

namespace gltk {

/**
 * @brief Struct to hold a view of the command line arguments passed to
 *        the application
 */
struct ApplicationArguments {
    std::vector<std::string_view> arguments;
};

class Application {
private:
    ApplicationArguments arguments;
public:

    /**
     * @brief Parses command line arguments into an ApplicationArguments
     *        struct
     * 
     * @param argc The number of command line arguments
     * @param argv The command line arguments as an array of C-strings
     */
    static ApplicationArguments parseArguments(int argc, char** argv);

    /**
     * @brief Constructor for the application - initializes the application
     *        with the given arguments
     */
    explicit Application(ApplicationArguments args);

    /**
     * @brief Virtual destructor for subtypes
     */
    virtual ~Application() = default;

    /**
     * @brief Runs before loading any engine systems. Can be used to set up
     *        the application state before any engine initialization occurs
     */
    virtual void preInitialize();

    /**
     * @brief Runs after loading all engine systems. Can be used to set up the
     *        application state and configure engine systems before the main
     *        loop starts
     */
    virtual void postInitialize();

    /**
     * @brief Runs the core application loop
     */
    virtual void run() = 0;

    /**
     * @brief Runs after the main loop ends, but before engine systems are shut
     *        down. Can be used for cleanup that requires engine systems to still
     *        be running
     */
    virtual void preShutdown();

    /**
    * @brief Runs after the main loop ends and all engine systems have been shut
    *        down. Can be used for final cleanup before the application exits
    */
    virtual void postShutdown();
};

} // namespace gltk

#endif // GLTK_APPLICATION_HPP
