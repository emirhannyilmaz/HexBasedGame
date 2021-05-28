#include "MasterRenderer.h"

MasterRenderer::MasterRenderer(Camera* _camera, glm::vec3 _skyColor, float fogDensity, float fogGradient) {
    camera = _camera;
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

void MasterRenderer::Render(std::vector<Light*> lights, glm::vec4 clipPlane) {
    glEnable(GL_DEPTH_TEST);
    staticShader.Start();
    staticShader.LoadClipPlane(clipPlane);
    staticShader.LoadSkyColor(skyColor);
    staticShader.LoadViewMatrix(camera->GetViewMatrix());
    staticShader.LoadLights(lights);
    renderer.Render(entities);
    staticShader.Stop();
    entities.clear();
    glDisable(GL_DEPTH_TEST);
}

void MasterRenderer::RenderScene(std::vector<Entity*> _entities, std::vector<Light*> lights, glm::vec4 clipPlane) {
    for (int i = 0; i < _entities.size(); i++) {
        ProcessEntity(_entities.at(i));
    }
    Render(lights, clipPlane);
}
