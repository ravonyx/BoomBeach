#include "Base.h"
#include <algorithm> 

Base::Base()
{
	field = new Field();
	money = 1500;
}

Base::Base(Field *pf, int pmoney)
{
	field = pf;
	money = pmoney;
}

Base::~Base()
{
	delete &field;
}

bool Base::DestroyBuilding(int id)
{
	Building* building = GetBuilding(id);
	if (building != nullptr)
	{
		std::cout << "Erase building " << building->getId() << std::endl;
		std::vector<Building*>::iterator it;
		it = find(buildings.begin(), buildings.end(), building);
		buildings.erase(it);
		field->Erase(building->getZone());
		return true;
	}

	std::cout << "L'id n'existe pas" << std::endl;
	return false;
}

bool Base::AddBuilding(BuildingFactory *buildingFactory, const char *name)
{
	int instances(0);
	int max(0);
	if (buildingFactory == NULL)
		std::cout << "Building factory not initialised" << std::endl;
	else
	{
		
		for (int i = 0; i < buildings.size();i++)
		{
			if (buildings[i]->getName().compare(std::string(name)) == 0)
			{
				max = buildings[i]->getMaxInstances();
				instances++;
			}
				
		}
		if (instances < max) 
		{
			Building* building = buildingFactory->build(name);
			if (building != nullptr && building->getCost() < money)
			{
				Zone zoneToBuild = field->FindEmptyZone(building->getWidth(), building->getHeight());
				if (!zoneToBuild.isEmpty())
				{
					building->setId(_currentId);
					zoneToBuild.setId(_currentId);
					building->setZone(zoneToBuild);
					_currentId++;
					field->Build(zoneToBuild);
					buildings.push_back(building);

					money -= building->getCost();
					return true;
				}
				else
					std::cout << "No more space for building" << std::endl;

			}
			else if (building->getCost() > money)
				std::cout << "Not enough money" << std::endl;
			else
				std::cout << "Building name does not exist" << std::endl;
		}
		else
		{
			std::cout << "Cannot create another " << name << " building" << std::endl;
		}
		
	}
	std::cout << "Fail to build building" << std::endl;
	return false;
}

void Base::EnhanceBuilding(int id)
{
	if (money >= buildings[id]->getCost() ) 
	{
		buildings[id]->levelUp();
	}
	else
	{
		std::cout << "Cannot Upgrade This Building" << std::endl;
	}
}

void Base::printBuildings()
{
	if (buildings.size() <= 0)
		std::cout << "No buildings";
	else
	{
		for (int i = 0; i < buildings.size(); i++)
		{
			std::cout << *(buildings[i]) << std::endl;
		}
	}
}

void Base::saveBase()
{
	std::cout << "Saving" << std::endl;
	std::ofstream myfile;
	myfile.open("base.txt", std::ofstream::out | std::ofstream::trunc);
	if (myfile.is_open())
	{
		myfile << money;
		myfile << std::endl;
		myfile << *field;
	}
	myfile.close();
}

void Base::loadBase()
{
	std::string line;
	std::ifstream myfile("base.txt", std::ios::in);
	if (myfile.is_open())
	{
		//On trouve l'argent
		myfile >> money;

		myfile >> *field;
		myfile.close();
	}
	else std::cout << "Impossible d'ouvrir Base";
}

Building* Base::GetBuilding(int id)
{
	for (int i = 0; i < buildings.size(); i++)
	{
		if (buildings[i]->getId() == id)
		{
			return buildings[i];
		}
	}
	return nullptr;
}

Field* Base::getField()
{
	return field;
}
