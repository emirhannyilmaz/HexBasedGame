#include "VAO.h"

VAO::VAO() {
    glGenVertexArrays(1, &id);
}

GLuint VAO::GetId() {
    return id;
}

VAO::~VAO() {
    glDeleteVertexArrays(1, &id);
}
