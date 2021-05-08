#pragma once

#include <iostream>
#include <vector>
#include <glm/glm.hpp>

class Collider {
public:
    std::vector<glm::vec3> GetVertices();
    void AddVertex(glm::vec3 vertex);
    void TransformVertex(int location, glm::vec3 vertex);
private:
    std::vector<glm::vec3> vertices;
};