#pragma once

#include <iostream>
#include <GL/glew.h>
#include "../../Shaders/SkyboxShader.h"
#include "../../Entities/Camera.h"
#include "../Mesh.h"
#include "../../Objects/Texture.h"

class SkyboxRenderer {
public:
	SkyboxRenderer(Camera* _camera);
	void Render();
private:
	SkyboxShader skyboxShader = SkyboxShader("Resources/Shaders/skyboxVertex.glsl", "Resources/Shaders/skyboxFragment.glsl");
	Camera* camera;
	const float SIZE = 500.0f;
	const std::vector<std::string> TEXTURE_FILES = {"Resources/Textures/Right.jpg", "Resources/Textures/Left.jpg", "Resources/Textures/Top.jpg", "Resources/Textures/Bottom.jpg", "Resources/Textures/Back.jpg", "Resources/Textures/Front.jpg"};
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
};