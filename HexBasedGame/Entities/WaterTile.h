#pragma once

#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class WaterTile {
public:
    static float TILE_SIZE;
    WaterTile(float _x, float _z, float _height);
    float GetX();
    float GetZ();
    float GetHeight();
    glm::mat4 GetModelMatrix();
private:
    float x;
    float z;
    float height;
    glm::mat4 modelMatrix;
    glm::mat4 identityMatrix = glm::mat4(1.0f);
};