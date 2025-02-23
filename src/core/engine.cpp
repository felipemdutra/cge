
#include "./engine.hpp"
#include "./window/window.hpp"
#include "./renderer/renderer.hpp"
#include "./input/input.hpp"

#include <GLFW/glfw3.h>
#include <string>
#include <iostream>

using namespace cge;

Engine::Engine(Window& window, Renderer& renderer, Input& input) 
    : mWindow(window), mRenderer(renderer), mInput(input) { }

Engine::~Engine() { }

void Engine::run() {

    // Temporary input binding, just to test the input system
    std::string walkForward = "WalkForward";
    mInput.bindKeyAction(GLFW_KEY_W, walkForward);
    mInput.bindCallback(walkForward, [&]() {
        std::cout << "Walking forward\n";
    });

    std::string walkBackward = "WalkBackward";
    mInput.bindKeyAction(GLFW_KEY_S, walkBackward);
    mInput.bindCallback(walkBackward, [&]() {
        std::cout << "Walking backward\n";
    });

    std::string shoot = "Shoot";
    mInput.bindMouseButtonAction(GLFW_MOUSE_BUTTON_1, shoot);
    mInput.bindCallback(shoot, [&]() {
        std::cout << "Shot\n";
    });

    while (!mWindow.shouldClose()) {
        mRenderer.clear(0.1f, 0.15f, 1.0f, 1.0f);

        mRenderer.draw();

        mInput.update();

        mWindow.pollEvents();
        mWindow.swapBuffers();
    }
}

