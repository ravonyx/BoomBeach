#include "AttackUnit.h"



AttackUnit::AttackUnit(const Unit& model) : Unit(model) {};


AttackUnit::~AttackUnit()
{
}

void AttackUnit::setPosition(int x, int y)
{
	position.first = x;
	position.second = y;
}

std::pair<int, int> AttackUnit::getPosition()
{
	return position;
}

void AttackUnit::takeDamage(const int amount)
{
	health -= amount;
}
