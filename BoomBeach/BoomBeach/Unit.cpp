#include "Unit.h"

Unit::Unit(unitType name)
{
	switch (name) {
	case princess:
		maxInstances = 2;
		cost = 2000;
		attack = 10;
		firerate = 100;
		range = 20;
		health = 300;
		attackUpdateRate = 1.2;
		firerateUpdateRate = 1.1;
		rangeUpdateRate = 1.2;
		healthUpdateRate = 1.3;
		costUpdateRate = 1.5;
		break;
	case mushroom:
		// Code
		break;
	case badguy:
		// Code
		break;
	case goodguy:
		// Code
		break;
	default:
		// Code
		break;
	}
}

int Unit::nextUpdateCost()
{
	return cost * costUpdateRate;
}

int Unit::levelUp()
{
	cost *= costUpdateRate;
	attack *= attackUpdateRate;
	firerate *= firerateUpdateRate;
	range *= rangeUpdateRate;
	health *= healthUpdateRate;
	return cost /= costUpdateRate;
}

/*std::ostream& operator<<(std::ostream& os, const Unit &building)
{
	os << "Name:" << building.name << "Niveau:" << building.level << std::endl;
	return os;
}*/

Unit::~Unit()
{
}
