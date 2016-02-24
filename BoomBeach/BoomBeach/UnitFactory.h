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
	Unit* CreateUnit(const unitType type, Army *army);
	Unit* ReadNextUnit(std::istream &stream);
	~UnitFactory();
};

