#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "window.hpp"

using namespace cge;

Window::Window() : window(nullptr) { }

bool Window::init(int width, int height, std::string title) {
    if (!glfwInit()) {
        return false;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        return false;
    }

    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK) {
        return false;
    }

    return true;
}

Window::~Window() {
    glfwDestroyWindow(window);
    glfwTerminate();
}

void Window::update() {
    swapBuffers();
    pollEvents();
}

void Window::setShouldClose(bool value) {
    glfwSetWindowShouldClose(window, value);
}

bool Window::shouldClose() const {
    return glfwWindowShouldClose(window);
}

void Window::swapBuffers() {
    glfwSwapBuffers(window);
}

void Window::pollEvents() {
    glfwPollEvents();
}

