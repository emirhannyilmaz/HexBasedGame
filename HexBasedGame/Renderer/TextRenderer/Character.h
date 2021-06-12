#pragma once

#include "../../Objects/Texture.h"
#include <glm/glm.hpp>
#include <ft2build.h>
#include FT_FREETYPE_H

class Character {
public:
	Character(FT_Face face);
	Texture* GetTexture();
	glm::ivec2 GetSize();
	glm::ivec2 GetBearing();
	unsigned int GetAdvance();
	~Character();
private:
	Texture* texture = NULL;
	glm::ivec2 size;
	glm::ivec2 bearing;
	unsigned int advance;
};