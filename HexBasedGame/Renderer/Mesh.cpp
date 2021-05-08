#include "Mesh.h"

Mesh::Mesh(std::vector<glm::vec3> vertices, std::vector<glm::vec2> texCoords, std::vector<glm::vec3> normals, std::vector<GLuint> indices) {

    indicesCount = indices.size();

    vao = new VAO();
    vao->Bind();

    vbo1 = new VBO();
    vbo1->Bind();
    vbo1->StoreData(sizeof(glm::vec3) * vertices.size(), &vertices[0]);
    vao->StoreDataInAttributeList(0, 3, sizeof(glm::vec3), (void*) 0);
    vbo1->Unbind();

    vbo2 = new VBO();
    vbo2->Bind();
    vbo2->StoreData(sizeof(glm::vec2) * texCoords.size(), &texCoords[0]);
    vao->StoreDataInAttributeList(1, 2, sizeof(glm::vec2), (void*) 0);
    vbo2->Unbind();

    vbo3 = new VBO();
    vbo3->Bind();
    vbo3->StoreData(sizeof(glm::vec3) * normals.size(), &normals[0]);
    vao->StoreDataInAttributeList(2, 3, sizeof(glm::vec3), (void*) 0);
    vbo3->Unbind();

    ebo = new EBO();
    ebo->Bind();
    ebo->StoreData(sizeof(GLuint) * indices.size(), &indices[0]);

    vao->Unbind();
    ebo->Unbind();
}

Mesh::Mesh(std::vector<glm::vec3> vertices) {
    verticesCount = vertices.size();

    vao = new VAO();
    vao->Bind();

    vbo1 = new VBO();
    vbo1->Bind();
    vbo1->StoreData(sizeof(glm::vec3) * vertices.size(), &vertices[0]);
    vao->StoreDataInAttributeList(0, 3, sizeof(glm::vec3), (void*) 0);
    vbo1->Unbind();

    vao->Unbind();
}

Mesh::Mesh(std::vector<glm::vec2> vertices) {
    verticesCount = vertices.size();

    vao = new VAO();
    vao->Bind();
    
    vbo1 = new VBO();
    vbo1->Bind();
    vbo1->StoreData(sizeof(glm::vec2) * vertices.size(), &vertices[0]);
    vao->StoreDataInAttributeList(0, 2, sizeof(glm::vec2), (void*)0);
    vbo1->Unbind();

    vao->Unbind();
}

VAO* Mesh::GetVao() {
    return vao;
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
