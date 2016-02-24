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

Building* BuildingFactory::build(std::string name)
{
	for (int i = 0; i < buildingModels.size(); i++)
	{
		if (buildingModels[i]->getName() == name)
		{
			if (buildingModels[i]->getMaxInstances() > getInstances(name))
			{
				Building *building = new Building(*(buildingModels[i]));
				if (name == "Tower")
					instanceTower++;
				if (name == "Mortar")
					instanceMortar++;
				if (name == "House")
					instanceHouse++;
				return building;
			}
			else
				break;
		}
	}
	return nullptr;
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
	std::string junk;
	stream >> junk;
	std::cout << junk << std::endl;
	return nullptr;
}

void BuildingFactory::buildingList()
{
	for (int i = 0; i < buildingModels.size(); i++)
	{
		std::cout << "Name: " << buildingModels[i]->getName() << " Cost: " << buildingModels[i]->getCost() << " Life :" << buildingModels[i]->getLife() << std::endl;
	}
}

int BuildingFactory::getInstances(std::string name)
{
	if (name == "Tower")
		return instanceTower;
	else if (name == "Mortar")
		return instanceMortar;
	else if (name == "House")
		return instanceHouse;
}