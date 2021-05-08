#pragma once

#include <iostream>
#include <GL/glew.h>

class VAO {
public:
    VAO();
    void Bind();
    void StoreDataInAttributeList(GLuint slot, GLint coordinateLength, GLsizei stride, const void* offset);
    void Unbind();
    GLuint GetId();
    ~VAO();
private:
    GLuint id;
};