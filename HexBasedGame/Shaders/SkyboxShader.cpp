#include "SkyboxShader.h"

SkyboxShader::SkyboxShader(std::string vertexShaderPath, std::string fragmentShaderPath) : ShaderProgram(vertexShaderPath, fragmentShaderPath) {
	viewLoc = GetUniformLocation("view");
	projectionLoc = GetUniformLocation("projection");
	fogColorLoc = GetUniformLocation("fogColor");
	cubeMapLoc = GetUniformLocation("cubeMap");
	cubeMap2Loc = GetUniformLocation("cubeMap2");
	blendFactorLoc = GetUniformLocation("blendFactor");
}

void SkyboxShader::LoadViewMatrix(glm::mat4 matrix) {
	matrix[3][0] = 0.0f;
	matrix[3][1] = 0.0f;
	matrix[3][2] = 0.0f;
	rotation += ROTATION_SPEED * Window::GetDeltaTime();
	matrix = glm::rotate(matrix, glm::radians(rotation), glm::vec3(0.0f, 1.0f, 0.0f));
	LoadMatrix4f(viewLoc, matrix);
}

void SkyboxShader::LoadProjectionMatrix(glm::mat4 matrix) {
	LoadMatrix4f(projectionLoc, matrix);
}

void SkyboxShader::LoadFogColor(glm::vec3 color) {
	LoadVector3f(fogColorLoc, color);
}

void SkyboxShader::ConnectTextureUnits() {
	LoadInt(cubeMapLoc, 0);
	LoadInt(cubeMap2Loc, 1);
}

void SkyboxShader::LoadBlendFactor(float blendFactor) {
	LoadFloat(blendFactorLoc, blendFactor);
}