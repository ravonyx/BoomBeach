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

void Building::setHeathCost(int baseLife, int baseCost, int plevel)
{
	life = baseLife + baseLife * (plevel * healthUpdateRate);
	cost = baseCost + baseLife * (plevel * costUpdateRate);
}

std::ofstream& operator<< (std::ofstream& os, const Building &building)
{
	os << building.id << std::endl;
	os << building.name << std::endl;
	os << building.level << std::endl;
	os << building.zone.getX() << std::endl;
	os << building.zone.getY() << std::endl;
	return os;
}
std::ostream& operator<< (std::ostream& os, const Building &building)
{
	os << std::endl;
	os << "Id: " << building.id << " Name: " << building.name << " Level: " << building.level << " Life: " << building.life <<
		" Cost: " << building.cost << " X: " << building.zone.getX() << " Y: " << building.zone.getY();
	return os;
}

int Building::getId() const
{
	return id;
}
std::string Building::getName() const
{
	return name;
}
int Building::getLife() const
{
	return life;
}
int Building::getCost() const
{
	return cost;
}

float Building::getHealthUpdateRate() const
{
	return healthUpdateRate;
}
float Building::getCostUpdateRate() const
{
	return costUpdateRate;
}

int Building::getWidth() const
{
	return width;
}
int Building::getHeight() const
{
	return height;
}
int Building::getMaxInstances() const
{
	return maxInstances;
}

Zone Building::getZone() const
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
