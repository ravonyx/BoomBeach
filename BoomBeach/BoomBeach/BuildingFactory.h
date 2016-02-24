#pragma once

#include <vector>
#include <string>
#include <iostream>
#include "Building.h"

class BuildingFactory
{
	private:
		//std::vector <Building>buildingList;
		std::vector <Building*>buildingModels;
		bool nameInList(std::string name);

		int instanceTower;
		int instanceMortar;
		int instanceHouse;

	public:
		BuildingFactory();
		Building* build(std::string name);
		Building* readNextBuilding(std::istream &stream);
		void buildingList();

		int getInstances(std::string name);
};