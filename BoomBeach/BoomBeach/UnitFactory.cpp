#include "UnitFactory.h"

UnitFactory::UnitFactory()
{
	Unit* brute = new Unit(0, "Brute", 100, 1.3, 1.4, 2, 1.1, 1.3, 1.2, 2, 75, 2, 500);
	Unit* kamikaze = new Unit(1, "Kamikaze", 200, 1.2, 1.4, 4, 1.1, 1.3, 0, 2, 75, 2, 10);
	Unit* fusilleur = new Unit(2, "Fusilleur", 100, 1.2, 1.4, 3, 1.1, 1.3, 1.4, 2, 75, 2, 100);
	Unit* sniper = new Unit(3, "Sniper", 100, 1.1, 1.2, 2, 1.1, 1.3, 1.4, 2, 75, 2, 100);
	Unit* bazooka = new Unit(4, "Bazooka", 50, 1.2, 1.4, 2, 1.1, 1.3, 1.2, 2, 75, 2, 200);
	Unit* medecinContact = new Unit(5, "MedecinContact", 10, 1.2, 1.2, 4, 1.2, 1.4, 0, 3, 75, 0, 150);
	Unit* medecinSeringue = new Unit(6, "MedecinSeringue", 50, 1.2, 1.4, 3, 1.4, 1.3, 1.3, 4, 75, 2, 170);
	Unit* medecinZone = new Unit(7, "MedecinZone", 100, 1.2, 1.4, 2, 1.1, 1.3, 1.2, 2, 75, 2, 120);

	unitModels.push_back(brute);
	unitModels.push_back(kamikaze);
	unitModels.push_back(fusilleur);
	unitModels.push_back(sniper);
	unitModels.push_back(bazooka);
	unitModels.push_back(medecinContact);
	unitModels.push_back(medecinSeringue);
	unitModels.push_back(medecinZone);
}

Unit* UnitFactory::create(const std::string name)
{
	if (nameInList(name))
	{
		for (int i = 0; i < unitModels.size(); i++)
		{
			if (unitModels[i]->getName() == name)
			{
				if (unitModels[i]->getMaxInstances() > getInstances(name))
				{
					Unit *unit = new Unit(*(unitModels[i]));
					return unit;
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

bool UnitFactory::nameInList(std::string name)
{
	for (int i = 0; i < unitModels.size(); i++)
	{
		if (name == unitModels[i]->getName())
		{
			return true;
		}
	}
	return false;
}

Unit* UnitFactory::readNextUnit(std::istream & stream)
{
	std::string name;
	int level = 0, type = 0;

	stream >> type;
	stream >> name;
	stream >> level;

	Unit *unitModel = getUnitModel(name);
	Unit *unit = new Unit(type, name, 0, unitModel->getHealthUpdateRate(), unitModel->getCostUpdateRate(), unitModel->getMaxInstances(), unitModel->getAttackUpdateRate(), unitModel->getFireUpdateRate(), unitModel->getRangeUpdateRate(), 0, 0, 0, 0);

	unit->setAttributes(unitModel->getLife(), unitModel->getCost(), unitModel->getAttack(), unitModel->getFirerate(), unitModel->getRange(), level);
	instances[type]++;

	return unit;
}

int UnitFactory::getInstances(std::string name)
{
	for (int i = 0; i < unitModels.size(); i++)
	{
		if (unitModels[i]->getName() == name)
			return instances[i];
	}
}

void UnitFactory::addInstances(std::string name)
{
	for (int i = 0; i < unitModels.size(); i++)
	{
		if (unitModels[i]->getName() == name)
			instances[i]++;
	}
}

std::vector<Unit*> UnitFactory::getUnitModels()
{
	return unitModels;
}

Unit* UnitFactory::getUnitModel(std::string name)
{
	for (unsigned int i = 0; i < unitModels.size(); i++)
	{
		if (unitModels[i]->name == name)
			return unitModels[i];
	}
	return NULL;
}