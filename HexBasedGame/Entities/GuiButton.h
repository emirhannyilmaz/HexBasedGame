#pragma once

#include <GL/glew.h>
#include "../IO/Window.h"
#include "../Objects/Texture.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "../IO/Mouse.h"

class GuiButton {
public:
	GuiButton(const char* texturePath, GLint format, GLenum sourceFormat, GLenum type, glm::vec2 _position, float _rotationInDegrees, glm::vec3 _rotationAxis, float scaleXInPixels, float scaleYInPixels, bool _isActive, void(*clickCallback)());
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
	float rotationInDegrees;
	glm::vec3 rotationAxis;
	glm::vec2 scale;
	glm::mat4 modelMatrix;
	glm::mat4 identityMatrix = glm::mat4(1.0f);
	bool isActive;
	void(*ClickCallback)();
	bool isHighlighted = false;
};