#include "Collider.h"

std::vector<glm::vec3> Collider::GetVertices() {
    return vertices;
}

void Collider::AddVertex(glm::vec3 vertex) {
    vertices.push_back(vertex);
}

void Collider::TransformVertex(int location, glm::vec3 vertex) {
    vertices.at(location) = vertex;
}
