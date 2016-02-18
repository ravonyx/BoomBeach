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
	Base(Field f, int m);
	~Base();
	void AddBuilding();
	void DestroyBuilding();
	void ListBuildings();

	void saveBase();
	Base loadBase();

private:
	Field field;
	//vector <Unit> units
	int money;

};

