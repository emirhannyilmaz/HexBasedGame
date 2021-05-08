#include "Material.h"

Material::Material(const char* texturePath, GLint format, GLenum sourceFormat, GLenum type, bool generateMipmaps, float _shineDamper, float _reflectivity) {
    shineDamper = _shineDamper;
    reflectivity = _reflectivity;

    texture = new Texture(texturePath, format, sourceFormat, type, true, generateMipmaps);
}

Texture* Material::GetTexture() {
    return texture;
}

float Material::GetShineDamper() {
    return shineDamper;
}

float Material::GetReflectivity() {
    return reflectivity;
}

Material::~Material() {
    delete texture;
}
