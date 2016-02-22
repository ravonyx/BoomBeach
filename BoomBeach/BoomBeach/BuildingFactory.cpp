#include "BuildingFactory.h"

BuildingFactory::BuildingFactory()
{
	Building* tower = new Building("Tower", 500, 100, 0.3, 0.2, 4, 2, 2);
	Building* mortar = new Building("Mortar", 800, 300, 0.2, 0.3, 2, 2, 3);
	Building* house = new Building("House", 1000, 500, 0.1, 0.3, 1, 4, 4);

	buildingModels.push_back(tower);
	buildingModels.push_back(mortar);
	buildingModels.push_back(house);
}

bool BuildingFactory::nameInList(std::string name)
{
	for (int i = 0; i < buildingModels.size(); i++)
	{
		if (name == buildingModels[i]->getName())
		{
			return true;
		}
	}
	return false;
}

Building* BuildingFactory::readNextBuilding(std::istream &stream)
{
	std::string readline;
	getline(stream, readline);
	return nullptr;
}