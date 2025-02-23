#include <GLFW/glfw3.h>
#include <cassert>
#include <iostream>

#include "input.hpp"

using namespace cge;

Input::~Input() {
    mWindow = nullptr;
}

bool Input::init(GLFWwindow* window) { 
    assert(window && "Input::init - window is nullptr");

    if (!window) {
        std::cerr << "Input::init - window is nullptr\n";
        return false;
    }

    mWindow = window;

    mKeyActions.reserve(100);
    mKeyStates.reserve(100);
    mPreviousKeyStates.reserve(100);

    mMouseButtonActions.reserve(5);
    mMouseButtonStates.reserve(5);
    mPreviousMouseButtonStates.reserve(5);

    mActionCallbacks.reserve(110);
    return true;
}

void Input::bindKeyAction(int key, std::string& action) {
    mKeyActions[key] = action;
}

void Input::bindMouseButtonAction(int button, std::string& action) {
    mMouseButtonActions[button] = action;
}

void Input::bindCallback(std::string& action, InputCallback callback) {
    mActionCallbacks[action] = callback;
}

bool Input::keyDown(int key) const {
    return glfwGetKey(mWindow, key) == GLFW_PRESS;
}

bool Input::mouseButtonDown(int button) const {
    return glfwGetMouseButton(mWindow, button) == GLFW_PRESS;
}

glm::vec2 Input::getMousePosition() const {
    double x, y;
    glfwGetCursorPos(mWindow, &x, &y);
    return glm::vec2(float(x), float(y));
}

float Input::getMouseX() const {
    return getMousePosition().x;
}

float Input::getMouseY() const {
    return getMousePosition().y;
}

void Input::update() {
    // Update key states
    for (const auto& [key, action] : mKeyStates) {
        mPreviousKeyStates[key] = mKeyStates[key];
        mKeyStates[key] = keyDown(key);
    }

    // Update mouse button states
    for (const auto& [button, action] : mMouseButtonStates) {
        mPreviousMouseButtonStates[button] = mMouseButtonStates[button];
        mMouseButtonStates[button] = mouseButtonDown(button);
    }

    // Go over all key bindings, and check if the key has been pressed
    for (const auto& [key, action] : mKeyActions) {
        if (mKeyStates[key]) {
            // Call the callback associated with the action
            mActionCallbacks[action]();
        }
    }

    for (const auto& [button, action] : mMouseButtonActions) {
        // Only execute callback if the button was pressed once.
        if (mMouseButtonStates[button] && !mPreviousMouseButtonStates[button]) {
            mActionCallbacks[action]();
        }
    }
}

