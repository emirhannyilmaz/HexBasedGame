#pragma once

#include "../Objects/Texture.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class GuiTexture {
public:
	GuiTexture(const char* texturePath, GLint format, GLenum sourceFormat, GLenum type, glm::vec2 _position, float _rotationInDegrees, glm::vec3 rotationAxis, glm::vec2 _scale);
	Texture* GetTexture();
	glm::mat4 GetModelMatrix();
	~GuiTexture();
private:
	Texture* texture = NULL;
	glm::vec2 position;
	float rotationInDegrees;
	glm::vec3 rotationAxis;
	glm::vec2 scale;
	glm::mat4 modelMatrix;
	glm::mat4 identityMatrix = glm::mat4(1.0f);
};