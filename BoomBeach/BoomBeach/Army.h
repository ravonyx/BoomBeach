#pragma once
#include "Unit.h"
#include <vector>

class Army
{
public:
	Army();
	std::vector<Unit> _unitArray;
	void AddUnit(Unit &unit);
	void DestroyUnit(unitType type, int level);
	void SaveArmy();
	void LoadArmy();
	~Army();
};

