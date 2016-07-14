#pragma once
#include "Unit.h"


class SupportUnit :
	public Unit
{
public:
	SupportUnit();
	~SupportUnit();

	std::vector<int> FindPathToClosestAlly(); //Returns a list of map indices to get through
};

