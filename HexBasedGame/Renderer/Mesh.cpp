#include "Mesh.h"

Mesh::Mesh(std::vector<glm::vec3> vertices, std::vector<glm::vec2> texCoords, std::vector<glm::vec3> normals, std::vector<GLuint> indices) {
    indicesCount = indices.size();

    vao = new VAO();
    glBindVertexArray(vao->GetId());

    vbo1 = new VBO();
    glBindBuffer(GL_ARRAY_BUFFER, vbo1->GetId());
    glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * vertices.size(), &vertices[0], GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), (void*) 0);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    vbo2 = new VBO();
    glBindBuffer(GL_ARRAY_BUFFER, vbo2->GetId());
    glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec2) * texCoords.size(), &texCoords[0], GL_STATIC_DRAW);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(glm::vec2), (void*) 0);
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    vbo3 = new VBO();
    glBindBuffer(GL_ARRAY_BUFFER, vbo3->GetId());
    glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * normals.size(), &normals[0], GL_STATIC_DRAW);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), (void*) 0);
    glEnableVertexAttribArray(2);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    ebo = new EBO();
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo->GetId());
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * indices.size(), &indices[0], GL_STATIC_DRAW);

    glBindVertexArray(0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

Mesh::Mesh(std::vector<glm::vec3> vertices) {
    verticesCount = vertices.size();

    vao = new VAO();
    glBindVertexArray(vao->GetId());

    vbo1 = new VBO();
    glBindBuffer(GL_ARRAY_BUFFER, vbo1->GetId());
    glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * vertices.size(), &vertices[0], GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), (void*) 0);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);
}

Mesh::Mesh(std::vector<glm::vec2> vertices) {
    verticesCount = vertices.size();

    vao = new VAO();
    glBindVertexArray(vao->GetId());
    
    vbo1 = new VBO();
    glBindBuffer(GL_ARRAY_BUFFER, vbo1->GetId());
    glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec2) * vertices.size(), &vertices[0], GL_STATIC_DRAW);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(glm::vec2), (void*) 0);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);
}

Mesh::Mesh(GLfloat bufferSize, GLuint coordinateLength, GLenum type, GLsizei stride, const void* offset) {
    verticesCount = sizeof(bufferSize) / sizeof(type);

    vao = new VAO();
    glBindVertexArray(vao->GetId());

    vbo1 = new VBO();
    glBindBuffer(GL_ARRAY_BUFFER, vbo1->GetId());
    glBufferData(GL_ARRAY_BUFFER, bufferSize, NULL, GL_DYNAMIC_DRAW);
    glVertexAttribPointer(0, coordinateLength, type, GL_FALSE, stride, offset);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);
}

VAO* Mesh::GetVao() {
    return vao;
}

VBO* Mesh::GetVbo1() {
    return vbo1;
}

VBO* Mesh::GetVbo2() {
    return vbo2;
}

VBO* Mesh::GetVbo3() {
    return vbo3;
}

GLsizei Mesh::GetIndicesCount() {
    return indicesCount;
}

GLsizei Mesh::GetVerticesCount() {
    return verticesCount;
}

Mesh::~Mesh() {
    delete vao;
    delete vbo1;
    delete vbo2;
    delete vbo3;
    delete ebo;
}
