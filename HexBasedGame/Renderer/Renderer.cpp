#include "Renderer.h"

Renderer::Renderer(StaticShader* _staticShader) {
    staticShader = _staticShader;
}

void Renderer::Render(std::map<Model*, std::vector<Entity*>> entities) {
    for (auto& key : entities) {
        BindModel(key.first);
        for (Entity* e : key.second) {
            PrepareEntity(e);
            glDrawElements(GL_TRIANGLES, e->GetModel()->GetMesh()->GetIndicesCount(), GL_UNSIGNED_INT, 0);
        }
        UnbindModel();
    }
}

void Renderer::BindModel(Model* model) {
    glBindVertexArray(model->GetMesh()->GetVao()->GetId());
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, model->GetMaterial()->GetTexture()->GetId());
    staticShader->LoadShineVariables(model->GetMaterial()->GetShineDamper(), model->GetMaterial()->GetReflectivity());
}

void Renderer::PrepareEntity(Entity* entity) {
    staticShader->LoadModelMatrix(entity->GetModelMatrix());
    staticShader->LoadIsHighlighted(entity->GetIsHighlighted());
    staticShader->LoadIsSelected(entity->GetIsSelected());
}

void Renderer::UnbindModel() {
    glBindVertexArray(0);
}
