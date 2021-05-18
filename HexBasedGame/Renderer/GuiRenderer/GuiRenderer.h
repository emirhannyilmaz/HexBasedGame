#pragma once

#include <iostream>
#include <GL/glew.h>
#include <vector>
#include <glm/glm.hpp>
#include "../Mesh.h"
#include "../../Entities/GuiTexture.h"
#include "../../Entities/GuiButton.h"
#include "../../Shaders/GuiShader.h"

class GuiRenderer {
public:
	void Render(std::vector<GuiTexture*> guiTextures, std::vector<GuiButton*> guiButtons);
private:
	std::vector<glm::vec2> vertices = {
		glm::vec2(-1.0f, 1.0f),
		glm::vec2(-1.0f, -1.0f),
		glm::vec2(1.0f, 1.0f),
		glm::vec2(1.0f, -1.0f)
	};
	Mesh mesh = Mesh(vertices);
	GuiShader guiShader = GuiShader("Resources/Shaders/guiVertex.glsl", "Resources/Shaders/guiFragment.glsl");
};