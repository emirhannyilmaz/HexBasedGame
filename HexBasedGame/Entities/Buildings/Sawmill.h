#pragma once

#include <iostream>
#include "../Entity.h"
#include "../ResourceGenerator.h"

class Sawmill : public Entity, public ResourceGenerator {
public:
	Sawmill(Model* model, glm::vec3 position, float rotationInDegrees, glm::vec3 rotationAxis, glm::vec3 scale);
};