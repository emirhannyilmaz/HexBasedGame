#include "EBO.h"

EBO::EBO() {
    glGenBuffers(1, &id);
}

void EBO::Bind() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
}

void EBO::StoreData(GLsizeiptr size, const void* data) {
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

void EBO::Unbind() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

EBO::~EBO() {
    glDeleteBuffers(1, &id);
}
