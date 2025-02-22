#include "./core/window/window.hpp"
#include "./core/engine.hpp"
#include "./core/renderer/renderer.hpp"
#include "./core/input/input.hpp"
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

    cge::Input input;
    if (!input.init(window.getNativeWindow())) {
        std::cerr << "Failed to initialize input" << std::endl;
        return -1;
    }

    cge::Engine engine(window, renderer, input);

    engine.run();

    return 0;
}

