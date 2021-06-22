#include "Property.h"

Property::Property(int _income, int _expense) {
	income = _income;
	expense = _expense;
	lastIncomeTime = glfwGetTime();
	lastExpenseTime = glfwGetTime();
}

void Property::Update(Text& moneyText) {
	if (glfwGetTime() - lastIncomeTime >= 24.0f) {
		PlayerStats::SetMoney(PlayerStats::GetMoney() + income);
		moneyText.SetText("Money: " + std::to_string(PlayerStats::GetMoney()));
		lastIncomeTime = glfwGetTime();
	}

	if (glfwGetTime() - lastExpenseTime >= 24.0f) {
		PlayerStats::SetMoney(PlayerStats::GetMoney() - expense);
		moneyText.SetText("Money: " + std::to_string(PlayerStats::GetMoney()));
		lastExpenseTime = glfwGetTime();
	}
}

void Property::SetIncome(int _income) {
	income = _income;
}

void Property::SetExpense(int _expense) {
	expense = _expense;
}