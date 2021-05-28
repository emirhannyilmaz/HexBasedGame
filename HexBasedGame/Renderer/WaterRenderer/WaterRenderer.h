#pragma once

#include <iostream>
#include "../../Shaders/WaterShader.h"
#include <vector>
#include "../../Entities/WaterTile.h"
#include "../../Entities/Camera.h"
#include "../Mesh.h"
#include "WaterFrameBuffers.h"
#include "../../Objects/Texture.h"
#include "../../IO/Window.h"
#include "../../Entities/Light.h"

class WaterRenderer {
public:
	WaterRenderer(Camera* _camera, WaterFrameBuffers* _fbos);
	void Render(std::vector<WaterTile*> waterTiles, std::vector<Light*> lights);
private:
	WaterShader waterShader = WaterShader("Resources/Shaders/waterVertex.glsl", "Resources/Shaders/waterFragment.glsl");
	Camera* camera = NULL;
	WaterFrameBuffers* fbos = NULL;
	std::vector<glm::vec3> vertices = {
		glm::vec3(-1.0f, 0.0f, -1.0f),
		glm::vec3(-1.0f, 0.0f, 1.0f),
		glm::vec3(1.0f, 0.0f, -1.0f),
		glm::vec3(1.0f, 0.0f, -1.0f),
		glm::vec3(-1.0f, 0.0f, 1.0f),
		glm::vec3(1.0f, 0.0f, 1.0f)
	};
	Mesh mesh = Mesh(vertices);
	static const char* DUDV_MAP;
	static const char* NORMAL_MAP;
	static const float WAVE_SPEED;
	Texture* waterDudvTexture = NULL;
	Texture* normalMapTexture = NULL;
	float moveFactor = 0.0f;
};
