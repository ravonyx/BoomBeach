#include "Building.h"

Building::Building()
{
	id = 0;
	name = "Default";
	life = 2000;
	cost = 1000;
	level = 0;

	width = 1;
	height = 1;

	healthUpdateRate = 0.1;
	costUpdateRate = 0.2;
	maxInstances = 1;

	zone = Zone();
}

Building::Building(int pid, std::string pname, int plife, int pcost, int plevel, float phealthUpdateRate, float pcostUpdateRate, 
	int pmaxInstances, int pwidth, int pheight, Zone pzone)
{
	id = pid;
	name = pname;
	life = plife;
	cost = pcost;
	level = plevel;

	width = pwidth;
	height = pheight;

	healthUpdateRate = phealthUpdateRate;
	costUpdateRate = pcostUpdateRate;
	maxInstances = pmaxInstances;

	zone = pzone;
}

Building::Building(const Building& model)
{
	id = 0;
	name = model.name;
	life = model.life;
	cost = model.cost;
	level = 0;

	width = model.width;
	height = model.height;
	
	healthUpdateRate = model.healthUpdateRate;
	costUpdateRate = model.costUpdateRate; 
	
	maxInstances = model.maxInstances;
	zone = Zone(model.zone);
}

int Building::nextUpdateCost()
{
	return cost * costUpdateRate;
}

int Building::levelUp()
{
	level++;

	life *= healthUpdateRate;
	cost *= costUpdateRate;

	return cost /= costUpdateRate;
}

int Building::getId()
{
	return id;
}
std::string Building::getName()
{
	return name;
}

int Building::getCost()
{
	return cost;
}

float Building::getHealthUpdateRate()
{
	return healthUpdateRate;
}
float Building::getCostUpdateRate()
{
	return costUpdateRate;
}

int Building::getWidth()
{
	return width;
}
int Building::getHeight()
{
	return height;
}
int Building::getMaxInstances()
{
	return maxInstances;
}

Zone Building::getZone()
{
	return zone;
}

void Building::setId(int pid)
{
	id = pid;
}

void Building::setZone(Zone pzone)
{
	zone = pzone;
}

int Building::getLife()
{
	return life;
}
