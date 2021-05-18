#pragma once

#include <iostream>
#include <GL/glew.h>
#include "../Mesh.h"
#include "../../IO/Window.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "../../Shaders/TextShader.h"
#include <map>
#include "Character.h"
#include "../../Entities/Text.h"
#include <vector>
#include "../../Entities/Text.h"

class TextRenderer {
public:
	TextRenderer(std::map<char, Character*> _characters);
	void Render(std::vector<Text*> texts);
	~TextRenderer();
private:
	Mesh mesh = Mesh(sizeof(float) * 6 * 4, 4, GL_FLOAT, 4 * sizeof(float), 0);
	std::map<char, Character*> characters;
	TextShader shader = TextShader("Resources/Shaders/textVertex.glsl", "Resources/Shaders/textFragment.glsl");
};