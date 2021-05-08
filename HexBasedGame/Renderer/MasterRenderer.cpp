#include "MasterRenderer.h"

MasterRenderer::MasterRenderer(Camera* _camera, Light* _light, glm::vec3 _skyColor, float fogDensity, float fogGradient) {
    //    glEnable(GL_CULL_FACE);
    //    glEnable(GL_BACK);
    glEnable(GL_DEPTH_TEST);
    camera = _camera;
    light = _light;
    skyColor = _skyColor;
    staticShader.Start();
    staticShader.LoadFogDensity(fogDensity);
    staticShader.LoadFogGradient(fogGradient);
    staticShader.LoadProjectionMatrix(camera->GetProjectionMatrix());
    staticShader.Stop();
}

void MasterRenderer::Clear() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(skyColor.r, skyColor.g, skyColor.b, 1.0f);
}

void MasterRenderer::ProcessEntity(Entity* entity) {
    if (entities.find(entity->GetModel()) != entities.end()) {
        entities.at(entity->GetModel()).push_back(entity);
    }
    else {
        std::vector<Entity*> newBatch;
        newBatch.push_back(entity);
        entities.insert({ entity->GetModel(), newBatch });
    }
}

void MasterRenderer::Render(glm::vec4 clipPlane) {
    staticShader.Start();
    staticShader.LoadClipPlane(clipPlane);
    staticShader.LoadSkyColor(skyColor);
    staticShader.LoadViewMatrix(camera->GetViewMatrix());
    staticShader.LoadLight(light->GetPosition(), light->GetColor());
    renderer.Render(entities);
    staticShader.Stop();
    entities.clear();
}

void MasterRenderer::RenderScene(std::vector<Entity*> _entities, glm::vec4 clipPlane) {
    for (int i = 0; i < _entities.size(); i++) {
        ProcessEntity(_entities.at(i));
    }
    Render(clipPlane);
}
