#include "engine.hpp"
#include "../platform/window.hpp"
#include "renderer/renderer.hpp"

using namespace cge;

#define WIDTH 800
#define HEIGHT 600

Engine::Engine(Window& window, Renderer& renderer) : window(window), renderer(renderer) { }

Engine::~Engine() { }

void Engine::run() {
    while (!window.shouldClose()) {
        renderer.clear(0.0f, 0.15f, 0.6f, 1.0f);

        renderer.draw();

        window.pollEvents();
        window.swapBuffers();
    }
}

