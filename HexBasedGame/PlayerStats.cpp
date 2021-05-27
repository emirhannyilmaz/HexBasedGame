#include "PlayerStats.h"

int PlayerStats::goldCount = 200;
int PlayerStats::woodCount = 500;

int PlayerStats::GetGoldCount() {
	return goldCount;
}

void PlayerStats::SetGoldCount(int value) {
	PlayerStats::goldCount = value;
}

int PlayerStats::GetWoodCount() {
	return PlayerStats::woodCount;
}

void PlayerStats::SetWoodCount(int value) {
	PlayerStats::woodCount = value;
}