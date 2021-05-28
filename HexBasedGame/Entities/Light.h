#pragma once

#include <iostream>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

class Light {
public:
    Light(glm::vec3 _position, glm::vec3 _color, glm::vec3 _attenuation = glm::vec3(1.0f, 0.0f, 0.0f));
    glm::vec3 GetPosition();
    glm::vec3 GetColor();
    glm::vec3 GetAttenuation();
private:
    glm::vec3 position;
    glm::vec3 color;
    glm::vec3 attenuation;
};