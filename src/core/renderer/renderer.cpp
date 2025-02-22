#include <GL/glew.h>

#include "renderer.hpp"

using namespace cge;
using std::make_unique;

Renderer::Renderer() : mShader(make_unique<Shader>()) { }

Renderer::~Renderer() { }

bool Renderer::init() {
    glEnable(GL_DEPTH_TEST);

    mShader->init("src/shaders/defaultVertex.glsl", "src/shaders/defaultFragment.glsl");

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    mShader->use();

    return true;
}

void Renderer::clear(float r, float g, float b, float a) {
    glClearColor(r, g, b, a);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::draw() {
    glBindVertexArray(vao);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glBindVertexArray(0);
}

