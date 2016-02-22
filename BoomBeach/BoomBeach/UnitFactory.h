#pragma once

#include "Unit.h"
#include "Army.h"
#include <vector>
#include <string>

class UnitFactory
{
private:
	bool nameInList(unitType name);
	std::vector<std::pair<unitType, std::string>> unitTypes = { std::pair<unitType, std::string>(unitType::princess, "princess"), 
		std::pair<unitType, std::string>(unitType::mushroom, "mushroom"), 
		std::pair<unitType, std::string>(unitType::goodguy, "goodguy"), 
		std::pair<unitType, std::string>(unitType::badguy, "badguy") };
public:
	UnitFactory();
	std::vector<std::string>UnitList();
	friend std::ostream& operator<<(std::ostream& os, const Unit &unit);
	Unit* Create(const unitType type, Army &army)
	{
		if (nameInList(type))
		{
			Unit *unit = new Unit(type);
			army.AddUnit(*unit);
			return unit;
		}
		return nullptr;
	}
	Unit* ReadNextUnit(std::istream &stream);
	~UnitFactory();
};

