#include "BuildingFactory.h"

BuildingFactory::BuildingFactory()
{
	Building* tower = new Building(0, "Tower", 500, 100, 0, 0.3, 0.2, 4, 2, 2, Zone());
	Building* mortar = new Building(0, "Mortar", 800, 300, 0, 0.2, 0.3, 2, 2, 3, Zone());
	Building* house = new Building(0, "House", 1000, 500, 0, 0.1, 0.3, 1, 4, 4, Zone());

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
	int id = 0, level = 0, x = 0, y = 0;
	std::string name;
	std::string junk;

	stream >> junk;
	stream >> id;
	stream >> junk;
	stream >> name;
	stream >> junk;
	stream >> level;
	stream >> junk;
	stream >> x;
	stream >> junk;
	stream >> y;

	Building *buildingModel = getBuildingModel(name);
	Zone zone = Zone(buildingModel->getWidth(), buildingModel->getHeight(), x, y);
	zone.setId(id);
	Building *building = new Building(id, name, buildingModel->getLife(), buildingModel->getCost(), level, buildingModel->getHealthUpdateRate(), 
		buildingModel->getCostUpdateRate(), buildingModel->getMaxInstances(), buildingModel->getWidth(), buildingModel->getHeight(), zone);
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