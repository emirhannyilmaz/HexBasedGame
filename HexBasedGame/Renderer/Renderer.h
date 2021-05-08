#pragma once

#include <iostream>
#include <GL/glew.h>
#include "../Shaders/StaticShader.h"
#include <vector>
#include "../Entities/Entity.h"
#include "../Models/Model.h"
#include "Mesh.h"
#include <map>

class Renderer {
public:
    Renderer(StaticShader* _staticShader);
    void Render(std::map<Model*, std::vector<Entity*>> entities);
    void BindModel(Model* model);
    void PrepareEntity(Entity* entity);
    void UnbindModel();
private:
    StaticShader* staticShader = NULL;
};