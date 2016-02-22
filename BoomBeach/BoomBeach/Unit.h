#pragma once
#include <string>

enum unitType {princess, mushroom, badguy, goodguy};

class Unit
{
private:
	Unit(unitType type, int level = 0);
	unitType type;
	std::string name;
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
	std::string getName() const { return name; };
	unitType getType() const { return type; };
	int getLevel() const { return level; };

	friend class UnitFactory;
	friend class Army;
	int nextUpdateCost();
	int levelUp();
	//Unit& operator=(const Unit&& u) { this->name = u.name; this->type = u.type; return *this;};
	//friend std::ostream& operator<<(std::ostream& os, const Unit &building);
	~Unit();
};

