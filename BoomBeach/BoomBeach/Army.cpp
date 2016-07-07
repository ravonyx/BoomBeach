#include "Army.h"
#include <fstream>
#include <iostream>

//using namespace std;


Army::Army()
{
	_unitFactory = new UnitFactory();
}

bool Army::addUnit(const char* name)
{
	int cost = 0;
	std::cout << std::endl;
	if (_unitFactory == NULL)
		std::cout << "Unit factory not initialised" << std::endl;
	else
	{
		Unit* unit = _unitFactory->create(name);
		if (unit != nullptr && unit->getCost() <= _money)
		{
			cost = unit->getCost();
			_unitFactory->addInstances(name);
			//unit->setId(_currentId);
			//_currentId++;
			_units.push_back(unit);
			_money -= cost;
			std::cout << "Suceed to create unit" << std::endl;
			return true;
		}
		else if (unit != nullptr && unit->getCost() >_money)
			std::cout << "Not enough money" << std::endl;
	}
	std::cout << "Fail to create unit" << std::endl;
	return false;
}

void Army::DeleteUnit(Unit & unit)
{
	int id = 0;
	for (size_t i = 0; i < _units.size(); i++)
	{
		if (_units[i]->getType() == unit.getType() && _units[i]->getLevel() && unit.getLevel()) {
			id = i;
			break;
		}
	}
	_units.erase(_units.begin() + id);
}

void Army::DeleteUnit(int type, int level)
{
	int unitIndex = -1;
	for (size_t i = 0; i < _units.size(); i++)
	{
		if (_units[i]->getType() == type && _units[i]->getLevel() == level) {
			unitIndex = i;
			break;
		}
	}
	if (unitIndex != -1) {
		_units.erase(_units.begin() + unitIndex);
	}
}

std::vector<Unit*> Army::getUnitsPossibilities()
{
	return _unitFactory->getUnitModels();
}

std::vector<Unit*> Army::getCurrentUnits()
{
	return _units;
}

UnitFactory* Army::getUnitFactory()
{
	return _unitFactory;
}

void Army::SaveArmy()
{
	std::cout << "Saving army" << std::endl;
	std::ofstream myfile;
	myfile.open("saveArmy.txt", std::ios::out | std::ios::trunc);
	if (myfile.is_open())
	{
		myfile << _money;
		myfile << std::endl;

		myfile << "NbUnits: " << _units.size();
		myfile << std::endl;
		for (unsigned int i = 0; i < _units.size(); i++)
		{
			myfile << (*_units[i]);
		}
	}
	myfile.close();
}

void Army::LoadArmy()
{
	_units.clear();
	int nbUnits = 0;
	std::ifstream myfile("saveArmy.txt", std::ios::in);
	if (myfile.is_open())
	{
		myfile >> _money;
		std::string junk;
		myfile >> junk;
		myfile >> nbUnits;
		for (int i = 0; i < nbUnits; i++)
		{
			_units.push_back(_unitFactory->readNextUnit(myfile));
			//_currentId++;
		}
	}
	myfile.close();
}