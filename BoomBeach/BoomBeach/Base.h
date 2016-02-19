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
	bool AddBuilding(BuildingFactory *buildingFactory, const char *name);
	void DestroyBuilding();
	void ListBuildings();

	void saveBase();
	Base loadBase();

	Field* GetField();
private:
	Field *field;
	//vector <Unit> units
	int money;

};

