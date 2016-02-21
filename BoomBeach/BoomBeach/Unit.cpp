#include "Unit.h"

Unit::Unit(unitType type, int level)
{
	switch (type) {
	case princess:
		this->type = type;
		name = "princess";
		maxInstances = 2;
		attackUpdateRate = 1.2;
		firerateUpdateRate = 1.1;
		rangeUpdateRate = 1.2;
		healthUpdateRate = 1.3;
		costUpdateRate = 1.5;
		cost = 2000 + (2000 * level * costUpdateRate);
		attack = 10;
		firerate = 100;
		range = 20;
		health = 300;
		break;
	case mushroom:
		this->type = type;
		name = "mushroom";
		maxInstances = 5;
		cost = 500;
		attack = 2;
		firerate = 25;
		range = 5;
		health = 75;
		attackUpdateRate = 1.1;
		firerateUpdateRate = 1.1;
		rangeUpdateRate = 1.1;
		healthUpdateRate = 1.3;
		costUpdateRate = 1.1;
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
