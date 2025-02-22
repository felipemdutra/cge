#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "window.hpp"

using namespace cge;

Window::Window() : mWindow(nullptr) { }

bool Window::init(int width, int height, std::string title) {
    if (!glfwInit()) {
        return false;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    mWindow = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    if (!mWindow) {
        glfwTerminate();
        return false;
    }

    glfwMakeContextCurrent(mWindow);

    if (glewInit() != GLEW_OK) {
        return false;
    }

    return true;
}

Window::~Window() {
    glfwDestroyWindow(mWindow);
    glfwTerminate();
}

void Window::update() {
    swapBuffers();
    pollEvents();
}

void Window::setShouldClose(bool value) {
    glfwSetWindowShouldClose(mWindow, value);
}

bool Window::shouldClose() const {
    return glfwWindowShouldClose(mWindow);
}

void Window::swapBuffers() {
    glfwSwapBuffers(mWindow);
}

void Window::pollEvents() {
    glfwPollEvents();
}

