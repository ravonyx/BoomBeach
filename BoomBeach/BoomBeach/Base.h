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
		Base(const Base &base);
		Base& Base::operator=(const Base& base);
		~Base();

		void printBuildings();
		bool addBuilding(const char *name, int x = -1, int y = -1);
		void enhanceBuilding(int id);
		bool destroyBuilding(int id);
		Building* getBuilding(int id);
		int getIndexOfBuilding(int id);
		std::vector<Building*> getBuildingsPossibilities();
		std::vector<Building*> getCurrentBuildings();
		Building* GetNearestBuilding(int x, int y);
	
		BuildingFactory* getBuildingFactory();

		void saveBase();
		void loadBase();

		Field* getField() const;
		int getMoney() const;

		void triggerBuildingActions();

	private:
		BuildingFactory *_buildingFactory;
		std::vector <Building*> _buildings;
		int _currentId = 1;
		Field *_field;
		int _money;
};

