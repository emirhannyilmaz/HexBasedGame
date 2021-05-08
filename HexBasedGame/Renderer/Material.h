#pragma once

#include <iostream>
#include <GL/glew.h>
#include "../Objects/Texture.h"

class Material {
public:
	Material(const char* texturePath, GLint format, GLenum sourceFormat, GLenum type, bool generateMipmaps, float _shineDamper, float _reflectivity);
	Texture* GetTexture();
	float GetShineDamper();
	float GetReflectivity();
	~Material();
private:
	Texture* texture = NULL;
	float shineDamper = 0.0f;
	float reflectivity = 0.0f;
};