#pragma once

#include "../Entity.h"
#include "../Property.h"

class Hotel : public Property, public Entity {
public:
	Hotel(Model* model, std::vector<Light> lights, glm::vec3 position, float rotationInDegrees, glm::vec3 rotationAxis, glm::vec3 scale, int income, int expense);
};