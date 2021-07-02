#include "BuildController.h"

BuildController::BuildController(std::vector<Entity*>* _entities, std::vector<Light*>* _lights, std::vector<Hex*> _hexes, Text* _hexNameText, Text* _moneyText, std::vector<Property*>* _properties, std::vector<SaleableProperty*>* _saleableProperties) {
	entities = _entities;
	lights = _lights;
	hexes = _hexes;
	hexNameText = _hexNameText;
	moneyText = _moneyText;
	properties = _properties;
	saleableProperties = _saleableProperties;

	std::vector<glm::vec3> vertices;
	std::vector<glm::vec2> texCoords;
	std::vector<glm::vec3> normals;
	std::vector<GLuint> indices;

	ObjLoader::LoadObj("Resources/Models/Concrete.obj", vertices, texCoords, normals, indices);
	Mesh* concreteMesh = new Mesh(vertices, texCoords, normals, indices);
	Material* concreteMaterial = new Material("Resources/Textures/Palette.png", GL_RGB, GL_RGB, GL_UNSIGNED_BYTE, true, 1.0f, 0.1f);
	concreteModel = new Model(concreteMesh, concreteMaterial);

	vertices.clear();
	texCoords.clear();
	normals.clear();
	indices.clear();

	ObjLoader::LoadObj("Resources/Models/Hotel.obj", vertices, texCoords, normals, indices, hotelLights);
	Mesh* hotelMesh = new Mesh(vertices, texCoords, normals, indices);
	Material* hotelMaterial = new Material("Resources/Textures/Palette.png", GL_RGB, GL_RGB, GL_UNSIGNED_BYTE, true, 1.0f, 0.5f);
	hotelModel = new Model(hotelMesh, hotelMaterial);

	vertices.clear();
	texCoords.clear();
	normals.clear();
	indices.clear();

	ObjLoader::LoadObj("Resources/Models/Apartment.obj", vertices, texCoords, normals, indices, apartmentLights);
	Mesh* apartmentMesh = new Mesh(vertices, texCoords, normals, indices);
	Material* apartmentMaterial = new Material("Resources/Textures/Palette.png", GL_RGB, GL_RGB, GL_UNSIGNED_BYTE, true, 1.0f, 0.5f);
	apartmentModel = new Model(apartmentMesh, apartmentMaterial);
}

void BuildController::BuildHotel() {
	if (PlayerStats::GetMoney() < 250) {
		return;
	}

	for (int i = 0; i < hexes.size(); i++) {
		if (!hexes.at(i)->GetIsSelected()) {
			continue;
		}
		Concrete* concrete = new Concrete(concreteModel, glm::vec3(hexes.at(i)->GetPosition().x, hexes.at(i)->GetPosition().y + 1.0f, hexes.at(i)->GetPosition().z), 0.0f, glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(10.0f, 10.0f, 10.0f));
		entities->push_back(concrete);
		placedConcretes.push_back(concrete);
		float rotation = rand() % 360;
		Hotel* hotel = new Hotel(hotelModel, hotelLights, glm::vec3(hexes.at(i)->GetPosition().x, hexes.at(i)->GetPosition().y + 1.0f + 0.2f, hexes.at(i)->GetPosition().z), rotation, glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(10.0f, 10.0f, 10.0f), 50, 25);
		entities->push_back(hotel);
		for (int i = 0; i < hotel->GetLights().size(); i++) {
			Light* light = new Light(hotel->GetLights().at(i).GetPosition(), hotel->GetLights().at(i).GetColor(), hotel->GetLights().at(i).GetAttenuation());
			lights->push_back(light);
			placedLights.push_back(light);
		}
		placedHotels.push_back(hotel);
		properties->push_back(hotel);
		hexNameText->SetText("Hotel");
		hexes.at(i)->SetName("Hotel");
		PlayerStats::SetMoney(PlayerStats::GetMoney() - 250);
		moneyText->SetText("Money: " + std::to_string(PlayerStats::GetMoney()));
	}
}

void BuildController::BuildApartment() {
	if (PlayerStats::GetMoney() < 1000) {
		return;
	}

	for (int i = 0; i < hexes.size(); i++) {
		if (!hexes.at(i)->GetIsSelected()) {
			continue;
		}
		Concrete* concrete = new Concrete(concreteModel, glm::vec3(hexes.at(i)->GetPosition().x, hexes.at(i)->GetPosition().y + 1.0f, hexes.at(i)->GetPosition().z), 0.0f, glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(10.0f, 10.0f, 10.0f));
		entities->push_back(concrete);
		placedConcretes.push_back(concrete);
		float rotation = rand() % 360;
		Apartment* apartment = new Apartment(apartmentModel, apartmentLights, glm::vec3(hexes.at(i)->GetPosition().x, hexes.at(i)->GetPosition().y + 1.0f + 0.2f, hexes.at(i)->GetPosition().z), rotation, glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.25f, 0.25f, 0.25f), 3000);
		entities->push_back(apartment);
		for (int i = 0; i < apartment->GetLights().size(); i++) {
			Light* light = new Light(apartment->GetLights().at(i).GetPosition(), apartment->GetLights().at(i).GetColor(), apartment->GetLights().at(i).GetAttenuation());
			lights->push_back(light);
			placedLights.push_back(light);
		}
		placedApartments.push_back(apartment);
		saleableProperties->push_back(apartment);
		hexNameText->SetText("Apartment");
		hexes.at(i)->SetName("Apartment");
		PlayerStats::SetMoney(PlayerStats::GetMoney() - 1000);
		moneyText->SetText("Money: " + std::to_string(PlayerStats::GetMoney()));
	}
}

BuildController::~BuildController() {
	delete concreteModel->GetMesh();
	delete concreteModel->GetMaterial();
	delete concreteModel;
	for (int i = 0; i < placedConcretes.size(); i++) {
		delete placedConcretes.at(i);
	}

	delete hotelModel->GetMesh();
	delete hotelModel->GetMaterial();
	delete hotelModel;
	for (int i = 0; i < placedHotels.size(); i++) {
		delete placedHotels.at(i);
	}

	delete apartmentModel->GetMesh();
	delete apartmentModel->GetMaterial();
	delete apartmentModel;
	for (int i = 0; i < placedApartments.size(); i++) {
		delete placedApartments.at(i);
	}

	for (int i = 0; i < placedLights.size(); i++) {
		delete placedLights.at(i);
	}
}