#pragma once

#include <iostream>
#include <glm/glm.hpp>
#include "../Entities/Camera.h"
#include "../IO/Mouse.h"
#include "../IO/Window.h"
#include <vector>
#include "../Entities/Entity.h"
#include "Collision.h"
#include "../Entities/GuiTexture.h"

class Raycast {
private:
    float rayRange;
    int recursionCount;
    float hexHeight;
    glm::vec3 currentRay;
    glm::vec3 currentPoint;
    glm::mat4 projectionMatrix;
    glm::mat4 viewMatrix;
    Camera* camera;
public:
    Raycast(Camera* _camera, float _rayRange, int _recursionCount, float _hexHeight);
    glm::vec3 GetCurrentRay();
    glm::vec3 GetCurrentPoint();
    void Update();
    void CheckForCollisions(std::vector<Entity*> entities, GuiTexture* hexInfoTexture);
    glm::vec3 CalculateRay();
    glm::vec2 GetNormalizedDeviceCoords(float mouseX, float mouseY);
    glm::vec4 ToEyeCoords(glm::vec4 clipCoords);
    glm::vec3 ToWorldCoords(glm::vec4 eyeCoords);
    glm::vec3 GetPointOnRay(float distance);
    glm::vec3 BinarySearch(int count, float start, float finish);
    bool IntersectionInRange(float start, float finish);
    bool IsUnderGround(glm::vec3 testPoint);
};