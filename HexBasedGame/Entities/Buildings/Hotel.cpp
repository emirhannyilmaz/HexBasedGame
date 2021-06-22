#include "Hotel.h"

Hotel::Hotel(Model* model, std::vector<Light> lights, glm::vec3 position, float rotationInDegrees, glm::vec3 rotationAxis, glm::vec3 scale, int income, int expense) : Entity(model, lights, position, rotationInDegrees, rotationAxis, scale), Property(income, expense) {

}