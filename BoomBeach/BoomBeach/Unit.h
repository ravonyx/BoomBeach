#pragma once
#include <string>

enum unitType {princess, mushroom, badguy, goodguy};

class Unit
{
private:
	unitType name;
	int maxInstances;
	int cost;
	int attack;
	int firerate;
	int range;
	int health;
	int level = 0;
	float attackUpdateRate;
	float firerateUpdateRate;
	float rangeUpdateRate;
	float healthUpdateRate;
	float costUpdateRate;
public:
	Unit(unitType name);
	int UpgradeUnit();
	float getName() const { return name; };
	float getLevel() const { return level; };
	~Unit();
};

