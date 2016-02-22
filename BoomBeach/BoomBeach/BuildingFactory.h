#pragma once

#include <vector>
#include <string>

#include "Building.h"

class BuildingFactory
{
	private:
		//std::vector <Building>buildingList;
		std::vector <Building*>buildingModels;
		bool nameInList(std::string name);
	public:
		BuildingFactory();
		Building* build(std::string name)
		{
			for (int i = 0; i < buildingModels.size(); i++)
			{
				if (buildingModels[i]->getName() == name)
				{
					Building *building = new Building(*(buildingModels[i]));
					return building;
				}
			}
			return nullptr;
		}
		Building* readNextBuilding(std::istream &stream);
		friend std::ostream& operator << (std::ostream& os, const BuildingFactory& bf)
		{
			for (int i = 0; i < bf.buildingModels.size(); i++)
			{
				os << *(bf.buildingModels[i]) << std::endl;
			}
			return os;
		}
};