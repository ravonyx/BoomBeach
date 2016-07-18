#pragma once
#include "Unit.h"
#include <vector>
#include <iostream>
#include "UnitFactory.h"
#include "AttackUnit.h"

class Army
{
	private : 
		int _money = 10000;
		int _currentId = 1;
		std::vector<Unit*> _units;
		std::vector<AttackUnit*> _attackUnits;
		UnitFactory *_unitFactory;

	public:
		Army();
		~Army();

		bool addUnit(const char* name);
		bool addAttackUnit(int id, int x, int y);
		void enhanceUnit(int id);
		bool deleteUnit(int id);
		bool deleteAttackUnit(int id);
		void clearAttackUnit();
		Unit* getUnit(int id);
		AttackUnit* Army::getAttackUnit(int id);
		int getIndexOfUnit(int id);
		int getIndexOfAttackUnit(int id);
		bool moveUnit(int id, std::pair<int, int> position);
		AttackUnit * Army::GetNearestUnit(int x, int y);
		
		std::vector<Unit*> getUnitsPossibilities();
		std::vector<Unit*> getCurrentUnits();
		std::vector<AttackUnit*> Army::getCurrentAttackUnits();

		UnitFactory* getUnitFactory();

		void saveArmy();
		void loadArmy();

		int getMoney() { return _money; }
		void setMoney(int _money) { _money = _money; }
};
