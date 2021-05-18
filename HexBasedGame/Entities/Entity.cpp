#include "Entity.h"

Entity::Entity(Model* _model, std::vector<Collider> _colliders, glm::vec3 _position, float _rotationInDegrees, glm::vec3 _rotationAxis, glm::vec3 _scale, std::string _hexName) {
	model = _model;
	colliders = _colliders;
	position = _position;
	rotationInDegrees = _rotationInDegrees;
	rotationAxis = _rotationAxis;
	scale = _scale;
	for (int i = 0; i < colliders.size(); i++) {
		for (int j = 0; j < colliders.at(i).GetVertices().size(); j++) {
			glm::vec4 vertexPosition = glm::vec4(colliders.at(i).GetVertices().at(j).x, colliders.at(i).GetVertices().at(j).y, colliders.at(i).GetVertices().at(j).z, 1.0f);
			glm::vec4 result = GetModelMatrix() * vertexPosition;
			glm::vec3 resultInVec3 = glm::vec3(result.x, result.y, result.z);
			colliders.at(i).TransformVertex(j, resultInVec3);
		}
	}
	name = _hexName;
}

Entity::Entity(Model* _model, glm::vec3 _position, float _rotationInDegrees, glm::vec3 _rotationAxis, glm::vec3 _scale, std::string _hexName) {
	model = _model;
	position = _position;
	rotationInDegrees = _rotationInDegrees;
	rotationAxis = _rotationAxis;
	scale = _scale;
	name = _hexName;
}

glm::mat4 Entity::GetModelMatrix() {
	modelMatrix = glm::translate(identityMatrix, position);
	if (rotationAxis != glm::vec3(0.0f, 0.0f, 0.0f)) {
		modelMatrix = glm::rotate(modelMatrix, glm::radians(rotationInDegrees), rotationAxis);
	}
	modelMatrix = glm::scale(modelMatrix, scale);

	return modelMatrix;
}

Model* Entity::GetModel() {
	return model;
}

std::vector<Collider> Entity::GetColliders() {
	return colliders;
}

glm::vec3 Entity::GetPosition() {
	return position;
}

void Entity::SetPosition(glm::vec3 _position) {
	position = _position;
}

bool Entity::GetIsHighlighted() {
	return isHighlighted;
}

bool Entity::GetIsSelected() {
	return isSelected;
}

void Entity::SetIsHighlighted(bool value) {
	isHighlighted = value;
}

void Entity::SetIsSelected(bool value) {
	isSelected = value;
	if (value) {
		isHighlighted = false;
	}
}

std::string Entity::GetName() {
	return name;
}

void Entity::SetName(std::string _hexName) {
	name = _hexName;
}