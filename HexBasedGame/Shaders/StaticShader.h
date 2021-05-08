#pragma once

#include <iostream>
#include "ShaderProgram.h"

class StaticShader : public ShaderProgram {
public:
    StaticShader(const char* vertexShaderPath, const char* fragmentShaderPath);
    void LoadModelMatrix(glm::mat4 matrix);
    void LoadViewMatrix(glm::mat4 matrix);
    void LoadProjectionMatrix(glm::mat4 matrix);
    void LoadLight(glm::vec3 position, glm::vec3 color);
    void LoadShineVariables(float shineDamper, float reflectivity);
    void LoadIsHighlighted(bool value);
    void LoadSkyColor(glm::vec3 color);
    void LoadFogDensity(float density);
    void LoadFogGradient(float gradient);
    void LoadClipPlane(glm::vec4 clipPlane);
private:
    GLint modelLoc;
    GLint viewLoc;
    GLint projectionLoc;
    GLint lightPositionLoc;
    GLint lightColorLoc;
    GLint shineDamperLoc;
    GLint reflectivityLoc;
    GLint isHighlightedLoc;
    GLint skyColorLoc;
    GLint fogDensityLoc;
    GLint fogGradientLoc;
    GLint clipPlaneLoc;
};
