
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
    mInput.bindAction(walkForward, GLFW_KEY_W);
    mInput.bindCallback(walkForward, [&]() {
        std::cout << "Walking forward\n";
    });

    while (!mWindow.shouldClose()) {
        mRenderer.clear(0.1f, 0.15f, 1.0f, 1.0f);

        mRenderer.draw();

        mInput.update();

        mWindow.pollEvents();
        mWindow.swapBuffers();
    }
}

