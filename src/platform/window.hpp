#pragma once

#include <string>

class GLFWwindow;

namespace cge {
    class Window {
    public:
        Window();
        ~Window();

        /**
         * init Initializes GLFW, GLEW and creates a window.
         *
         * @param width - The width of the window.
         * @param height - The height of the window.
         * @param title - The title of the window.
         * @return bool - True if the window was created successfully, false otherwise.
         */
        bool init(int width, int height, std::string title);

        /**
         * update Updates the window.
         * This function should be called every frame.
         */
        void update();
        void setShouldClose(bool value);
        bool shouldClose() const;
        void swapBuffers();
        void pollEvents();

    private:
        GLFWwindow* window;
    };
}

