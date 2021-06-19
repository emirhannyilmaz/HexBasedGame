#pragma once

#include <iostream>
#include "../IO/Mouse.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "../IO/Window.h"

class Camera {
public:
    Camera(float fov, int width, int height, float _near, float _far, glm::vec3 _position, float _pitch, float _yaw, float _roll, float _distance, float _minDistance, float _maxDistance, float _angleAround);
    glm::mat4 GetViewMatrix();
    glm::mat4 GetProjectionMatrix();
    float GetNear();
    float GetFar();
    void HandleInput();
    glm::vec3 GetPosition();
    void SetPosition(glm::vec3 _position);
    void InvertPitch();
private:
    glm::vec3 position;
    glm::vec3 direction;
    glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
    glm::vec3 right;
    float pitch;
    float yaw;
    float roll;
    float distance;
    float minDistance;
    float maxDistance;
    float angleAround;
    glm::mat4 view;
    glm::mat4 projection;
    glm::mat4 identity = glm::mat4(1.0f);
    float near;
    float far;
};