#pragma once

#include <iostream>
#include <GLFW/glfw3.h>
#include "Text.h"
#include "../PlayerStats.h"

enum ResourceTypes {
	GOLD,
	WOOD
};

class ResourceGenerator {
public:
	ResourceGenerator(ResourceTypes _resourceType);
	void Update(Text& resourceCountText);
	ResourceTypes GetResourceType();
private:
	ResourceTypes resourceType;
	float lastResourceGiveTime;
};