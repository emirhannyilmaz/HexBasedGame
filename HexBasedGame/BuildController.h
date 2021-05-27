#pragma once

#include <iostream>
#include "Entities/Entity.h"
#include "Renderer/EntityRenderer/ObjLoader.h"
#include <vector>
#include "Entities/Text.h"
#include "PlayerStats.h"
#include "Entities/Buildings/House.h"
#include "Entities/Buildings/Sawmill.h"
#include "Entities/Buildings/Hex.h"

class BuildController {
public:
	BuildController(std::vector<Entity*>* _entities, std::vector<Hex*> _hexes, Text* _hexNameText, Text* _goldCountText, Text* _woodCountText, std::vector<ResourceGenerator*>* _resourceGenerators);
	void BuildTown();
	void BuildSawmill();
	~BuildController();
private:
	std::vector<Entity*>* entities;
	std::vector<Hex*> hexes;
	std::vector<ResourceGenerator*>* resourceGenerators;
	std::vector<House*> placedHouses;
	std::vector<Sawmill*> placedSawmills;
	Text* hexNameText;
	Text* goldCountText;
	Text* woodCountText;
	Model* houseModel = NULL;
	Model* sawmillModel = NULL;
};