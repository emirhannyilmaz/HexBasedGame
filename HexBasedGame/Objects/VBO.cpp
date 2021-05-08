#include "VBO.h"

VBO::VBO() {
    glGenBuffers(1, &id);
}

void VBO::Bind() {
    glBindBuffer(GL_ARRAY_BUFFER, id);
}

void VBO::StoreData(GLsizeiptr size, const void* data) {
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

void VBO::Unbind() {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

VBO::~VBO() {
    glDeleteBuffers(1, &id);
}
