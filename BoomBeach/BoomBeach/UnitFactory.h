#pragma once

#include "Unit.h"
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
	Unit* Create(unitType name)
	{
		if (nameInList(name))
		{
			Unit *unit = new Unit(name);
			return unit;
		}
		return nullptr;
	}
	Unit* ReadNextUnit(std::istream &stream);
	~UnitFactory();
};

