#pragma once

class PlayerStats {
public:
	static int GetMoney();
	static void SetMoney(int value);
private:
	static int money;
};