#include <iostream>
#include <GL/glew.h>
#include "IO/Window.h"
#include "Renderer/MasterRenderer.h"
#include <vector>
#include "Renderer/Mesh.h"
#include "Renderer/Material.h"
#include "Models/Model.h"
#include "Entities/Camera.h"
#include "Renderer/ObjLoader.h"
#include "Entities/Light.h"
#include "Physics/Collider.h"
#include "Physics/Collision.h"
#include "Physics/Raycast.h"
#include <glm/glm.hpp>
#include "Renderer/WaterRenderer.h"
#include "Renderer/WaterFrameBuffers.h"
#include "Entities/GuiTexture.h"
#include "Entities/GuiButton.h"
#include "Renderer/GuiRenderer.h"

void ClickCallback() {
	std::cout << "Callback Function!" << std::endl;
}

int main() {
	Window window;
	if (window.CreateWindow(1920, 1080, "Hex Based Game") == -1) {
		return -1;
	}

	Camera camera(45.0f, 1280.0f, 720.0f, 0.1f, 500.0f, glm::vec3(0.0f, 0.0f, 0.0f), 30.0f, 0.0f, 0.0f, 80.0f, 50.0f, 110.0f, 0.0f);
	Light light(glm::vec3(5000.0f, 5000.0f, 5000.0f), glm::vec3(1.0f, 1.0f, 1.0f));
	MasterRenderer masterRenderer(&camera, &light, glm::vec3(72.0f / 255.0f, 219.0f / 255.0f, 251.0f / 255.0f), 0.0030f, 2.0f);
	GuiRenderer guiRenderer;
	WaterFrameBuffers buffers;
	WaterRenderer waterRenderer(&camera, &buffers);
	Raycast ray(&camera, 500.0f, 200, 0.50f);

	std::vector<glm::vec3> vertices;
	std::vector<glm::vec2> texCoords;
	std::vector<glm::vec3> normals;
	std::vector<GLuint> indices;
	std::vector<Collider> colliders;
	ObjLoader::LoadObj("Resources/Models/hex.obj", vertices, texCoords, normals, indices, colliders);
	Mesh mesh(vertices, texCoords, normals, indices);
	Material material("Resources/Textures/hex.png", GL_RGB, GL_RGB, GL_UNSIGNED_BYTE, true, 1.0f, 0.5f);
	Model model(&mesh, &material);

	Entity entity(&model, colliders, glm::vec3(0.0f, 0.0f, 0.0f), 0.0f, glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(5.0f, 5.0f, 5.0f));
	Entity entity2(&model, colliders, glm::vec3(8.6f, 0.0f, 0.0f), 0.0f, glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(5.0f, 5.0f, 5.0f));
	Entity entity3(&model, colliders, glm::vec3(17.2f, 0.0f, 0.0f), 0.0f, glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(5.0f, 5.0f, 5.0f));
	Entity entity4(&model, colliders, glm::vec3(-8.6f, 0.0f, 0.0f), 0.0f, glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(5.0f, 5.0f, 5.0f));
	Entity entity5(&model, colliders, glm::vec3(-17.2f, 0.0f, 0.0f), 0.0f, glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(5.0f, 5.0f, 5.0f));
	Entity entity6(&model, colliders, glm::vec3(4.3f, 0.0f, -8.6f), 0.0f, glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(5.0f, 5.0f, 5.0f));
	Entity entity7(&model, colliders, glm::vec3(-4.3f, 0.0f, -8.6f), 0.0f, glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(5.0f, 5.0f, 5.0f));
	Entity entity8(&model, colliders, glm::vec3(12.9f, 0.0f, -8.6f), 0.0f, glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(5.0f, 5.0f, 5.0f));
	Entity entity9(&model, colliders, glm::vec3(21.5f, 0.0f, -8.6f), 0.0f, glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(5.0f, 5.0f, 5.0f));
	Entity entity10(&model, colliders, glm::vec3(-12.9f, 0.0f, -8.6f), 0.0f, glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(5.0f, 5.0f, 5.0f));
	Entity entity11(&model, colliders, glm::vec3(-21.5f, 0.0f, -8.6f), 0.0f, glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(5.0f, 5.0f, 5.0f));

	std::vector<Entity*> entities;
	entities.push_back(&entity);
	entities.push_back(&entity2);
	entities.push_back(&entity3);
	entities.push_back(&entity4);
	entities.push_back(&entity5);
	entities.push_back(&entity6);
	entities.push_back(&entity7);
	entities.push_back(&entity8);
	entities.push_back(&entity9);
	entities.push_back(&entity10);
	entities.push_back(&entity11);

	WaterTile waterTile(0.0f, 0.0f, 0.0f);

	std::vector<WaterTile*> waterTiles;
	waterTiles.push_back(&waterTile);

	GuiTexture hexInfoTexture("Resources/Textures/hexInfo.png", GL_RGB, GL_RGB, GL_UNSIGNED_BYTE, glm::vec2(0.0f, 1.0f - 0.1f), 0.0f, glm::vec3(0.0f, 0.0f, 0.0f), 250.0f, 60.0f, false);
	GuiButton buildTownButton("Resources/Textures/buildTown.png", GL_RGB, GL_RGB, GL_UNSIGNED_BYTE, glm::vec2(-1.0f + 0.1f, 0.0f), 0.0f, glm::vec3(0.0f, 0.0f, 0.0f), 100.0f, 100.0f, true, ClickCallback);

	std::vector<GuiTexture*> guiTextures;
	guiTextures.push_back(&hexInfoTexture);

	std::vector<GuiButton*> guiButtons;
	guiButtons.push_back(&buildTownButton);

	while (!window.ShouldClose()) {
		window.CalculateDeltaTime();

		camera.HandleInput();
		for (GuiButton* guiButton : guiButtons) {
			guiButton->HandleMouse();
		}
		ray.Update();
		ray.CheckForCollisions(entities, &hexInfoTexture);

		glEnable(GL_CLIP_DISTANCE0);
		buffers.BindReflectionFrameBuffer();
		float distance = 2 * (camera.GetPosition().y - waterTile.GetHeight());
		camera.SetPosition(glm::vec3(camera.GetPosition().x, camera.GetPosition().y - distance, camera.GetPosition().z));
		camera.InvertPitch();
		masterRenderer.Clear();
		masterRenderer.RenderScene(entities, glm::vec4(0.0f, 1.0f, 0.0f, -waterTile.GetHeight() + 1.0f));
		camera.SetPosition(glm::vec3(camera.GetPosition().x, camera.GetPosition().y + distance, camera.GetPosition().z));
		camera.InvertPitch();

		buffers.BindRefractionFrameBuffer();
		masterRenderer.Clear();
		masterRenderer.RenderScene(entities, glm::vec4(0.0f, -1.0f, 0.0f, waterTile.GetHeight()));

		glDisable(GL_CLIP_DISTANCE0);
		buffers.UnbindCurrentFrameBuffer();
		masterRenderer.Clear();
		masterRenderer.RenderScene(entities, glm::vec4(0.0f, 1.0f, 0.0f, 1000000.0f));
		waterRenderer.Render(waterTiles, &light);
		guiRenderer.Render(guiTextures, guiButtons);

		window.DoStuff();
	}

	return 0;
}
