#include "PlayerStats.h"

int PlayerStats::money = 2000;

int PlayerStats::GetMoney() {
	return money;
}

void PlayerStats::SetMoney(int value) {
	PlayerStats::money = value;
}