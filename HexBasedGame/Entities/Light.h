#pragma once

#include <iostream>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

class Light {
public:
    Light(glm::vec3 _position, glm::vec3 _color);
    glm::vec3 GetPosition();
    glm::vec3 GetColor();
private:
    glm::vec3 position;
    glm::vec3 color;
};