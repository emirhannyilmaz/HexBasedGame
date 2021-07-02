#pragma once

#include <iostream>
#include "Text.h"
#include "../PlayerStats.h"
#include <GLFW/glfw3.h>

class SaleableProperty {
public:
	SaleableProperty(int _price);
	void Update(Text& moneyText);
	bool GetIsSold();
	void SetIsSold(bool value);
private:
	int price;
	bool isSold = false;
	float lastTryTime;
};