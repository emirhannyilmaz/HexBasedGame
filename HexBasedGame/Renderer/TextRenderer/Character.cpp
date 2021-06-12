#include "Character.h"

Character::Character(FT_Face face) {
	texture = new Texture(GL_RED, GL_RED, face->glyph->bitmap.width, face->glyph->bitmap.rows, GL_UNSIGNED_BYTE, face->glyph->bitmap.buffer, false);
	size = glm::ivec2(face->glyph->bitmap.width, face->glyph->bitmap.rows);
	bearing = glm::ivec2(face->glyph->bitmap_left, face->glyph->bitmap_top);
	advance = face->glyph->advance.x;
}

Texture* Character::GetTexture() {
	return texture;
}

glm::ivec2 Character::GetSize() {
	return size;
}

glm::ivec2 Character::GetBearing() {
	return bearing;
}

unsigned int Character::GetAdvance() {
	return advance;
}

Character::~Character() {
	delete texture;
}