#include <iostream>
#include "IO/Window.h"
#include "Renderer/EntityRenderer/MasterRenderer.h"
#include <vector>
#include "Renderer/Mesh.h"
#include "Renderer/Material.h"
#include "Models/Model.h"
#include "Entities/Camera.h"
#include "Renderer/EntityRenderer/ObjLoader.h"
#include "Entities/Light.h"
#include "Physics/Collider.h"
#include "Physics/Collision.h"
#include "Physics/Raycast.h"
#include <glm/glm.hpp>
#include "Renderer/WaterRenderer/WaterRenderer.h"
#include "Renderer/WaterRenderer/WaterFrameBuffers.h"
#include "Entities/GuiTexture.h"
#include "Entities/GuiButton.h"
#include "Renderer/GuiRenderer/GuiRenderer.h"
#include "BuildController.h"
#include "Entities/Text.h"
#include "Renderer/TextRenderer/TextRenderer.h"
#include "Renderer/TextRenderer/FontLoader.h"
#include "Renderer/TextRenderer/Character.h"
#include <map>
#include "Renderer/SkyboxRenderer/SkyboxRenderer.h"
#include "Entities/Buildings/Hex.h"
#include "Entities/Buildings/Hotel.h"
#include "Entities/Buildings/Apartment.h"

BuildController* buildController = NULL;

void BuildHotelButtonClick() {
	buildController->BuildHotel();
}

void BuildApartmentButtonClick() {
	buildController->BuildApartment();
}

