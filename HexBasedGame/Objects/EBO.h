#pragma once

#include <iostream>
#include <GL/glew.h>

class EBO {
public:
    EBO();
    GLuint GetId();
    ~EBO();
private:
    GLuint id;
};