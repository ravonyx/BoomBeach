#include "BuildingFactory.h"

BuildingFactory::BuildingFactory()
{
	Building* house = new Building(0, "QG", 1, 1000, 500, 0, 1.1, 1.3, 1, 4, 4, Zone());
	Building* snipertower = new Building(0, "SniperTower", 2, 500, 100, 0, 1.3, 1.2, 4, 2, 2, Zone());
	Building* lanceflamme = new Building(0, "LanceFlamme", 3, 800, 300, 0, 1.2, 1.3, 2, 2, 3, Zone());
	Building* mitrailleuse = new Building(0, "Mitrailleuse", 4, 1000, 500, 0, 1.1, 1.3, 2, 4, 4, Zone());
	Building* repare = new Building(0, "RepareBuilding", 5, 1000, 500, 0, 1.1, 1.3, 2, 4, 4, Zone());
	Building* shield = new Building(0, "ShieldBuilding", 6, 1000, 500, 0, 1.1, 1.3, 3, 4, 4, Zone());
	Building* energy = new Building(0, "EnergyBuilding", 7, 1000, 500, 0, 1.1, 1.3, 1, 4, 4, Zone());

	buildingModels.push_back(house);
	buildingModels.push_back(snipertower);
	buildingModels.push_back(lanceflamme);
	buildingModels.push_back(mitrailleuse);
	buildingModels.push_back(repare);
	buildingModels.push_back(shield);
	buildingModels.push_back(energy);
}

Building* BuildingFactory::build(std::string name)
{
	if (nameInList(name))
	{
		for (int i = 0; i < buildingModels.size(); i++)
		{
			if (buildingModels[i]->getName() == name)
			{
				if (buildingModels[i]->getMaxInstances() > getInstances(name))
				{
					Building *building = new Building(*(buildingModels[i]));
					instances[i]++;
					return building;
				}
				else
				{
					std::cout << "Max instances of " << name << std::endl;
					return nullptr;
				}
			}
		}
	}
	else
	{
		std::cout << "Wrong name" << std::endl;
		return nullptr;
	}
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
	int id = 0, level = 0, x = 0, y = 0, type = 0;
	std::string name;
	std::string junk;

	stream >> id;
	stream >> name;
	stream >> type;
	stream >> level;
	stream >> x;
	stream >> y;

	Building *buildingModel = getBuildingModel(name);
	Zone zone = Zone(buildingModel->getWidth(), buildingModel->getHeight(), x, y);
	zone.setId(id);
	
	Building *building = new Building(id, name, type, 0, 0, level, buildingModel->getHealthUpdateRate(), 
		buildingModel->getCostUpdateRate(), buildingModel->getMaxInstances(), buildingModel->getWidth(), buildingModel->getHeight(), zone);

	building->setHeathCost(buildingModel->getLife(), buildingModel->getCost(), level);
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

int BuildingFactory::getInstances(std::string name)
{
	for (int i = 0; i < buildingModels.size(); i++)
	{
		if (buildingModels[i]->getName() == name)
			return instances[i];
	}
}