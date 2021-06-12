#include "WaterShader.h"

WaterShader::WaterShader(const char* vertexShaderPath, const char* fragmentShaderPath) : ShaderProgram(vertexShaderPath, fragmentShaderPath) {
	modelLoc = GetUniformLocation("model");
	viewLoc = GetUniformLocation("view");
	projectionLoc = GetUniformLocation("projection");
	reflectionTextureLoc = GetUniformLocation("reflectionTexture");
	refractionTextureLoc = GetUniformLocation("refractionTexture");
	dudvMapLoc = GetUniformLocation("dudvMap");
	moveFactorLoc = GetUniformLocation("moveFactor");
	cameraPositionLoc = GetUniformLocation("cameraPosition");
	normalMapLoc = GetUniformLocation("normalMap");
	depthMapLoc = GetUniformLocation("depthMap");
	nearLoc = GetUniformLocation("near");
	farLoc = GetUniformLocation("far");
	fogDensityLoc = GetUniformLocation("fogDensity");
	fogGradientLoc = GetUniformLocation("fogGradient");
	skyColorLoc = GetUniformLocation("skyColor");

	for (int i = 0; i < MAX_LIGHTS; i++) {
		lightPositionLoc[i] = GetUniformLocation("lightPosition[" + std::to_string(i) + "]");
		lightColorLoc[i] = GetUniformLocation("lightColor[" + std::to_string(i) + "]");
		attenuationLoc[i] = GetUniformLocation("attenuation[" + std::to_string(i) + "]");
	}
}

void WaterShader::LoadModelMatrix(glm::mat4 matrix) {
	LoadMatrix4f(modelLoc, matrix);
}

void WaterShader::LoadViewMatrix(glm::mat4 matrix, glm::vec3 cameraPosition) {
	LoadMatrix4f(viewLoc, matrix);
	LoadVector3f(cameraPositionLoc, cameraPosition);
}

void WaterShader::LoadProjectionMatrix(glm::mat4 matrix, float near, float far) {
	LoadMatrix4f(projectionLoc, matrix);
	LoadFloat(nearLoc, near);
	LoadFloat(farLoc, far);
}

void WaterShader::ConnectTextureUnits() {
	LoadInt(reflectionTextureLoc, 0);
	LoadInt(refractionTextureLoc, 1);
	LoadInt(dudvMapLoc, 2);
	LoadInt(normalMapLoc, 3);
	LoadInt(depthMapLoc, 4);
}

void WaterShader::LoadMoveFactor(float factor) {
	LoadFloat(moveFactorLoc, factor);
}

void WaterShader::LoadLights(std::vector<Light*> lights) {
	for (int i = 0; i < MAX_LIGHTS; i++) {
		if (i < lights.size()) 	{
			LoadVector3f(lightPositionLoc[i], lights[i]->GetPosition());
			LoadVector3f(lightColorLoc[i], lights[i]->GetColor());
			LoadVector3f(attenuationLoc[i], lights[i]->GetAttenuation());
		} else {
			LoadVector3f(lightPositionLoc[i], glm::vec3(0.0f, 0.0f, 0.0f));
			LoadVector3f(lightColorLoc[i], glm::vec3(0.0f, 0.0f, 0.0f));
			LoadVector3f(attenuationLoc[i], glm::vec3(1.0f, 0.0f, 0.0f));
		}
	}
}

void WaterShader::LoadFogDensity(float density) {
	LoadFloat(fogDensityLoc, density);
}

void WaterShader::LoadFogGradient(float gradient) {
	LoadFloat(fogGradientLoc, gradient);
}

void WaterShader::LoadSkyColor(glm::vec3 color) {
	LoadVector3f(skyColorLoc, color);
}