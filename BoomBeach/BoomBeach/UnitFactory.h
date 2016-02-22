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
	void CreateUnit(const unitType type, Army &army)
	{
		if (nameInList(type))
		{
			Unit *unit = new Unit(type);
			if (army.getMoney() - unit->cost > 0) {
				army.AddUnit(*unit);
				army.setMoney(army.getMoney() - unit->cost);
			}
		}
	}
	Unit* ReadNextUnit(std::istream &stream);
	~UnitFactory();
};

