#pragma once

#include <iostream>
#include "../Objects/VAO.h"
#include "../Objects/VBO.h"
#include "../Objects/EBO.h"
#include <glm/glm.hpp>
#include <vector>

class Mesh {
public:
    Mesh(std::vector<glm::vec3> vertices, std::vector<glm::vec2> texCoords, std::vector<glm::vec3> normals, std::vector<GLuint> indices);
    Mesh(std::vector<glm::vec3> vertices);
    Mesh(std::vector<glm::vec2> vertices);
    VAO* GetVao();
    GLsizei GetIndicesCount();
    GLsizei GetVerticesCount();
    ~Mesh();
private:
    VAO* vao = NULL;
    VBO* vbo1 = NULL;
    VBO* vbo2 = NULL;
    VBO* vbo3 = NULL;
    EBO* ebo = NULL;
    GLsizei indicesCount;
    GLsizei verticesCount;
};