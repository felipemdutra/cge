#include <GLFW/glfw3.h>
#include <stdexcept>

#include "input.hpp"

using namespace cge;

Input::Input(Window* window) { 
    if (!window) {
        throw std::runtime_error("Failed to start Input Subsystem: Window is nullptr");
    }

    mWindow = window;
}

