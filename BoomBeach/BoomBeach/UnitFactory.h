#pragma once

#include "Unit.h"
#include "Army.h"
#include <vector>
#include <string>
#include <iostream>

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
	Unit* CreateUnit(const unitType type, Army &army)
	{
		if (nameInList(type))
		{
			Unit *unit = new Unit(type);
			if (army.getMoney() - unit->cost > 0){
				if (army.NumberOfInstance(type) < unit->maxInstances) {
					army.AddUnit(*unit);
					army.setMoney(army.getMoney() - unit->cost);
					return unit;
				}else
					std::cout << "Too many units of this type" << std::endl;
			}else
				std::cout << "Not enought gold" << std::endl;
		}
		return nullptr;
	}
	Unit* ReadNextUnit(std::istream &stream);
	~UnitFactory();
};

