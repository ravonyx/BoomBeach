#pragma once
#include <string>

enum unitType {princess, mushroom, badguy, goodguy};

class Unit
{
private:
	Unit(unitType name);
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
	float getName() const { return name; };
	float getLevel() const { return level; };

	friend class UnitFactory;
	friend class Army;
	int nextUpdateCost();
	int levelUp();
	//friend std::ostream& operator<<(std::ostream& os, const Unit &building);
	~Unit();
};

