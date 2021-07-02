#pragma once

#include "../Entity.h"
#include "../SaleableProperty.h"

class Apartment : public Entity, public SaleableProperty {
public:
	Apartment(Model* model, std::vector<Light> lights, glm::vec3 position, float rotationInDegrees, glm::vec3 rotationAxis, glm::vec3 scale, int price);
};