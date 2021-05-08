#include "VAO.h"

VAO::VAO() {
    glGenVertexArrays(1, &id);
}

void VAO::Bind() {
    glBindVertexArray(id);
}

void VAO::StoreDataInAttributeList(GLuint slot, GLint coordinateLength, GLsizei stride, const void* offset) {
    glVertexAttribPointer(slot, coordinateLength, GL_FLOAT, GL_FALSE, stride, offset);
    glEnableVertexAttribArray(slot);
}

void VAO::Unbind() {
    glBindVertexArray(0);
}

GLuint VAO::GetId() {
    return id;
}

VAO::~VAO() {
    glDeleteVertexArrays(1, &id);
}
