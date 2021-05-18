#pragma once

#include <iostream>
#include "Entities/Entity.h"
#include "Renderer/EntityRenderer/ObjLoader.h"
#include <vector>
#include "Entities/Text.h"

class BuildController {
public:
	BuildController(std::vector<Entity*>* _entities, Text* _hexNameText);
	void BuildTown();
	~BuildController();
private:
	std::vector<Entity*>* entities;
	std::vector<Entity*> placedEntities;
	Model* houseModel = NULL;
	std::vector<Collider> houseColliders;
	Text* hexNameText;
};