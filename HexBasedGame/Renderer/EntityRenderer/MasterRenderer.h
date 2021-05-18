#pragma once

#include <iostream>
#include "../../Shaders/StaticShader.h"
#include "Renderer.h"
#include "../../Entities/Camera.h"
#include "../../Entities/Light.h"
#include "../../Entities/Entity.h"
#include <map>
#include <glm/glm.hpp>

class MasterRenderer {
public:
    MasterRenderer(Camera* _camera, Light* _light, glm::vec3 _skyColor, float fogDensity, float fogGradient);
    std::map<Model*, std::vector<Entity*>> entities;
    void Clear();
    void ProcessEntity(Entity* entity);
    void Render(glm::vec4 clipPlane);
    void RenderScene(std::vector<Entity*> entities, glm::vec4 clipPlane);
private:
    Camera* camera = NULL;
    Light* light = NULL;
    StaticShader staticShader = StaticShader("Resources/Shaders/vertex.glsl", "Resources/Shaders/fragment.glsl");
    Renderer renderer = Renderer(&staticShader);
    glm::vec3 skyColor;
};