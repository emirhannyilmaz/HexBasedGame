#include "FontLoader.h"

void FontLoader::LoadFont(const char* fontPath, unsigned int fontHeight, std::map<char, Character*>& characters) {
	FT_Library library;
	if (FT_Init_FreeType(&library)) {
		std::cout << "ERROR::FONT_LOADER::FREETYPE_LIBRARY_INITIALIZATION_FAILED" << std::endl;
	}

	FT_Face face;
	if (FT_New_Face(library, fontPath, 0, &face)) {
		std::cout << "ERROR::FONT_LOADER::FREETYPE_FONT_LOADING_FAILED" << std::endl;
	}

	FT_Set_Pixel_Sizes(face, 0, fontHeight);

	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	for (unsigned char c = 0; c < 128; c++) {
		if (FT_Load_Char(face, c, FT_LOAD_RENDER)) {
			std::cout << "ERROR::FONT_LOADER::GLYPH_LOADING_FAILED" << std::endl;
			continue;
		}

		Character* character = new Character(face);
		characters.insert(std::pair<char, Character*>(c, character));
	}

	FT_Done_Face(face);
	FT_Done_FreeType(library);
}