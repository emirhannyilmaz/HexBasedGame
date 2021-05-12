#include "GuiButton.h"

GuiButton::GuiButton(const char* texturePath, GLint format, GLenum sourceFormat, GLenum type, glm::vec2 _positionInPixels, float _rotationInDegrees, glm::vec3 _rotationAxis, glm::vec2 _scaleInPixels, bool _isActive, void(*_ClickCallback)()) {
	texture = new Texture(texturePath, format, sourceFormat, type, false, false);
	position = glm::vec2((2.0f * _positionInPixels.x) / Window::GetWidth() - 1.0f, (2.0f * _positionInPixels.y) / Window::GetHeight() - 1.0f);
	positionInPixels = _positionInPixels;
	rotationInDegrees = _rotationInDegrees;
	rotationAxis = _rotationAxis;
	scale = glm::vec2(_scaleInPixels.x / Window::GetWidth(), _scaleInPixels.y / Window::GetHeight());
	scaleInPixels = _scaleInPixels;
	isActive = _isActive;
	ClickCallback = _ClickCallback;
}

Texture* GuiButton::GetTexture() {
	return texture;
}

glm::mat4 GuiButton::GetModelMatrix() {
	modelMatrix = glm::translate(identityMatrix, glm::vec3(position.x, position.y, 0.0f));
	if (rotationAxis != glm::vec3(0.0f, 0.0f, 0.0f)) {
		modelMatrix = glm::rotate(modelMatrix, glm::radians(rotationInDegrees), rotationAxis);
	}
	modelMatrix = glm::scale(modelMatrix, glm::vec3(scale.x, scale.y, 0.0f));

	return modelMatrix;
}

bool GuiButton::GetIsActive() {
	return isActive;
}

void GuiButton::SetIsActive(bool value) {
	isActive = value;
}

void GuiButton::HandleMouse() {
	if (Mouse::GetX() >= (positionInPixels.x - (scaleInPixels.x / 2)) && Mouse::GetX() <= (positionInPixels.x + (scaleInPixels.x / 2)) &&
		Mouse::GetY() >= (positionInPixels.y - (scaleInPixels.y / 2)) && Mouse::GetY() <= (positionInPixels.y + (scaleInPixels.y / 2))) {
		isHighlighted = true;
		if (Mouse::GetMouseButtonDown(0)) {
			ClickCallback();
		}
	} else {
		isHighlighted = false;
	}
}

bool GuiButton::GetIsHighlighted() {
	return isHighlighted;
}

GuiButton::~GuiButton() {
	delete texture;
}