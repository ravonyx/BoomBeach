#pragma once
#include "Unit.h"
#include <vector>

class Army
{
public:
	Army();
	std::vector<Unit> _unitArray;
	void CreateUnit(unitType type);
	void DestroyUnit(unitType type, int level);
	~Army();
};

