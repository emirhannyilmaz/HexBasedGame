#include "WaterTile.h"

float WaterTile::TILE_SIZE = 200.0f;

WaterTile::WaterTile(float _x, float _z, float _height) {
    x = _x;
    z = _z;
    height = _height;
}

float WaterTile::GetX() {
    return x;
}

float WaterTile::GetZ() {
    return z;
}

float WaterTile::GetHeight() {
    return height;
}

glm::mat4 WaterTile::GetModelMatrix() {
    modelMatrix = glm::translate(identityMatrix, glm::vec3(x, height, z));
    modelMatrix = glm::scale(modelMatrix, glm::vec3(WaterTile::TILE_SIZE, WaterTile::TILE_SIZE, WaterTile::TILE_SIZE));

    return modelMatrix;
}
