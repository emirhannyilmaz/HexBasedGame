#include "Collision.h"

bool Collision::IsPointInsideBox(glm::vec3 point, std::vector<glm::vec3> boxVertices) {
    if (point.x < boxVertices.at(4).x && point.x > boxVertices.at(0).x &&
        point.y > boxVertices.at(0).y && point.y < boxVertices.at(1).y &&
        point.z < boxVertices.at(4).z && point.z > boxVertices.at(7).z) {
        return true;
    }

    return false;
}
