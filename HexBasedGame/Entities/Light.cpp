#include "Light.h"

Light::Light(glm::vec3 _position, glm::vec3 _color, glm::vec3 _attenuation) {
    position = _position;
    color = _color;
    attenuation = _attenuation;
}

glm::vec3 Light::GetPosition() {
    return position;
}

void Light::SetPosition(glm::vec3 _position) {
    position = _position;
}

glm::vec3 Light::GetColor() {
    return color;
}

glm::vec3 Light::GetAttenuation() {
    return attenuation;
}