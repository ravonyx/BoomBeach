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
		Building* build(std::string name)
		{
			if (name != "")
			{
				Building *building = new Building();
				return building;
			}
			return nullptr;
		}
		Building* readNextBuilding(std::istream &stream);
};