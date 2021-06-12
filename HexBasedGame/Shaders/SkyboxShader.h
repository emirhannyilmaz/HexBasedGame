#pragma once

#include "ShaderProgram.h"
#include "../IO/Window.h"

class SkyboxShader : public ShaderProgram {
public:
	SkyboxShader(std::string vertexShaderPath, std::string fragmentShaderPath);
	void LoadViewMatrix(glm::mat4 matrix);
	void LoadProjectionMatrix(glm::mat4 matrix);
	void LoadFogColor(glm::vec3 color);
	void ConnectTextureUnits();
	void LoadBlendFactor(float blendFactor);
private:
	GLint viewLoc;
	GLint projectionLoc;
	GLint fogColorLoc;
	GLint cubeMapLoc;
	GLint cubeMap2Loc;
	GLint blendFactorLoc;
	const float ROTATION_SPEED = 1.0f;
	float rotation = 0.0f;
};