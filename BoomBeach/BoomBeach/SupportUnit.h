#pragma once
#include "Unit.h"


class SupportUnit :
	public Unit
{
public:
	SupportUnit();
	~SupportUnit();

	int posx;
	int posy;

	std::vector<int> FindPathToClosestAlly(); //Returns a list of map indices to get through
};

