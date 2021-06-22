#pragma once

#include <iostream>
#include "Entities/Entity.h"
#include "Renderer/EntityRenderer/ObjLoader.h"
#include <vector>
#include "Entities/Text.h"
#include "PlayerStats.h"
#include "Entities/Buildings/Hex.h"
#include "Entities/Buildings/Hotel.h"
#include "Entities/Buildings/Concrete.h"
#include "Entities/Property.h"

class BuildController {
public:
	BuildController(std::vector<Entity*>* _entities, std::vector<Light*>* _lights, std::vector<Hex*> _hexes, Text* _hexNameText, Text* _moneyText, std::vector<Property*>* _properties);
	void BuildHotel();
	~BuildController();
private:
	std::vector<Entity*>* entities;
	std::vector<Light*>* lights;
	std::vector<Light*> placedLights;
	std::vector<Hex*> hexes;
	std::vector<Concrete*> placedConcretes;
	std::vector<Hotel*> placedHotels;
	Text* hexNameText;
	Text* moneyText;
	std::vector<Property*>* properties;
	Model* hotelModel = NULL;
	Model* concreteModel = NULL;
	std::vector<Light> hotelLights;
};