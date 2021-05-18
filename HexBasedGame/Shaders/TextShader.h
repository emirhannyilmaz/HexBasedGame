#pragma once

#include <iostream>
#include "ShaderProgram.h"
#include <glm/glm.hpp>

class TextShader : public ShaderProgram {
public:
	TextShader(const char* vertexShaderPath, const char* fragmentShaderPath);
	void LoadProjectionMatrix(glm::mat4 matrix);
	void LoadTextColor(glm::vec3 color);
private:
	GLint projectionLoc;
	GLint textColorLoc;
};