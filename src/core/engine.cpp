#include <memory>

#include "engine.hpp"

using namespace cge;

#define WIDTH 800
#define HEIGHT 600

Engine::Engine() : window(std::make_unique<Window>()){ }

Engine::~Engine() { }

bool Engine::init() {
    if (!window->init(WIDTH, HEIGHT, "Game Engine")) {
        return false;
    }

    return true;
}

void Engine::run() {
    while (!window->shouldClose()) {
        window->pollEvents();
        window->swapBuffers();
    }
}

