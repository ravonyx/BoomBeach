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
	void printBuildings();
	bool AddBuilding(BuildingFactory *buildingFactory, const char *name);
	void DestroyBuilding();
	void ListBuildings();

	void saveBase();
	Base loadBase();

	Field* getField();
private:
	std::vector <Building*> buildings;
	int _currentId = 1;
	Field *field;
	//vector <Unit> units
	int money;

};

