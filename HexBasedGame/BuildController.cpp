#include "BuildController.h"

BuildController::BuildController(std::vector<Entity*>* _entities, Text* _hexNameText) {
	entities = _entities;
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec2> texCoords;
	std::vector<glm::vec3> normals;
	std::vector<GLuint> indices;
	ObjLoader::LoadObj("Resources/Models/well.obj", vertices, texCoords, normals, indices);
	Mesh* houseMesh = new Mesh(vertices, texCoords, normals, indices);
	Material* houseMaterial = new Material("Resources/Textures/well.png", GL_RGB, GL_RGB, GL_UNSIGNED_BYTE, true, 1.0f, 0.5f);
	houseModel = new Model(houseMesh, houseMaterial);
	hexNameText = _hexNameText;
}

void BuildController::BuildTown() {
	for (int i = 0; i < entities->size(); i++) {
		if (!entities->at(i)->GetIsSelected()) {
			continue;
		}
		Entity* entityToPlace = new Entity(houseModel, glm::vec3(entities->at(i)->GetPosition().x, entities->at(i)->GetPosition().y + 1.0f, entities->at(i)->GetPosition().z), 0.0f, glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(3.0f, 3.0f, 3.0f));
		entities->push_back(entityToPlace);
		placedEntities.push_back(entityToPlace);
		hexNameText->SetText("Town");	
		entities->at(i)->SetName("Town");
	}
}

BuildController::~BuildController() {
	delete houseModel->GetMesh();
	delete houseModel->GetMaterial();
	for (int i = 0; i < placedEntities.size(); i++) {
		delete placedEntities.at(i);
	}
}