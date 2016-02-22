#pragma once
#include "Unit.h"
#include <vector>

class Army
{
private : 
	int money = 2000;
public:
	Army();
	std::vector<Unit> _unitArray;
	void AddUnit(Unit &unit);
	void DeleteUnit(Unit &unit);
	void DestroyUnit(unitType type, int level);
	void SaveArmy();
	void LoadArmy();
	int getMoney() { return money; }
	void setMoney(int _money) { money = _money; }
	~Army();
};

