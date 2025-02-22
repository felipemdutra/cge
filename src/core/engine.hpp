#pragma once

namespace cge {
    class Window;
    class Renderer;
    class Input;

    class Engine {
    public:
        Engine(Window& window, Renderer& renderer, Input& input);
        ~Engine();

        void run();

    private:
        void update();

        Window& mWindow;
        Renderer& mRenderer;
        Input& mInput;
    };
}

