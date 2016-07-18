#include "Unit.h"
#include <iostream>

Unit::Unit()
{
	id = 0;
	type = 0;
	name = "Default";
	level = 0;
	maxInstances = 2;
	attackUpdateRate = 1.2f;
	firerateUpdateRate = 1.1f;
	rangeUpdateRate = 1.1f;
	healthUpdateRate = 1.1f;
	costUpdateRate = 1.1f;
	cost = 2000 + (2000 * level * costUpdateRate);
	attack = 10 + (10 * level * attackUpdateRate);
	firerate = 100 + (100 * level * firerateUpdateRate);
	range = 20 + (20 * level * rangeUpdateRate);
	health = 300 + (300 * level * healthUpdateRate);
	speed = 10;
	area = false;
	deployed = false;
}

Unit::Unit(int pid, int ptype, std::string pname, int pcost, float phealthUpdateRate, float pcostUpdateRate, int pmaxInstances,
	float pattackupdaterate, float pfireupdaterate, float prangeupdaterate, int pattack, int pfirerate, int prange, int phealth, int pspeed, bool parea, bool pdeployed)
{
	id = pid;
	type = ptype;
	name = pname;
	level = 0;
	maxInstances = pmaxInstances;
	attackUpdateRate = pattackupdaterate;
	firerateUpdateRate = pfireupdaterate;
	rangeUpdateRate = prangeupdaterate;
	healthUpdateRate = phealthUpdateRate;
	costUpdateRate = pcostUpdateRate;
	cost = pcost;
	attack = pattack;
	firerate = pfirerate;
	range = prange;
	health = phealth;
	speed = pspeed;
	area = parea;
	deployed = pdeployed;
}

Unit::Unit(const Unit& model)
{
	id = model.id;
	type = model.type;
	name = model.name;
	level = model.level;
	maxInstances = model.maxInstances;
	attackUpdateRate = model.attackUpdateRate;
	firerateUpdateRate = model.firerateUpdateRate;
	rangeUpdateRate = model.rangeUpdateRate;
	healthUpdateRate = model.healthUpdateRate;
	costUpdateRate = model.costUpdateRate;
	cost = model.cost;
	attack = model.attack;
	firerate = model.firerate;
	range = model.range;
	health = model.health;
	speed = model.speed;
	area = model.area;
	deployed = model.deployed;
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

void Unit::setAttributes(int baseLife, int baseCost, int baseAttack, int baseFirerate, int baseRange, int plevel)
{
	health = baseLife + baseLife * (plevel * healthUpdateRate);
	cost = baseCost + baseCost * (plevel * costUpdateRate);
	attack = baseAttack + baseAttack * (plevel * attackUpdateRate);
	firerate = baseFirerate + baseFirerate * (plevel * firerateUpdateRate);
	range = baseRange + baseRange * (plevel * rangeUpdateRate);
}

std::ofstream& operator<< (std::ofstream& os, const Unit &unit)
{
	os << unit.id << std::endl;
	os << unit.type << std::endl;
	os << unit.name << std::endl;
	os << unit.level << std::endl;
	return os;
}
std::ostream& operator<< (std::ostream& os, const Unit &unit)
{
	os << std::endl;
	os << " Name: " << unit.name << "Type: " << unit.type << "Level: " << unit.level << " Life: " << unit.health << " Cost: " << unit.cost;
	return os;
}

int Unit::getId() const
{
	return id;
}
std::string Unit::getName() const
{
	return name;
}
int Unit::getType() const
{
	return type;
}
int Unit::getLevel() const
{
	return level;
}
int Unit::getLife() const
{
	return health;
}
int Unit::getCost() const
{
	return cost;
}
int Unit::getAttack() const
{
	return attack;
}
int Unit::getFirerate() const
{
	return firerate;
}
int Unit::getRange() const
{
	return range;
}
int Unit::getSpeed() const
{
	return speed;
}

float Unit::getHealthUpdateRate() const
{
	return healthUpdateRate;
}
float Unit::getCostUpdateRate() const
{
	return costUpdateRate;
}
float Unit::getAttackUpdateRate() const
{
	return healthUpdateRate;
}
float Unit::getFireUpdateRate() const
{
	return costUpdateRate;
}
float Unit::getRangeUpdateRate() const
{
	return healthUpdateRate;
}

int Unit::getMaxInstances() const
{
	return maxInstances;
}

void Unit::setId(int pid)
{
	id = pid;
}

void Unit::setDeployed(bool pdeployed)
{
	deployed = pdeployed;
}
bool Unit::getDeployed() const
{
	return deployed;
}