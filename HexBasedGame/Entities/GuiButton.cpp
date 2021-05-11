#include "GuiButton.h"

GuiButton::GuiButton(const char* texturePath, GLint format, GLenum sourceFormat, GLenum type, glm::vec2 _position, float _rotationInDegrees, glm::vec3 _rotationAxis, float scaleXInPixels, float scaleYInPixels, bool _isActive, void(*_ClickCallback)()) {
	texture = new Texture(texturePath, format, sourceFormat, type, false, false);
	position = _position;
	rotationInDegrees = _rotationInDegrees;
	rotationAxis = _rotationAxis;
	scale = glm::vec2(scaleXInPixels / Window::GetWidth(), scaleYInPixels / Window::GetHeight());
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
	float normalizedMouseX = (2.0f * Mouse::GetX()) / Window::GetWidth() - 1.0f;
	float normalizedMouseY = (2.0f * Mouse::GetY()) / Window::GetHeight() - 1.0f;
	normalizedMouseY = -normalizedMouseY;

	if (normalizedMouseX >= (position.x - (scale.x / 2)) && normalizedMouseX <= (position.x + (scale.x / 2)) &&
		normalizedMouseY >= (position.y - (scale.y / 2)) && normalizedMouseY <= (position.y + (scale.y / 2))) {
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