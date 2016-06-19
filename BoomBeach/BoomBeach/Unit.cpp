#include "Unit.h"
#include <iostream>

Unit::Unit(unitType type, int level)
{
	switch (type) {
	case princess:
		this->type = type;
		name = "princess";
		this->level = level;
		maxInstances = 2;
		attackUpdateRate = 1.2;
		firerateUpdateRate = 1.1;
		rangeUpdateRate = 1.2;
		healthUpdateRate = 1.3;
		costUpdateRate = 1.5;
		cost = 2000 + ( 2000 * level * costUpdateRate);
		attack = 10 + (10 * level * attackUpdateRate);
		firerate = 100 + (100 * level * firerateUpdateRate);
		range = 20 + (20 * level * rangeUpdateRate);
		health = 300 + (300 * level * healthUpdateRate);
		break;
	case mushroom:
		this->type = type;
		name = "mushroom";
		this->level = level;
		maxInstances = 5;
		attackUpdateRate = 1.1;
		firerateUpdateRate = 1.1;
		rangeUpdateRate = 1.1;
		healthUpdateRate = 1.3;
		costUpdateRate = 1.1;
		cost = 500 + (500 * level * costUpdateRate);
		attack = 2 + (2 * level * attackUpdateRate);
		firerate = 25 + (25 * level * firerateUpdateRate);
		range = 5 + (5 * level * rangeUpdateRate);
		health = 75 + (75 * level * healthUpdateRate);
		break;
	case badguy:
		this->type = type;
		name = "badguy";
		this->level = level;
		maxInstances = 5;
		attackUpdateRate = 1.1;
		firerateUpdateRate = 1.1;
		rangeUpdateRate = 1.1;
		healthUpdateRate = 1.3;
		costUpdateRate = 1.1;
		cost = 500 + (500 * level * costUpdateRate);
		attack = 2 + (2 * level * attackUpdateRate);
		firerate = 25 + (25 * level * firerateUpdateRate);
		range = 5 + (5 * level * rangeUpdateRate);
		health = 75 + (75 * level * healthUpdateRate);
		break;
	case goodguy:
		this->type = type;
		name = "goodguy";
		this->level = level;
		maxInstances = 5;
		attackUpdateRate = 1.1;
		firerateUpdateRate = 1.1;
		rangeUpdateRate = 1.1;
		healthUpdateRate = 1.3;
		costUpdateRate = 1.1;
		cost = 500 + (500 * level * costUpdateRate);
		attack = 2 + (2 * level * attackUpdateRate);
		firerate = 25 + (25 * level * firerateUpdateRate);
		range = 5 + (5 * level * rangeUpdateRate);
		health = 75 + (75 * level * healthUpdateRate);
		break;
	default:
		break;
	}
	std::cout << "Creation of " << this->name << " level " << this->level << " for " << this->cost << " gold" << std::endl << std::endl;
}

int Unit::nextUpdateCost()
{
	return cost * costUpdateRate;
}

int Unit::levelUp()
{
	level++;
	cost *= costUpdateRate;
	attack *= attackUpdateRate;
	firerate *= firerateUpdateRate;
	range *= rangeUpdateRate;
	health *= healthUpdateRate;
	return cost / costUpdateRate;
}
/*std::ostream& operator<<(std::ostream& os, const Unit &building)
{
	os << "Name:" << building.name << "Niveau:" << building.level << std::endl;
	return os;
}*/

