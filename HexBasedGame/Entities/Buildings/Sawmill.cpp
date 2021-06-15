#include "Sawmill.h"

Sawmill::Sawmill(Model* model, std::vector<Light> lights, glm::vec3 position, float rotationInDegrees, glm::vec3 rotationAxis, glm::vec3 scale) : Entity(model, lights, position, rotationInDegrees, rotationAxis, scale), ResourceGenerator(WOOD) {

}