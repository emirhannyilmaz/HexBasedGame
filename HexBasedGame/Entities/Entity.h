#pragma once

#include <iostream>
#include "../Models/Model.h"
#include <vector>
#include "../Physics/Collider.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Entity {
public:
    Entity(Model* _model, std::vector<Collider> _colliders, glm::vec3 _position, float _rotationInDegrees, glm::vec3 _rotationAxis, glm::vec3 _scale, std::string _hexName = "Empty");
    Entity(Model* _model, glm::vec3 _position, float _rotationInDegrees, glm::vec3 _rotationAxis, glm::vec3 _scale, std::string _hexName = "Empty");
    glm::mat4 GetModelMatrix();
    Model* GetModel();
    std::vector<Collider> GetColliders();
    glm::vec3 GetPosition();
    void SetPosition(glm::vec3 _position);
    bool GetIsHighlighted();
    bool GetIsSelected();
    void SetIsHighlighted(bool value);
    void SetIsSelected(bool value);
    std::string GetName();
    void SetName(std::string _name);
private:
    Model* model = NULL;
    std::vector<Collider> colliders;
    glm::vec3 position;
    float rotationInDegrees;
    glm::vec3 rotationAxis;
    glm::vec3 scale;
    glm::mat4 modelMatrix;
    glm::mat4 identityMatrix = glm::mat4(1.0f);
    bool isHighlighted = false;
    bool isSelected = false;
    std::string name;
};