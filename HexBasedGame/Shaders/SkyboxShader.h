#pragma once

#include "ShaderProgram.h"

class SkyboxShader : public ShaderProgram {
public:
	SkyboxShader(std::string vertexShaderPath, std::string fragmentShaderPath);
	void LoadViewMatrix(glm::mat4 matrix);
	void LoadProjectionMatrix(glm::mat4 matrix);
private:
	GLint viewLoc;
	GLint projectionLoc;
};