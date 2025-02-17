#pragma once

#include <memory>

#include "shader.hpp"

namespace cge {
    class Renderer {
    public:
        Renderer();
        ~Renderer();

        bool init();
        void clear(float r, float g, float b, float a);

        // Draws a simple shape for now
        void draw();

    private:
        std::unique_ptr<Shader> shader;
        unsigned int vao, vbo;

        // vertex data for simple triangle 
        // temporary, just to test rendering
        float vertices[9] = {
            -0.5f, -0.5f, 0.0f,
             0.5f, -0.5f, 0.0f,
             0.0f,  0.5f, 0.0f
        };
    };
}

