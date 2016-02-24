#pragma once
#include "Unit.h"
#include <vector>

class Army
{
private : 
	int money = 20000;
public:
	Army();
	std::vector<Unit> _unitArray;
	void AddUnit(Unit &unit);
	void DeleteUnit(Unit &unit);
	void DeleteUnit(unitType type, int level);
	void showUnits();
	int NumberOfInstance(unitType type);
	void SaveArmy();
	void LoadArmy();
	int getMoney() { return money; }
	void setMoney(int _money) { money = _money; }
	~Army();

};

