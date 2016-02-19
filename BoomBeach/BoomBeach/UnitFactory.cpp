#include "UnitFactory.h"

UnitFactory::UnitFactory()
{

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

std::ostream& operator<<(std::ostream& os, const Unit &unit)
{
	os << "Name:" << unit.getName() << "Niveau:" << unit.getLevel() << std::endl;
	return os;
}

bool UnitFactory::nameInList(unitType name)
{
	switch (name) {
	case princess || mushroom || badguy || goodguy:
		return true;
	default:
		return false;
		break;
	}
}

Unit* UnitFactory::ReadNextUnit(std::istream &stream)
{
	std::string readline;
	getline(stream, readline);
	return nullptr;
}


UnitFactory::~UnitFactory()
{
}
