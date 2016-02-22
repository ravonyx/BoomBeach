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

void Army::DestroyUnit(unitType type, int level)
{
	for (size_t i = 0; i < _unitArray.size(); i++)
	{
		int unitIndex = -1;
		if (_unitArray[i].getType() == type && _unitArray[i].getLevel() == level) {
			unitIndex = 1;
			break;
		}
		if (unitIndex != -1) {
			_unitArray.erase(_unitArray.begin() + unitIndex);
		}
	}
}

void Army::SaveArmy()
{
	std::ofstream fichier;

	fichier.open("saveArmy.txt", std::ios::out | std::ios::trunc);  //déclaration du flux et ouverture du fichier

	//fichier.fail() lecture
	if (fichier.bad()) //permet de tester si le fichier s'est ouvert sans probleme 
		std::cout << "Impossible de sauvegarder !" << std::endl;

	if (fichier)  // si l'ouverture a réussi
	{
		std::cout << "Sauvergarde en cours" << std::endl;
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
		std::cout << "Sauvergade OK !" << std::endl;
	}
	else  // sinon
		std::cerr << "Impossible de sauvegarder !" << std::endl;
}

void Army::LoadArmy()
{
	std::ifstream fichier("saveArmy.txt", std::ios::in);

	if (!fichier.fail())
	{
		_unitArray.clear();
		std::cout << "Chargement de la sauvergarde en cours" << std::endl;

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
		std::cerr << "Impossible de charger la sauvegarde !" << std::endl;
}

Army::~Army()
{
}
