#include "Base.h"
#include "Tools.h"

Base::Base()
{
	_buildingFactory = new BuildingFactory();
	_field = new Field();
	_money = 5000;
}

Base::Base(Field *pf, int pmoney)
{
	_field = pf;
	_money = pmoney;
}

Base::Base(const Base &base)
{
	_field = base._field;
	_money = base._money;
	_buildingFactory = base._buildingFactory;
	_buildings = base._buildings;
	_currentId = base._currentId;
}

Base& Base::operator=(const Base& base) 
{
	_field = base._field;
	_money = base._money;
	_buildingFactory = base._buildingFactory;
	_buildings = base._buildings;
	_currentId = base._currentId;
	return *this;
}

Base::~Base()
{
	delete _field;
	delete _buildingFactory;
	for (unsigned int i = 0; i < _buildings.size(); i++)
	{
		delete _buildings[i];
	}
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
		_buildingFactory->removeInstances(building->getName());
		_field->Erase(building->getZone());

		_currentId = 1;
		for (unsigned int i = 0; i < _buildings.size(); i++)
		{
			_buildings[i]->setId(_currentId);
			_currentId++;
		}

		return true;
	}
	std::cout << "L'id n'existe pas" << std::endl;
	return false;
}

bool Base::addBuilding(const char *name, int x, int y)
{
	int cost = 0;
	std::cout << std::endl;
	if (_buildingFactory == NULL)
		std::cout << "Building factory not initialised" << std::endl;
	else
	{
		Building* building = _buildingFactory->build(name);
		if (building != nullptr && building->getCost() <= _money)
		{
			cost = building->getCost();
			Zone zoneToBuild;
			if (x == -1 || y == -1)
				zoneToBuild = _field->FindEmptyZone(building->getWidth(), building->getHeight());
			else
				zoneToBuild = _field->FindEmptyZoneWithInd(building->getWidth(), building->getHeight(), x, y);
			if (!zoneToBuild.isEmpty())
			{
				_buildingFactory->addInstances(name);
				building->setId(_currentId);
				zoneToBuild.setId(building->getType());

				building->setZone(zoneToBuild);
				_currentId++;
				_field->Build(zoneToBuild);
				_buildings.push_back(building);

				_money -= cost;

				// Rule for QG HPs
				int qGAddedHealth = 0;
				int qGindex = 0;
				bool finded = false;
				for (unsigned int i = 0; i < _buildings.size(); i++)
				{
					if (_buildings[i]->getType() != 1)
					{
						qGAddedHealth += _buildings[i]->getLife() * 0.1f;
					}
					else
					{
						finded = true;
						qGindex = i;
					}
				}
				if(finded)
					_buildings[qGindex]->setAddedLife(qGAddedHealth);


				std::cout << "Suceed to build building" << std::endl;
				return true;
			}
			else
				std::cout << "No more space for building" << std::endl;
		}
		else if(building != nullptr && building->getCost() > _money)
			std::cout << "Not enough money" << std::endl;
	}
	std::cout << "Fail to build building" << std::endl;
	return false;
}

void Base::enhanceBuilding(int id)
{
	std::cout << std::endl;
	int index = getIndexOfBuilding(id);
	if (index != -1)
	{
		if (_money >= _buildings[index]->getCost())
		{
			int cost = _buildings[index]->levelUp();
			std::cout << "Cost you " << cost+1 << " gold" << std::endl;
			_money -= _buildings[index]->getCost();
		}
		else
			std::cout << "Not enough money to upgrade" << std::endl;
	}
	else
		std::cout << "Wrong ID" << std::endl;
}

void Base::printBuildings()
{
	if (_buildings.size() <= 0)
		std::cout << "No buildings";
	else
	{
		for (unsigned int i = 0; i < _buildings.size(); i++)
		{
			std::cout << *(_buildings[i]);
		}
	}
	std::cout << std::endl;
}

void Base::saveBase()
{
	std::cout << "Saving base" << std::endl;
	std::ofstream myfile;
	myfile.open("base.txt", std::ofstream::out | std::ofstream::trunc);
	if (myfile.is_open())
	{
		myfile << _money;
		myfile << std::endl;

		myfile << "NbBuildings: " << _buildings.size();
		myfile << std::endl;
		for (unsigned int i = 0; i < _buildings.size(); i++)
		{
			myfile << (*_buildings[i]);
		}
		myfile << *_field;
	}
	myfile.close();
}

void Base::loadBase()
{
	_buildings.clear();
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
			_currentId++;
		}
		myfile >> *_field;
	}
	myfile.close();
}

Building* Base::getBuilding(int id)
{
	for (unsigned int i = 0; i < _buildings.size(); i++)
	{
		if (_buildings[i]->getId() == id)
			return _buildings[i];
	}
	return nullptr;
}

int Base::getIndexOfBuilding(int id)
{
	for (unsigned int i = 0; i < _buildings.size(); i++)
	{
		if (_buildings[i]->getId() == id)
			return i;
	}
	return -1;
}

Field* Base::getField() const
{
	return _field;
}

int Base::getMoney() const
{
	return _money;
}

std::vector<Building*> Base::getBuildingsPossibilities()
{
	return _buildingFactory->getBuidingModels();
}

std::vector<Building*> Base::getCurrentBuildings()
{
	return _buildings;
}

Building * Base::GetNearestBuilding(int x, int y)
{
	float minLenght = 100;
	float currentLenght = 0;
	int minBuilding = 0;
	for (unsigned int i = 0; i < _buildings.size(); i++)
	{
		currentLenght = distance(_buildings[i]->getZone().getX(), _buildings[i]->getZone().getY(), x, y);
		if (currentLenght < minLenght) {
			minLenght = currentLenght;
			minBuilding = i;
		}
	}
	
	if(_buildings.size() > 0)
		return _buildings[minBuilding];
	else
	{
		return nullptr;
	}
}

BuildingFactory* Base::getBuildingFactory()
{
	return _buildingFactory;
}