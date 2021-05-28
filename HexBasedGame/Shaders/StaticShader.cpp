#include "StaticShader.h"

StaticShader::StaticShader(const char* vertexShaderPath, const char* fragmentShaderPath) : ShaderProgram(vertexShaderPath, fragmentShaderPath) {
	modelLoc = GetUniformLocation("model");
	viewLoc = GetUniformLocation("view");
	projectionLoc = GetUniformLocation("projection");
	shineDamperLoc = GetUniformLocation("shineDamper");
	reflectivityLoc = GetUniformLocation("reflectivity");
	isHighlightedLoc = GetUniformLocation("isHighlighted");
	isSelectedLoc = GetUniformLocation("isSelected");
	skyColorLoc = GetUniformLocation("skyColor");
	fogDensityLoc = GetUniformLocation("fogDensity");
	fogGradientLoc = GetUniformLocation("fogGradient");
	clipPlaneLoc = GetUniformLocation("clipPlane");

	for (int i = 0; i < MAX_LIGHTS; i++) {
		lightPositionLoc[i] = GetUniformLocation("lightPosition[" + std::to_string(i) + "]");
		lightColorLoc[i] = GetUniformLocation("lightColor[" + std::to_string(i) + "]");
		attenuationLoc[i] = GetUniformLocation("attenuation[" + std::to_string(i) + "]");
	}
}

void StaticShader::LoadModelMatrix(glm::mat4 matrix) {
	LoadMatrix4f(modelLoc, matrix);
}

void StaticShader::LoadViewMatrix(glm::mat4 matrix) {
	LoadMatrix4f(viewLoc, matrix);
}

void StaticShader::LoadProjectionMatrix(glm::mat4 matrix) {
	LoadMatrix4f(projectionLoc, matrix);
}

void StaticShader::LoadLights(std::vector<Light*> lights) {
	for (int i = 0; i < MAX_LIGHTS; i++) {
		if (i < lights.size()) 	{
			LoadVector3f(lightPositionLoc[i], lights.at(i)->GetPosition());
			LoadVector3f(lightColorLoc[i], lights.at(i)->GetColor());
			LoadVector3f(attenuationLoc[i], lights.at(i)->GetAttenuation());
		} else {
			LoadVector3f(lightPositionLoc[i], glm::vec3(0.0f, 0.0f, 0.0f));
			LoadVector3f(lightColorLoc[i], glm::vec3(0.0f, 0.0f, 0.0f));
			LoadVector3f(attenuationLoc[i], glm::vec3(1.0f, 0.0f, 0.0f));
		}
	}
}

void StaticShader::LoadShineVariables(float shineDamper, float reflectivity) {
	LoadFloat(shineDamperLoc, shineDamper);
	LoadFloat(reflectivityLoc, reflectivity);
}

void StaticShader::LoadIsHighlighted(bool value) {
	LoadBoolean(isHighlightedLoc, value);
}

void StaticShader::LoadIsSelected(bool value) {
	LoadBoolean(isSelectedLoc, value);
}

void StaticShader::LoadSkyColor(glm::vec3 color) {
	LoadVector3f(skyColorLoc, color);
}

void StaticShader::LoadFogDensity(float density) {
	LoadFloat(fogDensityLoc, density);
}

void StaticShader::LoadFogGradient(float gradient) {
	LoadFloat(fogGradientLoc, gradient);
}

void StaticShader::LoadClipPlane(glm::vec4 clipPlane) {
	LoadVector4f(clipPlaneLoc, clipPlane);
}
