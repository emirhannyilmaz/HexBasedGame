#include "Sawmill.h"

Sawmill::Sawmill(Model* model, glm::vec3 position, float rotationInDegrees, glm::vec3 rotationAxis, glm::vec3 scale) : Entity(model, position, rotationInDegrees, rotationAxis, scale), ResourceGenerator(WOOD) {

}