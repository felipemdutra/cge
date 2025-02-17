#pragma once

#include <memory>

#include "../platform/window.hpp"
#include "./renderer/renderer.hpp"

namespace cge {
    class Engine {
    public:
        Engine();
        ~Engine();

        bool init();
        void run();

    private:
        std::unique_ptr<Window> window;
        std::unique_ptr<Renderer> renderer;
    };
}

