#pragma once

#include <iostream>
#include <GL/glew.h>
#include <ft2build.h>
#include FT_FREETYPE_H
#include "Character.h"
#include <map>

class FontLoader {
public:
	static void LoadFont(const char* fontPath, unsigned int fontHeight, std::map<char, Character*>& characters);
};