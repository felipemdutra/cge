#include "engine.hpp"
#include "platform/window.hpp"
#include "renderer/renderer.hpp"

using namespace cge;

#define WIDTH 800
#define HEIGHT 600

Engine::Engine(Window& window, Renderer& renderer) : mWindow(window), mRenderer(renderer) { }

Engine::~Engine() { }

void Engine::run() {
    while (!mWindow.shouldClose()) {
        mRenderer.clear(0.0f, 0.15f, 0.6f, 1.0f);

        mRenderer.draw();

        mWindow.pollEvents();
        mWindow.swapBuffers();
    }
}

