#include "Entity.h"

Entity::Entity(Model* _model, std::vector<Collider> _colliders, glm::vec3 _position, float _rotationInDegrees, glm::vec3 _rotationAxis, glm::vec3 _scale, std::string _name) {
	model = _model;
	colliders = _colliders;
	position = _position;
	rotationInDegrees = _rotationInDegrees;
	rotationAxis = _rotationAxis;
	scale = _scale;
	name = _name;
	for (int i = 0; i < colliders.size(); i++) {
		for (int j = 0; j < colliders.at(i).GetVertices().size(); j++) {
			glm::vec4 vertexPosition = glm::vec4(colliders.at(i).GetVertices().at(j).x, colliders.at(i).GetVertices().at(j).y, colliders.at(i).GetVertices().at(j).z, 1.0f);
			glm::vec4 result = GetModelMatrix() * vertexPosition;
			glm::vec3 resultInVec3 = glm::vec3(result.x, result.y, result.z);
			colliders.at(i).TransformVertex(j, resultInVec3);
		}
	}
}

Entity::Entity(Model* _model, std::vector<Light> _lights, glm::vec3 _position, float _rotationInDegrees, glm::vec3 _rotationAxis, glm::vec3 _scale, std::string _name) {
	model = _model;
	lights = _lights;
	position = _position;
	rotationInDegrees = _rotationInDegrees;
	rotationAxis = _rotationAxis;
	scale = _scale;
	name = _name;
	for (int i = 0; i < lights.size(); i++) {
		glm::vec4 lightPosition = glm::vec4(lights.at(i).GetPosition().x, lights.at(i).GetPosition().y, lights.at(i).GetPosition().z, 1.0f);
		glm::vec4 result = GetModelMatrix() * lightPosition;
		glm::vec3 resultInVec3 = glm::vec3(result.x, result.y, result.z);
		lights.at(i).SetPosition(resultInVec3);
	}
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

std::vector<Light> Entity::GetLights() {
	return lights;
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

void Entity::SetIsHighlighted(bool value) {
	isHighlighted = value;
}

bool Entity::GetIsSelected() {
	return isSelected;
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

void Entity::SetName(std::string _name) {
	name = _name;
}