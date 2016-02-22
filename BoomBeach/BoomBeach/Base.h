#pragma once
#include "Field.h"
#include "BuildingFactory.h"
#include "Building.h"
#include <vector>
#include <iostream>
#include <fstream>

class Base
{
public:
	Base();
	Base(Field &f, int pmoney);
	~Base();
	void printBuildings();
	bool AddBuilding(BuildingFactory *buildingFactory, const char *name);
	void EnhanceBuilding(int id);
	void DestroyBuilding();
	void ListBuildings();
	Building GetBuilding(int id);

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

