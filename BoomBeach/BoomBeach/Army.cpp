#include "Army.h"
#include <fstream>
#include <iostream>
#include "Field.h"
#include <algorithm>

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
			unit->setId(_currentId);
			_currentId++;
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

bool Army::addAttackUnit(int id, int x, int y)
{
	std::cout << std::endl;
	int index = getIndexOfUnit(id);
	if (index != -1)
	{
		AttackUnit* attackUnit = new AttackUnit(*_units[index]);
		attackUnit->setPosition(x, y);
		_attackUnits.push_back(attackUnit);
		return true;
	}
	else
		std::cout << "Wrong ID" << std::endl;
	return false;
}

void Army::enhanceUnit(int id)
{
	std::cout << std::endl;
	int index = getIndexOfUnit(id);
	if (index != -1)
	{
		if (_money >= _units[index]->getCost())
		{
			int cost = _units[index]->levelUp();
			std::cout << "Cost you " << cost + 1 << " gold" << std::endl;
			_money -= _units[index]->getCost();
		}
		else
			std::cout << "Not enough money to upgrade" << std::endl;
	}
	else
		std::cout << "Wrong ID" << std::endl;
}

bool Army::deleteUnit(int id)
{
	Unit* unit = getUnit(id);
	if (unit != nullptr)
	{
		std::cout << "Erase unit " << unit->getId() << std::endl;
		std::vector<Unit*>::iterator it;
		it = find(_units.begin(), _units.end(), unit);
		_units.erase(it);
		_unitFactory->removeInstances(unit->getName());
		_currentId = 1;
		for (int i = 0; i < _units.size(); i++)
		{
			_units[i]->setId(_currentId);
			_currentId++;
		}

		return true;
	}
	std::cout << "L'id n'existe pas" << std::endl;
	return false;
}

bool Army::moveUnit(int id, std::pair<int, int> position)
{
	int index = getIndexOfAttackUnit(id);
	if (index != -1)
	{
		_attackUnits[index]->setPosition(_attackUnits[index]->position.first + std::max(-1, std::min(position.first - _attackUnits[index]->position.first, 1)),
			(_attackUnits[index]->position.second + std::max(-1, std::min(position.second - _attackUnits[index]->position.second, 1))));
		//std::cout << "x=" << _attackUnits[index]->position.first << "y=" << _attackUnits[index]->position.second << "    " << position.first << std::endl;
		return true;
	}
	else
		std::cout << "Wrong ID" << std::endl;
	return false;
}

/*void Army::DeleteUnit(Unit & unit)
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
}*/

Unit* Army::getUnit(int id)
{
	for (unsigned int i = 0; i < _units.size(); i++)
	{
		if (_units[i]->getId() == id)
			return _units[i];
	}
	return nullptr;
}
int Army::getIndexOfUnit(int id)
{
	for (unsigned int i = 0; i < _units.size(); i++)
	{
		if (_units[i]->getId() == id)
			return i;
	}
	return -1;
}

int Army::getIndexOfAttackUnit(int id)
{
	for (unsigned int i = 0; i < _attackUnits.size(); i++)
	{
		if (_attackUnits[i]->getId() == id)
			return i;
	}
	return -1;
}

std::vector<Unit*> Army::getUnitsPossibilities()
{
	return _unitFactory->getUnitModels();
}

std::vector<Unit*> Army::getCurrentUnits()
{
	return _units;
}

std::vector<AttackUnit*> Army::getCurrentAttackUnits()
{
	return _attackUnits;
}

UnitFactory* Army::getUnitFactory()
{
	return _unitFactory;
}

void Army::saveArmy()
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

void Army::loadArmy()
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
			_currentId++;
		}
	}
	myfile.close();
}