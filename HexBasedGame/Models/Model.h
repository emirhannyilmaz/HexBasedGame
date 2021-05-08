#pragma once

#include <iostream>
#include "../Renderer/Mesh.h"
#include "../Renderer/Material.h"

class Model {
public:
    Model(Mesh* _mesh, Material* _material);
    Mesh* mesh = NULL;
    Material* material = NULL;
    Mesh* GetMesh();
    Material* GetMaterial();
};