#pragma once

#include <iostream>
#include "ShaderProgram.h"
#include "../Entities/Light.h"
#include <vector>

class StaticShader : public ShaderProgram {
public:
    StaticShader(const char* vertexShaderPath, const char* fragmentShaderPath);
    void LoadModelMatrix(glm::mat4 matrix);
    void LoadViewMatrix(glm::mat4 matrix);
    void LoadProjectionMatrix(glm::mat4 matrix);
    void LoadLights(std::vector<Light*> lights);
    void LoadShineVariables(float shineDamper, float reflectivity);
    void LoadIsHighlighted(bool value);
    void LoadIsSelected(bool value);
    void LoadSkyColor(glm::vec3 color);
    void LoadFogDensity(float density);
    void LoadFogGradient(float gradient);
    void LoadClipPlane(glm::vec4 clipPlane);
private:
    static const int MAX_LIGHTS = 11;
    GLint modelLoc;
    GLint viewLoc;
    GLint projectionLoc;
    GLint lightPositionLoc[MAX_LIGHTS];
    GLint lightColorLoc[MAX_LIGHTS];
    GLint attenuationLoc[MAX_LIGHTS];
    GLint shineDamperLoc;
    GLint reflectivityLoc;
    GLint isHighlightedLoc;
    GLint isSelectedLoc;
    GLint skyColorLoc;
    GLint fogDensityLoc;
    GLint fogGradientLoc;
    GLint clipPlaneLoc;
    GLint numberOfLightsLoc;
};
