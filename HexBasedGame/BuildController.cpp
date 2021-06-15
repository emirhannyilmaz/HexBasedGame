#include "BuildController.h"

BuildController::BuildController(std::vector<Entity*>* _entities, std::vector<Light*>* _lights, std::vector<Hex*> _hexes, Text* _hexNameText, Text* _goldCountText, Text* _woodCountText, std::vector<ResourceGenerator*>* _resourceGenerators) {
	entities = _entities;
	lights = _lights;
	hexes = _hexes;
	resourceGenerators = _resourceGenerators;
	hexNameText = _hexNameText;
	goldCountText = _goldCountText;
	woodCountText = _woodCountText;

	std::vector<glm::vec3> vertices;
	std::vector<glm::vec2> texCoords;
	std::vector<glm::vec3> normals;
	std::vector<GLuint> indices;

	ObjLoader::LoadObj("Resources/Models/House.obj", vertices, texCoords, normals, indices, houseLights);
	Mesh* houseMesh = new Mesh(vertices, texCoords, normals, indices);
	Material* houseMaterial = new Material("Resources/Textures/House.png", GL_RGB, GL_RGB, GL_UNSIGNED_BYTE, true, 1.0f, 0.5f);
	houseModel = new Model(houseMesh, houseMaterial);

	vertices.clear();
	texCoords.clear();
	normals.clear();
	indices.clear();

	ObjLoader::LoadObj("Resources/Models/Sawmill.obj", vertices, texCoords, normals, indices, sawmillLights);
	Mesh* sawmillMesh = new Mesh(vertices, texCoords, normals, indices);
	Material* sawmillMaterial = new Material("Resources/Textures/Sawmill.png", GL_RGB, GL_RGB, GL_UNSIGNED_BYTE, true, 1.0f, 0.5f);
	sawmillModel = new Model(sawmillMesh, sawmillMaterial);
}

void BuildController::BuildTown() {
	if (PlayerStats::GetWoodCount() < 200) {
		return;
	}

	for (int i = 0; i < hexes.size(); i++) {
		if (!hexes.at(i)->GetIsSelected()) {
			continue;
		}
		float rotation = rand() % 360;
		House* house = new House(houseModel, houseLights, glm::vec3(hexes.at(i)->GetPosition().x, hexes.at(i)->GetPosition().y + 1.0f, hexes.at(i)->GetPosition().z), rotation, glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.5f, 1.5f, 1.5f));
		entities->push_back(house);
		for (int i = 0; i < house->GetLights().size(); i++) {
			Light* light = new Light(house->GetLights().at(i).GetPosition(), house->GetLights().at(i).GetColor(), house->GetLights().at(i).GetAttenuation());
			lights->push_back(light);
			placedLights.push_back(light);
		}
		placedHouses.push_back(house);
		resourceGenerators->push_back(house);
		hexNameText->SetText("House");
		hexes.at(i)->SetName("House");
		PlayerStats::SetWoodCount(PlayerStats::GetWoodCount() - 200);
		woodCountText->SetText("Wood: " + std::to_string(PlayerStats::GetWoodCount()));
	}
}

void BuildController::BuildSawmill() {
	if (PlayerStats::GetGoldCount() < 250) {
		return;
	}

	for (int i = 0; i < hexes.size(); i++) {
		if (!hexes.at(i)->GetIsSelected()) {
			continue;
		}
		float rotation = rand() % 360;
		Sawmill* sawmill = new Sawmill(sawmillModel, sawmillLights, glm::vec3(hexes.at(i)->GetPosition().x, hexes.at(i)->GetPosition().y + 1.0f, hexes.at(i)->GetPosition().z), rotation, glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.5f, 1.5f, 1.5f));
		entities->push_back(sawmill);
		for (int i = 0; i < sawmill->GetLights().size(); i++) {
			Light* light = new Light(sawmill->GetLights().at(i).GetPosition(), sawmill->GetLights().at(i).GetColor(), sawmill->GetLights().at(i).GetAttenuation());
			lights->push_back(light);
			placedLights.push_back(light);
		}
		placedSawmills.push_back(sawmill);
		resourceGenerators->push_back(sawmill);
		hexNameText->SetText("Sawmill");
		hexes.at(i)->SetName("Sawmill");
		PlayerStats::SetGoldCount(PlayerStats::GetGoldCount() - 250);
		goldCountText->SetText("Gold: " + std::to_string(PlayerStats::GetGoldCount()));
	}
}

BuildController::~BuildController() {
	delete houseModel->GetMesh();
	delete houseModel->GetMaterial();
	delete houseModel;
	for (int i = 0; i < placedHouses.size(); i++) {
		delete placedHouses.at(i);
	}

	delete sawmillModel->GetMesh();
	delete sawmillModel->GetMaterial();
	delete sawmillModel;
	for (int i = 0; i < placedSawmills.size(); i++) {
		delete placedSawmills.at(i);
	}

	for (int i = 0; i < placedLights.size(); i++) {
		delete placedLights.at(i);
	}
}