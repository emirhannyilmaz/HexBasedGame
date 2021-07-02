#include "SaleableProperty.h"

SaleableProperty::SaleableProperty(int _price) {
	price = _price;
	lastTryTime = glfwGetTime();
}

void SaleableProperty::Update(Text& moneyText) {
	if (!GetIsSold()) {
		if (glfwGetTime() - lastTryTime >= 10.0f) {
			int random = rand() % 5;
			if (random == 3) {
				PlayerStats::SetMoney(PlayerStats::GetMoney() + price);
				moneyText.SetText("Money: " + std::to_string(PlayerStats::GetMoney()));
				SetIsSold(true);
			}
			lastTryTime = glfwGetTime();
		}
	}
}

bool SaleableProperty::GetIsSold() {
	return isSold;
}

void SaleableProperty::SetIsSold(bool value) {
	isSold = value;
}