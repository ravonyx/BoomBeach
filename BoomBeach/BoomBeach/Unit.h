#pragma once
#include <string>
#include <fstream>
#include <vector>

enum unitType {princess, mushroom, badguy, goodguy};

class Unit
{
private:
	Unit(unitType type, int level = 0);
protected:
	
	unitType type;
	std::string name;
	int maxInstances;
	int cost;
	int attack; //Montant des dommages/soins possibles
	int firerate; //Fréquence d'action
	int range; //Distance d'action
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

	friend std::ofstream& operator << (std::ofstream& os, const Unit& u)
	{
		os << u.getType() << " " << u.getLevel();
		return os;
	}
};

inline std::ostream& operator << (std::ostream& os, const Unit& u)
{
	os << u.getName() << " level " << u.getLevel();
	return os;
}

