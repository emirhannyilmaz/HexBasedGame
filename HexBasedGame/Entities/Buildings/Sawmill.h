#pragma once

#include <iostream>
#include "../Entity.h"
#include "../ResourceGenerator.h"
#include "../Light.h"

class Sawmill : public Entity, public ResourceGenerator {
public:
	Sawmill(Model* model, std::vector<Light> lights, glm::vec3 position, float rotationInDegrees, glm::vec3 rotationAxis, glm::vec3 scale);
};