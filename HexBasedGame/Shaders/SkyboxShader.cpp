#include "SkyboxShader.h"

SkyboxShader::SkyboxShader(std::string vertexShaderPath, std::string fragmentShaderPath) : ShaderProgram(vertexShaderPath, fragmentShaderPath) {
	viewLoc = GetUniformLocation("view");
	projectionLoc = GetUniformLocation("projection");
}

void SkyboxShader::LoadViewMatrix(glm::mat4 matrix) {
	matrix[3][0] = 0.0f;
	matrix[3][1] = 0.0f;
	matrix[3][2] = 0.0f;
	LoadMatrix4f(viewLoc, matrix);
}

void SkyboxShader::LoadProjectionMatrix(glm::mat4 matrix) {
	LoadMatrix4f(projectionLoc, matrix);
}