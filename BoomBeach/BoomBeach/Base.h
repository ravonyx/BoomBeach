#pragma once
#include "Field.h"
#include "BuildingFactory.h"
#include "Building.h"
#include <vector>

class Base
{
public:
	Base();
	Base(Field *f, int pmoney);
	~Base();
	void AddBuilding();
	void DestroyBuilding();
	void ListBuildings();

	void saveBase();
	Base loadBase();

private:
	Field *field;
	//vector <Unit> units
	int money;

};

