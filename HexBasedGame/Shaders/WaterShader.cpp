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
    lightPositionLoc = GetUniformLocation("lightPosition");
    lightColorLoc = GetUniformLocation("lightColor");
    depthMapLoc = GetUniformLocation("depthMap");
    nearLoc = GetUniformLocation("near");
    farLoc = GetUniformLocation("far");
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

void WaterShader::LoadLight(Light* light) {
    LoadVector3f(lightPositionLoc, light->GetPosition());
    LoadVector3f(lightColorLoc, light->GetColor());
}
