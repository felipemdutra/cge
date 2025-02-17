#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <string>

class Shader {
public:
    Shader();
    ~Shader();

    bool init(const char* vertexPath, const char* fragmentPath);
    void use();

    void setBool(const char* name, bool value) const;
    void setInt(const char* name, int value) const;
    void setFloat(const char* name, float value) const;
    void setMat4(const char* name, const glm::mat4 value) const;

private:
    unsigned int id;

    unsigned int compileShader(GLenum type, const char* source);
    void checkCompileErrors(unsigned int shader, std::string type);
};

