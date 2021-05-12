#include "GuiTexture.h"

GuiTexture::GuiTexture(const char* texturePath, GLint format, GLenum sourceFormat, GLenum type, glm::vec2 positionInPixels, float _rotationInDegrees, glm::vec3 _rotationAxis, glm::vec2 scaleInPixels, bool _isActive) {
	texture = new Texture(texturePath, format, sourceFormat, type, false, false);
	position = glm::vec2((2.0f * positionInPixels.x) / Window::GetWidth() - 1.0f, (2.0f * positionInPixels.y) / Window::GetHeight() - 1.0f);
	rotationInDegrees = _rotationInDegrees;
	rotationAxis = _rotationAxis;
	scale = glm::vec2(scaleInPixels.x / Window::GetWidth(), scaleInPixels.y / Window::GetHeight());
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