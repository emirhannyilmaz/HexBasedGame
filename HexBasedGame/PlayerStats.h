#pragma once

class PlayerStats {
public:
	static int GetGoldCount();
	static void SetGoldCount(int value);
	static int GetWoodCount();
	static void SetWoodCount(int value);
private:
	static int goldCount;
	static int woodCount;
};