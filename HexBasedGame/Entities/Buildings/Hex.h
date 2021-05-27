#pragma once

#include "../Entity.h"

class Hex : public Entity {
public:
	Hex(Model* model, std::vector<Collider> _colliders, glm::vec3 position, float rotationInDegrees, glm::vec3 rotationAxis, glm::vec3 scale, std::string name);
};