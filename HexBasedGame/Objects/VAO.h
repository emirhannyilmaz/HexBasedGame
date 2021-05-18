#pragma once

#include <iostream>
#include <GL/glew.h>

class VAO {
public:
    VAO();
    GLuint GetId();
    ~VAO();
private:
    GLuint id;
};