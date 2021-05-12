#pragma once

#include <GL/glew.h>
#include "../IO/Window.h"
#include "../Objects/Texture.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "../IO/Mouse.h"

class GuiButton {
public:
	GuiButton(const char* texturePath, GLint format, GLenum sourceFormat, GLenum type, glm::vec2 _positionInPixels, float _rotationInDegrees, glm::vec3 _rotationAxis, glm::vec2 _scaleInPixels, bool _isActive, void(*_ClickCallback)());
	Texture* GetTexture();
	glm::mat4 GetModelMatrix();
	bool GetIsActive();
	void SetIsActive(bool value);
	void HandleMouse();
	bool GetIsHighlighted();
	~GuiButton();
private:
	Texture* texture = NULL;
	glm::vec2 position;
	glm::vec2 positionInPixels;
	float rotationInDegrees;
	glm::vec3 rotationAxis;
	glm::vec2 scale;
	glm::vec2 scaleInPixels;
	glm::mat4 modelMatrix;
	glm::mat4 identityMatrix = glm::mat4(1.0f);
	bool isActive;
	void(*ClickCallback)();
	bool isHighlighted = false;
};