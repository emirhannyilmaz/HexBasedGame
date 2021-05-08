#include "Light.h"

Light::Light(glm::vec3 _position, glm::vec3 _color) {
    position = _position;
    color = _color;
}

glm::vec3 Light::GetPosition() {
    return position;
}

glm::vec3 Light::GetColor() {
    return color;
}
