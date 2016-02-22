#pragma once

#include <vector>
#include <string>

#include "Building.h"

class BuildingFactory
{
	private:
		//std::vector <Building>buildingList;
		std::vector <std::string>buildingList;
		bool nameInList(std::string name);
	public:
		BuildingFactory();
		Building* build(std::string name)
		{
			if (nameInList(name))
			{
				Building *building = new Building();
				return building;
			}
			return nullptr;
		}
		Building* readNextBuilding(std::istream &stream);
};