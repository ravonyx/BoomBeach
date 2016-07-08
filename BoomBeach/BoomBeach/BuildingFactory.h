#pragma once

#include <vector>
#include <string>
#include <iostream>
#include "Building.h"

class BuildingFactory
{
	private:
		std::vector <Building*>buildingModels;
		bool nameInList(std::string name);
		Building* getBuildingModel(std::string name);

		int instances[7];

	public:
		BuildingFactory();
		Building* build(std::string name);
		Building* readNextBuilding(std::istream &stream);
		int getInstances(std::string name);
		void addInstances(std::string name);
		void removeInstances(std::string name);

		std::vector<Building*> getBuidingModels();
};