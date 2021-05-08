#include "Model.h"

Model::Model(Mesh* _mesh, Material* _material) {
    mesh = _mesh;
    material = _material;
}

Mesh* Model::GetMesh() {
    return mesh;
}

Material* Model::GetMaterial() {
    return material;
}
