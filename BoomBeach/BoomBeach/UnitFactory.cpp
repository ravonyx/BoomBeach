#include "UnitFactory.h"

UnitFactory::UnitFactory()
{

}

Unit* UnitFactory::CreateUnit(const unitType type, Army *army)
{
	if (nameInList(type))
	{
		Unit *unit = new Unit(type);
		if (army->getMoney() - unit->cost >= 0) {
			if (army->NumberOfInstance(type) < unit->maxInstances) {
				army->AddUnit(*unit);
				army->setMoney(army->getMoney() - unit->cost);
				return unit;
			}
			else
				std::cout << "Too many units of this type" << std::endl;
		}
		else
			std::cout << "Not enought gold" << std::endl;
	}
	return nullptr;
}

std::vector<std::string> UnitFactory::UnitList()
{
	std::vector<std::string> result;
	for (size_t i = 0; i < unitTypes.size(); i++)
	{
		result.push_back(unitTypes[i].second);
	}
	return result;
}

bool UnitFactory::nameInList(unitType name)
{
	switch (name) {
	case princess:
	case mushroom:
	case badguy:
	case goodguy:
		return true;
	default:
		return false;
		break;
	}
}

Unit* UnitFactory::ReadNextUnit(std::istream & stream)
{
	int type;
	int level;

	stream >> type;
	stream >> level;

	Unit *unit = new Unit(unitType(type), level);

	return unit;
}