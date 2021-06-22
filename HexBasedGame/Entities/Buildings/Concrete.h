#pragma once

#include "../Entity.h"

class Concrete : public Entity {
public:
	Concrete(Model* model, glm::vec3 position, float rotationInDegrees, glm::vec3 rotationAxis, glm::vec3 scale);
};