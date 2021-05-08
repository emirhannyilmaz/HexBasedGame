#pragma once

#include <iostream>
#include <GL/glew.h>

class EBO {
public:
    EBO();
    void Bind();
    void StoreData(GLsizeiptr size, const void* data);
    void Unbind();
    ~EBO();
private:
    GLuint id;
};