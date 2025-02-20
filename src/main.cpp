#include "./core/engine.hpp"
#include "./platform/window.hpp"
#include "./core/renderer/renderer.hpp"
#include <iostream>

#define WINDOW_TITLE "CGE"
#define WIDTH 800
#define HEIGHT 600

int main() {
    cge::Window window;
    if (!window.init(WIDTH, HEIGHT, WINDOW_TITLE)) {
        std::cerr << "Failed to initialize window" << std::endl;
        return -1;
    }

    cge::Renderer renderer;
    if (!renderer.init()) {
        std::cerr << "Failed to initialize renderer" << std::endl;
        return -1;
    }

    cge::Engine engine(window, renderer);

    engine.run();

    return 0;
}

