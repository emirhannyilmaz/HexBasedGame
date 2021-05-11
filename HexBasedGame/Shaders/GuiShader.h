#pragma once

#include "ShaderProgram.h"
#include <glm/glm.hpp>

class GuiShader : public ShaderProgram {
public:
	GuiShader(const char* vertexShaderPath, const char* fragmentShaderPath);
	void LoadModelMatrix(glm::mat4 matrix);
	void LoadIsHighlighted(bool value);
private:
	GLint modelLoc;
	GLint isHighlightedLoc;
};