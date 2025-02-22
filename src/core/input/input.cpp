#include <GLFW/glfw3.h>
#include <cassert>
#include <iostream>

#include "input.hpp"

using namespace cge;

/**
* init Initializes the input system.
*
* @param window - The window to bind the input to.
* @return bool - True if the input system was initialized successfully, false otherwise.
*/
bool Input::init(GLFWwindow* window) { 
    assert(window && "Input::init - window is nullptr");

    if (!window) {
        std::cerr << "Input::init - window is nullptr\n";
        return false;
    }

    sWindow = window;

    return true;
}

void Input::bindAction(std::string& action, int key) {
    mKeyActions[key] = action;
}

void Input::bindCallback(std::string& action, InputCallback callback) {
    mActionCallbacks[action] = callback;
}

bool Input::keyDown(int key) const {
    return glfwGetKey(sWindow, key) == GLFW_PRESS;
}

