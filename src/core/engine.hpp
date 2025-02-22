#pragma once


namespace cge {
    class Window;
    class Renderer;

    class Engine {
    public:
        Engine(Window& window, Renderer& renderer);
        ~Engine();

        void run();

    private:
        void update();

        Window& mWindow;
        Renderer& mRenderer;
    };
}

