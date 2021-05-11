#include "GuiTexture.h"

GuiTexture::GuiTexture(const char* texturePath, GLint format, GLenum sourceFormat, GLenum type, glm::vec2 _position, float _rotationInDegrees, glm::vec3 _rotationAxis, float scaleXInPixels, float scaleYInPixels, bool _isActive) {
	texture = new Texture(texturePath, format, sourceFormat, type, false, false);
	position = _position;
	rotationInDegrees = _rotationInDegrees;
	rotationAxis = _rotationAxis;
	scale = glm::vec2(scaleXInPixels / Window::GetWidth(), scaleYInPixels / Window::GetHeight());
	isActive = _isActive;
}

Texture* GuiTexture::GetTexture() {
	return texture;
}

glm::mat4 GuiTexture::GetModelMatrix() {
	modelMatrix = glm::translate(identityMatrix, glm::vec3(position.x, position.y, 0.0f));
	if (rotationAxis != glm::vec3(0.0f, 0.0f, 0.0f)) {
		modelMatrix = glm::rotate(modelMatrix, glm::radians(rotationInDegrees), rotationAxis);
	}
	modelMatrix = glm::scale(modelMatrix, glm::vec3(scale.x, scale.y, 0.0f));

	return modelMatrix;
}

bool GuiTexture::GetIsActive() {
	return isActive;
}

void GuiTexture::SetIsActive(bool value) {
	isActive = value;
}

GuiTexture::~GuiTexture() {
	delete texture;
}