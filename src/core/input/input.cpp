#include <GLFW/glfw3.h>
#include <cassert>
#include <iostream>

#include "input.hpp"

using namespace cge;

Input::~Input() {
    mWindow = nullptr;
}

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

    mWindow = window;

    mKeyActions.reserve(100);
    mActionCallbacks.reserve(100);
    mKeyStates.reserve(100);
    mPreviousKeyStates.reserve(100);

    return true;
}

void Input::bindAction(std::string& action, int key) {
    mKeyActions[key] = action;
}

void Input::bindCallback(std::string& action, InputCallback callback) {
    mActionCallbacks[action] = callback;
}

bool Input::keyDown(int key) const {
    return glfwGetKey(mWindow, key) == GLFW_PRESS;
}

void Input::update() {
    // Update key states
    for (const auto& [key, action] : mKeyStates) {
        mPreviousKeyStates[key] = mKeyStates[key];
        mKeyStates[key] = keyDown(key);
    }

    // Go over all key bindings, and check if the key has been pressed
    for (const auto& [key, action] : mKeyActions) {
        if (mKeyStates[key]) {
            // Call the callback associated with the action
            mActionCallbacks[action]();
        }
    }
}

