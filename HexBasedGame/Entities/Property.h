#pragma once

#include <iostream>
#include "Text.h"
#include "../PlayerStats.h"
#include <GLFW/glfw3.h>

class Property {
public:
	Property(int _income, int _expense);
	void Update(Text& moneyText);
	void SetIncome(int _income);
	void SetExpense(int _expense);
private:
	int income;
	int expense;
	float lastIncomeTime;
	float lastExpenseTime;
};