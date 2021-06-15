#pragma once

#include <iostream>
#include <GL/glew.h>
#include <string>
#include <fstream>
#include <vector>
#include <glm/glm.hpp>
#include "../../Physics/Collider.h"
#include "../../Entities/Light.h"

class ObjLoader {
public:
    static void LoadObj(const char* filePath, std::vector<glm::vec3>& outVertices, std::vector<glm::vec2>& outTexCoords, std::vector<glm::vec3>& outNormals, std::vector<GLuint>& outIndices, std::vector<Collider>& outColliders);
    static void LoadObj(const char* filePath, std::vector<glm::vec3>& outVertices, std::vector<glm::vec2>& outTexCoords, std::vector<glm::vec3>& outNormals, std::vector<GLuint>& outIndices, std::vector<Light>& outLights);
};