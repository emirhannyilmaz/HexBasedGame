#include "ResourceGenerator.h"

ResourceGenerator::ResourceGenerator(ResourceTypes _resourceType) {
	resourceType = _resourceType;
	lastResourceGiveTime = glfwGetTime();
}

void ResourceGenerator::Update(Text& resourceCountText) {
	if (glfwGetTime() - lastResourceGiveTime >= 10.0f) {
		switch (resourceType) {
			case GOLD:
				PlayerStats::SetGoldCount(PlayerStats::GetGoldCount() + 50);
				resourceCountText.SetText("Gold: " + std::to_string(PlayerStats::GetGoldCount()));
				break;
			case WOOD:
				PlayerStats::SetWoodCount(PlayerStats::GetWoodCount() + 100);
				resourceCountText.SetText("Wood: " + std::to_string(PlayerStats::GetWoodCount()));
				break;
			default:
				break;
		}
		lastResourceGiveTime = glfwGetTime();
	}
}

ResourceTypes ResourceGenerator::GetResourceType() {
	return resourceType;
}