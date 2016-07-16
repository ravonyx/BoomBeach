#pragma once
#include "Unit.h"

class AttackUnit :
	public Unit
{
public:
	AttackUnit(const Unit& model);
	~AttackUnit();

	std::pair<int, int> position;

	void AttackNearestBuilding(); //Supposed to use the Field function : GetNearestBuilding(posX, posY)

	void setPosition(int x, int y);
	std::pair<int, int> getPosition();

	void AttackUnit::takeDamage(const int amount);
};

