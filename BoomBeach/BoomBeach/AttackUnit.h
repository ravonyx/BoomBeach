#pragma once
#include "Unit.h"
class AttackUnit :
	public Unit
{
public:
	AttackUnit();
	~AttackUnit();

	void AttackNearestBuilding(); //Supposed to use the Field function : GetNearestBuilding(posX, posY)
};

