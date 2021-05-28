#pragma once

#include <iostream>
#include "ShaderProgram.h"
#include "../Entities/Light.h"
#include <vector>

class WaterShader : public ShaderProgram {
public:
    WaterShader(const char* vertexShaderPath, const char* fragmentShaderPath);
    void LoadModelMatrix(glm::mat4 matrix);
    void LoadViewMatrix(glm::mat4 matrix, glm::vec3 cameraPosition);
    void LoadProjectionMatrix(glm::mat4 matrix, float near, float far);
    void ConnectTextureUnits();
    void LoadMoveFactor(float factor);
    void LoadLights(std::vector<Light*> lights);
private:
    static const int MAX_LIGHTS = 4;
    GLint modelLoc;
    GLint viewLoc;
    GLint projectionLoc;
    GLint reflectionTextureLoc;
    GLint refractionTextureLoc;
    GLint dudvMapLoc;
    GLint moveFactorLoc;
    GLint cameraPositionLoc;
    GLint normalMapLoc;
    GLint lightPositionLoc[MAX_LIGHTS];
    GLint lightColorLoc[MAX_LIGHTS];
    GLint attenuationLoc[MAX_LIGHTS];
    GLint depthMapLoc;
    GLint nearLoc;
    GLint farLoc;
};