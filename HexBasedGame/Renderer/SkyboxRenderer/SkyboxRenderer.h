#pragma once

#include <iostream>
#include <GL/glew.h>
#include "../../Shaders/SkyboxShader.h"
#include "../../Entities/Camera.h"
#include "../Mesh.h"
#include "../../Objects/Texture.h"

class SkyboxRenderer {
public:
	SkyboxRenderer(Camera* _camera, glm::vec3 _fogColor);
	void Render();
	void BindTextures();
private:
	SkyboxShader skyboxShader = SkyboxShader("Resources/Shaders/skyboxVertex.glsl", "Resources/Shaders/skyboxFragment.glsl");
	Camera* camera;
	glm::vec3 fogColor;
	const float SIZE = 500.0f;
	const std::vector<std::string> TEXTURE_FILES = {"Resources/Textures/Right.jpg", "Resources/Textures/Left.jpg", "Resources/Textures/Top.jpg", "Resources/Textures/Bottom.jpg", "Resources/Textures/Back.jpg", "Resources/Textures/Front.jpg"};
	const std::vector<std::string> NIGHT_TEXTURE_FILES = { "Resources/Textures/NightRight.jpg", "Resources/Textures/NightLeft.jpg", "Resources/Textures/NightTop.jpg", "Resources/Textures/NightBottom.jpg", "Resources/Textures/NightBack.jpg", "Resources/Textures/NightFront.jpg" };
	std::vector<glm::vec3> vertices = {
		glm::vec3(-SIZE, SIZE, -SIZE),
		glm::vec3(-SIZE, -SIZE, -SIZE),
		glm::vec3(SIZE, -SIZE, -SIZE),
		glm::vec3(SIZE, -SIZE, -SIZE),
		glm::vec3(SIZE, SIZE, -SIZE),
		glm::vec3(-SIZE, SIZE, -SIZE),

		glm::vec3(-SIZE, -SIZE, SIZE),
		glm::vec3(-SIZE, -SIZE, -SIZE),
		glm::vec3(-SIZE, SIZE, -SIZE),
		glm::vec3(-SIZE, SIZE, -SIZE),
		glm::vec3(-SIZE, SIZE, SIZE),
		glm::vec3(-SIZE, -SIZE, SIZE),

		glm::vec3(SIZE, -SIZE, -SIZE),
		glm::vec3(SIZE, -SIZE, SIZE),
		glm::vec3(SIZE, SIZE, SIZE),
		glm::vec3(SIZE, SIZE, SIZE),
		glm::vec3(SIZE, SIZE, -SIZE),
		glm::vec3(SIZE, -SIZE, -SIZE),

		glm::vec3(-SIZE, -SIZE, SIZE),
		glm::vec3(-SIZE, SIZE, SIZE),
		glm::vec3(SIZE, SIZE, SIZE),
		glm::vec3(SIZE, SIZE, SIZE),
		glm::vec3(SIZE, -SIZE, SIZE),
		glm::vec3(-SIZE, -SIZE, SIZE),

		glm::vec3(-SIZE, SIZE, -SIZE),
		glm::vec3(SIZE, SIZE, -SIZE),
		glm::vec3(SIZE, SIZE, SIZE),
		glm::vec3(SIZE, SIZE, SIZE),
		glm::vec3(-SIZE, SIZE, SIZE),
		glm::vec3(-SIZE, SIZE, -SIZE),

		glm::vec3(-SIZE, -SIZE, -SIZE),
		glm::vec3(-SIZE, -SIZE, SIZE),
		glm::vec3(SIZE, -SIZE, -SIZE),
		glm::vec3(SIZE, -SIZE, -SIZE),
		glm::vec3(-SIZE, -SIZE, SIZE),
		glm::vec3(SIZE, -SIZE, SIZE)
	};
	Mesh mesh = Mesh(vertices);
	Texture texture = Texture(TEXTURE_FILES, GL_RGB, GL_RGB, GL_UNSIGNED_BYTE, false);
	Texture nightTexture = Texture(NIGHT_TEXTURE_FILES, GL_RGB, GL_RGB, GL_UNSIGNED_BYTE, false);
	float time = 0.0f;
};