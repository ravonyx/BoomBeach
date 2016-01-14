#pragma once

#include <vector>
#include <string>

#include "Building.h"

class BuildingFactory
{
	private:
		std::vector <Building>buildingList;
		
	public:
		BuildingFactory();
		Building* build(std::string name);
		Building* readNextBuilding(std::istream &stream);
};