int main() {
	Window window;
	if (window.CreateWindow(1920, 1080, "Hex Based Game") == -1) {
		return -1;
	}

	std::map<char, Character*> characters;
	FontLoader::LoadFont("Resources/Fonts/arialbd.ttf", 20, characters);

	Camera camera(60.0f, 1920, 1080, 0.1f, 1000.0f, glm::vec3(0.0f, 0.0f, 0.0f), 30.0f, 0.0f, 0.0f, 100.0f, 100.0f, 180.0f, 180.0f);
	MasterRenderer masterRenderer(&camera, glm::vec3(0.5444f, 0.62f, 0.69f), 0.0020f, 10.0f);
	GuiRenderer guiRenderer;
	WaterFrameBuffers buffers;
	WaterRenderer waterRenderer(&camera, &buffers, glm::vec3(0.5444f, 0.62f, 0.69f), 0.0020f, 10.0f);
	Raycast ray(&camera, 500.0f, 200, 0.50f);
	TextRenderer textRenderer(characters);
	SkyboxRenderer skyboxRenderer(&camera, glm::vec3(0.5444f, 0.62f, 0.69f));

	std::vector<glm::vec3> vertices;
	std::vector<glm::vec2> texCoords;
	std::vector<glm::vec3> normals;
	std::vector<GLuint> indices;
	std::vector<Collider> colliders;
	ObjLoader::LoadObj("Resources/Models/Hex.obj", vertices, texCoords, normals, indices, colliders);
	Mesh mesh(vertices, texCoords, normals, indices);
	Material material("Resources/Textures/Hex.png", GL_RGB, GL_RGB, GL_UNSIGNED_BYTE, true, 10.0f, 0.3f);
	Model model(&mesh, &material);

	Hex hex1(&model, colliders, glm::vec3(0.0f, 0.0f, 0.0f), 0.0f, glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(10.0f, 10.0f, 10.0f), "Empty");
	Hex hex2(&model, colliders, glm::vec3(17.3f, 0.0f, 0.0f), 0.0f, glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(10.0f, 10.0f, 10.0f), "Empty");
	Hex hex3(&model, colliders, glm::vec3(34.6f, 0.0f, 0.0f), 0.0f, glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(10.0f, 10.0f, 10.0f), "Empty");
	Hex hex4(&model, colliders, glm::vec3(-17.3f, 0.0f, 0.0f), 0.0f, glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(10.0f, 10.0f, 10.0f), "Empty");
	Hex hex5(&model, colliders, glm::vec3(-34.6f, 0.0f, 0.0f), 0.0f, glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(10.0f, 10.0f, 10.0f), "Empty");
	Hex hex6(&model, colliders, glm::vec3(8.65f, 0.0f, -15.0f), 0.0f, glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(10.0f, 10.0f, 10.0f), "Empty");
	Hex hex7(&model, colliders, glm::vec3(25.95f, 0.0f, -15.0f), 0.0f, glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(10.0f, 10.0f, 10.0f), "Empty");
	Hex hex8(&model, colliders, glm::vec3(43.25f, 0.0f, -15.0f), 0.0f, glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(10.0f, 10.0f, 10.0f), "Empty");
	Hex hex9(&model, colliders, glm::vec3(-8.65f, 0.0f, -15.0f), 0.0f, glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(10.0f, 10.0f, 10.0f), "Empty");
	Hex hex10(&model, colliders, glm::vec3(-25.95f, 0.0f, -15.0f), 0.0f, glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(10.0f, 10.0f, 10.0f), "Empty");
	Hex hex11(&model, colliders, glm::vec3(-43.25f, 0.0f, -15.0f), 0.0f, glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(10.0f, 10.0f, 10.0f), "Empty");
	Hex hex12(&model, colliders, glm::vec3(0.0f, 0.0f, -30.0f), 0.0f, glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(10.0f, 10.0f, 10.0f), "Empty");
	Hex hex13(&model, colliders, glm::vec3(17.3f, 0.0f, -30.0f), 0.0f, glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(10.0f, 10.0f, 10.0f), "Empty");
	Hex hex14(&model, colliders, glm::vec3(34.6f, 0.0f, -30.0f), 0.0f, glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(10.0f, 10.0f, 10.0f), "Empty");
	Hex hex15(&model, colliders, glm::vec3(-17.3f, 0.0f, -30.0f), 0.0f, glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(10.0f, 10.0f, 10.0f), "Empty");
	Hex hex16(&model, colliders, glm::vec3(-34.6f, 0.0f, -30.0f), 0.0f, glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(10.0f, 10.0f, 10.0f), "Empty");
	std::vector<Entity*> entities;
	entities.push_back(&hex1);
	entities.push_back(&hex2);
	entities.push_back(&hex3);
	entities.push_back(&hex4);
	entities.push_back(&hex5);
	entities.push_back(&hex6);
	entities.push_back(&hex7);
	entities.push_back(&hex8);
	entities.push_back(&hex9);
	entities.push_back(&hex10);
	entities.push_back(&hex11);
	entities.push_back(&hex12);
	entities.push_back(&hex13);
	entities.push_back(&hex14);
	entities.push_back(&hex15);
	entities.push_back(&hex16);
	std::vector<Hex*> hexes;
	hexes.push_back(&hex1);
	hexes.push_back(&hex2);
	hexes.push_back(&hex3);
	hexes.push_back(&hex4);
	hexes.push_back(&hex5);
	hexes.push_back(&hex6);
	hexes.push_back(&hex7);
	hexes.push_back(&hex8);
	hexes.push_back(&hex9);
	hexes.push_back(&hex10);
	hexes.push_back(&hex11);
	hexes.push_back(&hex12);
	hexes.push_back(&hex13);
	hexes.push_back(&hex14);
	hexes.push_back(&hex15);
	hexes.push_back(&hex16);

	WaterTile waterTile(0.0f, 0.0f, 0.0f);
	std::vector<WaterTile*> waterTiles;
	waterTiles.push_back(&waterTile);

	Light mainLight(glm::vec3(5000.0f, 5000.0f, -5000.0f), glm::vec3(1.0f, 1.0f, 1.0f));
	std::vector<Light*> lights;
	lights.push_back(&mainLight);

	GuiTexture infoTexture("Resources/Textures/Info.png", GL_RGBA, GL_RGBA, GL_UNSIGNED_BYTE, glm::vec2(Window::GetWidth() / 2.0f, 15.0f), 0.0f, glm::vec3(0.0f, 0.0f, 0.0f), glm::vec2(300.0f, 30.0f), true);
	GuiTexture hexInfoTexture("Resources/Textures/HexInfo.png", GL_RGBA, GL_RGBA, GL_UNSIGNED_BYTE, glm::vec2(Window::GetWidth() / 2.0f, Window::GetHeight() - 15.0f), 0.0f, glm::vec3(0.0f, 0.0f, 0.0f), glm::vec2(300.0f, 30.0f), false);
	GuiTexture buildMenuTexture("Resources/Textures/BuildMenu.png", GL_RGBA, GL_RGBA, GL_UNSIGNED_BYTE, glm::vec2(30.0f, Window::GetHeight() / 2.0f), 0.0f, glm::vec3(0.0f, 0.0f, 0.0f), glm::vec2(60.0f, 300.0f), false);
	std::vector<GuiTexture*> guiTextures;
	guiTextures.push_back(&infoTexture);
	guiTextures.push_back(&hexInfoTexture);
	guiTextures.push_back(&buildMenuTexture);

	GuiButton buildHotelButton("Resources/Textures/BuildHotelButton.png", GL_RGBA, GL_RGBA, GL_UNSIGNED_BYTE, glm::vec2(30.0f, Window::GetHeight() / 2.0f + 25.0f + 2.5f), 0.0f, glm::vec3(0.0f, 0.0f, 0.0f), glm::vec2(50.0f, 50.0f), false, BuildHotelButtonClick);
	GuiButton buildApartmentButton("Resources/Textures/BuildApartmentButton.png", GL_RGBA, GL_RGBA, GL_UNSIGNED_BYTE, glm::vec2(30.0f, Window::GetHeight() / 2.0f - 25.0f - 2.5f), 0.0f, glm::vec3(0.0f, 0.0f, 0.0f), glm::vec2(50.0f, 50.0f), false, BuildApartmentButtonClick);
	std::vector<GuiButton*> guiButtons;
	guiButtons.push_back(&buildHotelButton);
	guiButtons.push_back(&buildApartmentButton);

	Text moneyText("Money: " + std::to_string(PlayerStats::GetMoney()), glm::vec2(Window::GetWidth() / 2.0f, 7.5f), glm::vec2(1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), true, true);
	Text hexNameText("", glm::vec2(Window::GetWidth() / 2.0f, Window::GetHeight() - 22.0f), glm::vec2(1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), false, true);
	std::vector<Text*> texts;
	texts.push_back(&moneyText);
	texts.push_back(&hexNameText);

	std::vector<Property*> properties;
	std::vector<SaleableProperty*> saleableProperties;

	buildController = new BuildController(&entities, &lights, hexes, &hexNameText, &moneyText, &properties, &saleableProperties);

	while (!window.ShouldClose()) {
		window.CalculateDeltaTime();

		camera.HandleInput();
		for (GuiButton* guiButton : guiButtons) {
			guiButton->HandleMouse();
		}
		for (Property* prop : properties) {
			prop->Update(moneyText);
		}
		for (SaleableProperty* saleableProp : saleableProperties) {
			saleableProp->Update(moneyText);
		}
		ray.Update();
		ray.CheckForCollisions(entities, &buildMenuTexture, guiButtons, &hexInfoTexture, &hexNameText);

		glEnable(GL_CLIP_DISTANCE0);
		buffers.BindReflectionFrameBuffer();
		float distance = 2 * (camera.GetPosition().y - waterTile.GetHeight());
		camera.SetPosition(glm::vec3(camera.GetPosition().x, camera.GetPosition().y - distance, camera.GetPosition().z));
		camera.InvertPitch();
		masterRenderer.Clear();
		skyboxRenderer.Render();
		masterRenderer.RenderScene(entities, lights, glm::vec4(0.0f, 1.0f, 0.0f, -waterTile.GetHeight() + 0.5f));
		camera.SetPosition(glm::vec3(camera.GetPosition().x, camera.GetPosition().y + distance, camera.GetPosition().z));
		camera.InvertPitch();

		buffers.BindRefractionFrameBuffer();
		masterRenderer.Clear();
		masterRenderer.RenderScene(entities, lights, glm::vec4(0.0f, -1.0f, 0.0f, waterTile.GetHeight()));

		glDisable(GL_CLIP_DISTANCE0);
		buffers.UnbindCurrentFrameBuffer();
		masterRenderer.Clear();
		skyboxRenderer.Render();
		masterRenderer.RenderScene(entities, lights, glm::vec4(0.0f, 1.0f, 0.0f, 1000000.0f));
		waterRenderer.Render(waterTiles, lights);
		guiRenderer.Render(guiTextures, guiButtons);
		textRenderer.Render(texts);

		window.DoStuff();
	}

	delete buildController;

	return 0;
}