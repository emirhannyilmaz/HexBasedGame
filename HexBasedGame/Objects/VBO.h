#pragma once

#include <iostream>
#include <GL/glew.h>

class VBO {
public:
    VBO();
    void Bind();
    void StoreData(GLsizeiptr size, const void* data);
    void Unbind();
    ~VBO();
private:
    GLuint id;
};