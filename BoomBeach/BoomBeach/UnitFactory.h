#pragma once
#include "Unit.h"
#include "Army.h"
#include <vector>
#include <string>
#include <iostream>

class UnitFactory
{
private:
	std::vector <Unit*>unitModels;
	bool nameInList(std::string name);
	Unit* getUnitModel(std::string name);

	int instances[8];

public:
	UnitFactory();
	Unit* readNextUnit(std::istream &stream);
	Unit* create(std::string name);

	int getInstances(std::string name);
	void addInstances(std::string name);
	void removeInstances(std::string name);

	std::vector<Unit*> getUnitModels();
};

