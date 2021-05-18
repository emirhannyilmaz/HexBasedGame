#pragma once

#include <iostream>
#include <GL/glew.h>

class VBO {
public:
    VBO();
    GLuint GetId();
    ~VBO();
private:
    GLuint id;
};