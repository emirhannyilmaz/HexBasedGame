#include "Apartment.h"

Apartment::Apartment(Model* model, std::vector<Light> lights, glm::vec3 position, float rotationInDegrees, glm::vec3 rotationAxis, glm::vec3 scale, int price) : Entity(model, lights, position, rotationInDegrees, rotationAxis, scale), SaleableProperty(price) {

}