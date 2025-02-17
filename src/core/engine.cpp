#include <memory>

#include "engine.hpp"

using namespace cge;
using std::make_unique;

#define WIDTH 800
#define HEIGHT 600

Engine::Engine() : window(make_unique<Window>()),  renderer(make_unique<Renderer>()) { }

Engine::~Engine() { }

bool Engine::init() {
    if (!window->init(WIDTH, HEIGHT, "Game Engine")) {
        return false;
    }

    if (!renderer->init()) {
        return false;
    }

    return true;
}

void Engine::run() {
    while (!window->shouldClose()) {
        renderer->clear(0.0f, 0.15f, 0.3f, 1.0f);

        renderer->draw();

        window->pollEvents();
        window->swapBuffers();
    }
}

