#include "Army.h"
#include <fstream>
#include <iostream>

//using namespace std;


Army::Army()
{
}

void Army::AddUnit(Unit &unit)
{
	_unitArray.push_back(unit);
}

void Army::DeleteUnit(Unit & unit)
{
	int id = 0;
	for (size_t i = 0; i < _unitArray.size(); i++)
	{
		if (_unitArray[i].getType() == unit.getType() && _unitArray[i].getLevel() && unit.getLevel()) {
			id = i;
			break;
		}
	}
	_unitArray.erase(_unitArray.begin() + id);
}

void Army::DeleteUnit(unitType type, int level)
{
	int unitIndex = -1;
	for (size_t i = 0; i < _unitArray.size(); i++)
	{
		if (_unitArray[i].getType() == type && _unitArray[i].getLevel() == level) {
			unitIndex = i;
			break;
		}
	}
	if (unitIndex != -1) {
		_unitArray.erase(_unitArray.begin() + unitIndex);
	}
}

void Army::showUnits()
{

}

int Army::NumberOfInstance(unitType type)
{
	int result = 0;
	for (size_t i = 0; i < _unitArray.size(); i++)
	{
		if (_unitArray[i].getType() == type) {
			result++;
		}
	}
	return result;
}

void Army::SaveArmy()
{
	std::cout << "Army step" << std::endl;
	std::ofstream fichier;

	fichier.open("saveArmy.txt", std::ios::out | std::ios::trunc);  //déclaration du flux et ouverture du fichier

	//fichier.fail() lecture
	if (fichier.bad()) //permet de tester si le fichier s'est ouvert sans probleme 
		std::cout << "Save faild !" << std::endl;

	if (fichier)  // si l'ouverture a réussi
	{
		std::cout << "Save in progress" << std::endl;
		// instructions
		fichier.seekp(0, std::ios::end);
		fichier << getMoney() << std::endl;
		for (size_t i = 0; i < _unitArray.size(); i++)
		{
			fichier << _unitArray[i].getType() << " " << _unitArray[i].getLevel();
			if (i != _unitArray.size() - 1) {
				fichier << std::endl;
			}
		}

		fichier.close();  // on ferme le fichier
		std::cout << "Save complete !" << std::endl;
	}
	else  // sinon
		std::cerr << "Save faild !" << std::endl;
}

void Army::LoadArmy()
{
	std::cout << "Army step" << std::endl;
	std::ifstream fichier("saveArmy.txt", std::ios::in);

	if (!fichier.fail())
	{
		_unitArray.clear();
		std::cout << "Loading save in progress" << std::endl;

		std::string ligne{}; // Une variable pour stocker les lignes lues
		int type{};
		int level{};
		int money{};

		fichier >> money;
		this->setMoney(money);

		while (getline(fichier, ligne)) // Tant qu'on n'est pas à la fin, on lit
		{
			fichier >> type;
			fichier >> level;
			Unit *unit = new Unit(unitType(type), level);
			AddUnit(*unit);
			//std::cout << unit->getName() << " " << unit->getLevel() << std::endl;
		}

		fichier.close();
	}
	else
		std::cerr << "Save faild !" << std::endl;
}

Army::~Army()
{
}
