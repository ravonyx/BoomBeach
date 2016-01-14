#include "Building.h"

Building::Building()
{
	life = 2000;
	cost = 1000;
	level = 0;

	healthUpdateRate = 0.1;
	costUpdateRate = 0.2;

	zone = Zone();
}

int Building::nextUpdateCost()
{
	return cost * costUpdateRate;
}

int Building::levelUp()
{
	life *= healthUpdateRate;
	cost *= costUpdateRate;

	return cost /= costUpdateRate;
}

std::ostream& operator<<(std::ostream& os, const Building &building)
{
	os << "Name:" << building.name << "Niveau:" << building.level << std::endl;
	return os;
}