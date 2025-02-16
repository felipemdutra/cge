#include <GL/glew.h>

#include "renderer.hpp"

using namespace cge;

Renderer::Renderer() { }

Renderer::~Renderer() { }

void Renderer::init() {
    
    glEnable(GL_DEPTH_TEST);
}

void Renderer::clear(float r, float g, float b, float a) {
    glClearColor(r, g, b, a);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

