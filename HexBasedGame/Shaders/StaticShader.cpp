#include "StaticShader.h"

StaticShader::StaticShader(const char* vertexShaderPath, const char* fragmentShaderPath) : ShaderProgram(vertexShaderPath, fragmentShaderPath) {
    modelLoc = GetUniformLocation("model");
    viewLoc = GetUniformLocation("view");
    projectionLoc = GetUniformLocation("projection");
    lightPositionLoc = GetUniformLocation("lightPosition");
    lightColorLoc = GetUniformLocation("lightColor");
    shineDamperLoc = GetUniformLocation("shineDamper");
    reflectivityLoc = GetUniformLocation("reflectivity");
    isHighlightedLoc = GetUniformLocation("isHighlighted");
    isSelectedLoc = GetUniformLocation("isSelected");
    skyColorLoc = GetUniformLocation("skyColor");
    fogDensityLoc = GetUniformLocation("fogDensity");
    fogGradientLoc = GetUniformLocation("fogGradient");
    clipPlaneLoc = GetUniformLocation("clipPlane");
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

void StaticShader::LoadLight(glm::vec3 position, glm::vec3 color) {
    LoadVector3f(lightPositionLoc, position);
    LoadVector3f(lightColorLoc, color);
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
