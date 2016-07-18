#include "Building.h"

Building::Building()
{
	id = 0;
	name = "Default";
	life = 2000;
	lifeMax = 2000;
	cost = 1000;
	level = 0;

	width = 1;
	height = 1;

	healthUpdateRate = 0.1f;
	costUpdateRate = 0.2f;
	maxInstances = 1;

	zone = Zone();
	targetType = 0;
}

Building::Building(int pid, std::string pname, int ptype, int plife, int pcost, int plevel, int ppower, int prange, int pfireRate, bool parea, float phealthUpdateRate, float pcostUpdateRate,
	int pmaxInstances, int pwidth, int pheight, Zone pzone)
{
	id = pid;
	name = pname;
	type = ptype;
	life = plife;
	lifeMax = life;
	addedLife = 0;
	cost = pcost;
	level = plevel;
	power = ppower;
	range = prange;
	fireRate = pfireRate;
	area = parea;

	width = pwidth;
	height = pheight;

	healthUpdateRate = phealthUpdateRate;
	costUpdateRate = pcostUpdateRate;
	maxInstances = pmaxInstances;

	zone = pzone;
	targetType = 0;
}

Building::Building(const Building& model)
{
	id = 0;
	name = model.name;
	type = model.type;

	life = model.life;
	lifeMax = life;
	addedLife = 0;
	cost = model.cost;
	level = 0;
	power = model.power;
	range = model.range;
	fireRate = model.fireRate;
	area = model.area;

	width = model.width;
	height = model.height;
	
	healthUpdateRate = model.healthUpdateRate;
	costUpdateRate = model.costUpdateRate; 
	
	maxInstances = model.maxInstances;
	zone = Zone(model.zone);
	targetType = 0;

	initFireRate = fireRate;
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

	return cost / costUpdateRate;
}

void Building::setHeathCost(int baseLife, int baseCost, int plevel)
{
	life = baseLife + baseLife * (plevel * healthUpdateRate);
	cost = baseCost + baseCost * (plevel * costUpdateRate);
}

std::ofstream& operator<< (std::ofstream& os, const Building &building)
{
	os << building.id << std::endl;
	os << building.name << std::endl;
	os << building.type << std::endl;
	os << building.level << std::endl;
	os << building.zone.getX() << std::endl;
	os << building.zone.getY() << std::endl;
	return os;
}
std::ostream& operator<< (std::ostream& os, const Building &building)
{
	os << std::endl;
	os << "Id: " << building.id << " Name: " << building.name << "Type: " << building.type << "Level: " << building.level << " Life: " << building.life <<
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
int Building::getType() const
{
	return type;
}

int Building::getLife() const
{
	return life + addedLife;
}
int Building::getLevel() const
{
	return level;
}
int Building::getCost() const
{
	return cost;
}
int Building::getPower() const
{
	return power;
}
int Building::getRange() const
{
	return range;
}
int Building::getFireRate() const
{
	return fireRate;
}
bool Building::getArea() const
{
	return area;
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

int Building::getTargetType() const
{
	return targetType;
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

void Building::addLife(const int value)
{
	if (life + value >= lifeMax + addedLife)
		life = lifeMax;
	else
		life += value;
}

void Building::addFireRate(const int value)
{
	fireRate = initFireRate + value;
}


void Building::setAddedLife(const int value)
{
	addedLife = value;
}

void Building::setTargetType(const int value)
{
	if (value < 0) 
		targetType = 0;
	else if (value > 6)
		targetType = 0;
	else
		targetType = value;
}

void Building::takeDamage(const int amount)
{
	life -= amount;
}
