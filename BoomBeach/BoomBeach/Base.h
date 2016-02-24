#pragma once
#include "Field.h"
#include "BuildingFactory.h"
#include "Building.h"
#include "UnitFactory.h"
#include <vector>
#include <iostream>
#include <fstream>

class Base
{
public:
	Base();
	Base(Field *f, int pmoney);
	~Base();
	void printBuildings();
	void printBuildingsPossibilies();
	bool AddBuilding(const char *name);
	void EnhanceBuilding(int id);
	bool DestroyBuilding(int id);
	Building* GetBuilding(int id);

	void saveBase();
	void loadBase();

	Field* getField();
private:
	BuildingFactory *_buildingFactory;
	std::vector <Building*> buildings;
	int _currentId = 1;
	Field *_field;
	int money;

};

