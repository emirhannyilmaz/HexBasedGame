#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

class ShaderProgram {
public:
    ShaderProgram(const char* vertexShaderPath, const char* fragmentShaderPath);
    ~ShaderProgram();
    GLint GetUniformLocation(const char* uniformName);
    void LoadMatrix4f(GLint location, glm::mat4 matrix);
    void LoadVector3f(GLint location, glm::vec3 vector);
    void LoadVector4f(GLint location, glm::vec4 vector);
    void LoadFloat(GLint location, float value);
    void LoadBoolean(GLint location, bool value);
    void LoadInt(GLint location, int value);
    void Start();
    void Stop();
private:
    GLuint programId;
    GLuint vertexId;
    GLuint fragmentId;
};
