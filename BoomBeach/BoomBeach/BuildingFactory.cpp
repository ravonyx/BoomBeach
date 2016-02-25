#include "BuildingFactory.h"

BuildingFactory::BuildingFactory()
{
	Building* tower = new Building(0, "Tower", 500, 100, 0, 1.3, 1.2, 4, 2, 2, Zone());
	Building* mortar = new Building(0, "Mortar", 800, 300, 0, 1.2, 1.3, 2, 2, 3, Zone());
	Building* house = new Building(0, "House", 1000, 500, 0, 1.1, 1.3, 1, 4, 4, Zone());

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
			{
				std::cout << "Max instances of " << name << std::endl;
				return nullptr;
			}
		}
	}
	std::cout << "Wrong name" << std::endl;
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
	int id = 0, level = 0, x = 0, y = 0;
	std::string name;
	std::string junk;

	stream >> id;
	stream >> name;
	stream >> level;
	stream >> x;
	stream >> y;

	Building *buildingModel = getBuildingModel(name);
	Zone zone = Zone(buildingModel->getWidth(), buildingModel->getHeight(), x, y);
	zone.setId(id);
	
	Building *building = new Building(id, name, 0, 0, level, buildingModel->getHealthUpdateRate(), 
		buildingModel->getCostUpdateRate(), buildingModel->getMaxInstances(), buildingModel->getWidth(), buildingModel->getHeight(), zone);

	building->setHeathCost(buildingModel->getLife(), buildingModel->getCost(), level);
	std::cout << building->getLife() << " " << building->getCost() << std::endl;
	return building;
}

Building* BuildingFactory::getBuildingModel(std::string name)
{
	for (int i = 0; i < buildingModels.size(); i++)
	{
		if (buildingModels[i]->name == name)
			return buildingModels[i];
	}
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