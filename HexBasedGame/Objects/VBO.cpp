#include "VBO.h"

VBO::VBO() {
    glGenBuffers(1, &id);
}

GLuint VBO::GetId() {
    return id;
}

VBO::~VBO() {
    glDeleteBuffers(1, &id);
}
