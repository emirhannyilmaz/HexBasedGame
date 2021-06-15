#pragma once

#include "../Entity.h"
#include "../../Renderer/EntityRenderer/ObjLoader.h"
#include "../ResourceGenerator.h"
#include "../Light.h"

class House : public Entity, public ResourceGenerator {
public:
	House(Model* model, std::vector<Light> lights, glm::vec3 position, float rotationInDegrees, glm::vec3 rotationAxis, glm::vec3 scale);
};