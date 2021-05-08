#pragma once

#include <iostream>
#include <glm/glm.hpp>
#include <vector>

class Collision {
public:
    static bool IsPointInsideBox(glm::vec3 point, std::vector<glm::vec3> boxVertices);
};