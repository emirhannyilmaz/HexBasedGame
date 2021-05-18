#include "EBO.h"

EBO::EBO() {
    glGenBuffers(1, &id);
}

GLuint EBO::GetId() {
    return id;
}

EBO::~EBO() {
    glDeleteBuffers(1, &id);
}
