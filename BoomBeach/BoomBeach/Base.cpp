#include "Base.h"
#include <algorithm> 

Base::Base()
{
	_buildingFactory = new BuildingFactory();
	_field = new Field();
	_money = 1500;
}

Base::Base(Field *pf, int pmoney)
{
	_field = pf;
	_money = pmoney;
}

Base::~Base()
{
	delete &_field;
}

bool Base::destroyBuilding(int id)
{
	Building* building = getBuilding(id);
	if (building != nullptr)
	{
		std::cout << "Erase building " << building->getId() << std::endl;
		std::vector<Building*>::iterator it;
		it = find(_buildings.begin(), _buildings.end(), building);
		_buildings.erase(it);
		_field->Erase(building->getZone());
		return true;
	}

	std::cout << "L'id n'existe pas" << std::endl;
	return false;
}

bool Base::addBuilding(const char *name)
{
	int instances(0);
	int max(0);
	if (_buildingFactory == NULL)
		std::cout << "Building factory not initialised" << std::endl;
	else
	{
		Building* building = _buildingFactory->build(name);
		if (building != nullptr && building->getCost() < _money)
		{
			Zone zoneToBuild = _field->FindEmptyZone(building->getWidth(), building->getHeight());
			if (!zoneToBuild.isEmpty())
			{
				building->setId(_currentId);
				zoneToBuild.setId(_currentId);
				building->setZone(zoneToBuild);
				_currentId++;
				_field->Build(zoneToBuild);
				_buildings.push_back(building);

				_money -= building->getCost();
				return true;
			}
			else
				std::cout << "No more space for building" << std::endl;
		}
		else if (building == nullptr)
			std::cout << "Max instances of " << name << std::endl;
		else
			std::cout << "Not enough money" << std::endl;
			
	}

	std::cout << "Fail to build building" << std::endl;
	return false;
}

void Base::enhanceBuilding(int id)
{
	if (_money >= _buildings[id]->getCost())
		_buildings[id]->levelUp();
	else
		std::cout << "Cannot Upgrade This Building" << std::endl;
}

void Base::printBuildings()
{
	if (_buildings.size() <= 0)
		std::cout << "No buildings";
	else
	{
		for (int i = 0; i < _buildings.size(); i++)
		{
			std::cout << *(buildings[i]) << std::endl;
		}
	}
}

void Base::printBuildingsPossibilies()
{
	_buildingFactory->buildingList();
}

void Base::saveBase()
{
	std::cout << "Saving" << std::endl;
	std::ofstream myfile;
	myfile.open("base.txt", std::ofstream::out | std::ofstream::trunc);
	if (myfile.is_open())
	{
		myfile << _money;
		myfile << std::endl;

		myfile << "NbBuildings: " << _buildings.size();
		myfile << std::endl;
		for (int i = 0; i < _buildings.size(); i++)
		{
			myfile << (*buildings[i]);
		}
		myfile << *_field;
	}
	myfile.close();
}

void Base::loadBase()
{
	int nbBuildings = 0;
	std::ifstream myfile("base.txt", std::ios::in);
	if (myfile.is_open())
	{
		myfile >> _money;
		std::string junk;
		myfile >> junk;
		myfile >> nbBuildings;
		for (int i = 0; i < nbBuildings; i++)
		{
			_buildings.push_back(_buildingFactory->readNextBuilding(myfile));
		}
		myfile >> *_field;
	}
	myfile.close();
}

Building* Base::getBuilding(int id)
{
	for (int i = 0; i < _buildings.size(); i++)
	{
		if (_buildings[i]->getId() == id)
			return _buildings[i];
	}
	return nullptr;
}

Field* Base::getField()
{
	return _field;
}
