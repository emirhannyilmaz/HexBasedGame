#pragma once

#include <iostream>
#include "ShaderProgram.h"
#include "../Entities/Light.h"

class WaterShader : public ShaderProgram {
public:
    WaterShader(const char* vertexShaderPath, const char* fragmentShaderPath);
    void LoadModelMatrix(glm::mat4 matrix);
    void LoadViewMatrix(glm::mat4 matrix, glm::vec3 cameraPosition);
    void LoadProjectionMatrix(glm::mat4 matrix);
    void ConnectTextureUnits();
    void LoadMoveFactor(float factor);
    void LoadLight(Light* light);
private:
    GLint modelLoc;
    GLint viewLoc;
    GLint projectionLoc;
    GLint reflectionTextureLoc;
    GLint refractionTextureLoc;
    GLint dudvMapLoc;
    GLint moveFactorLoc;
    GLint cameraPositionLoc;
    GLint normalMapLoc;
    GLint lightPositionLoc;
    GLint lightColorLoc;
};