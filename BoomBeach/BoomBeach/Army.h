#pragma once
#include "Unit.h"
#include <vector>
#include <iostream>
#include "UnitFactory.h"

class Army
{
	private : 
		int _money = 10000;
		int _currentId = 1;
		std::vector<Unit*> _units;
		UnitFactory *_unitFactory;

	public:
		Army();
		~Army() { delete _unitFactory; };

		bool addUnit(const char* name);
		void enhanceUnit(int id);
		bool deleteUnit(int id);
		Unit* getUnit(int id);
		int getIndexOfUnit(int id);
		
		//void DeleteUnit(Unit &unit);
		//void DeleteUnit(int type, int level);
		//int LevelUpUnit(int i) { return _units[i]->levelUp(); }
		std::vector<Unit*> getUnitsPossibilities();
		std::vector<Unit*> Army::getCurrentUnits();

		UnitFactory* getUnitFactory();

		void saveArmy();
		void loadArmy();

		int getMoney() { return _money; }
		void setMoney(int _money) { _money = _money; }
};

/*inline std::ofstream& operator << (std::ofstream& of, const Army& a)
{
	for (size_t i = 0; i < a.GetUnits().size(); i++)
	{
		of << a.GetUnits()[i];
		if (i != a.GetUnits().size() - 1) {
			of << std::endl;
		}
	}
	return of;
}

inline std::ostream& operator << (std::ostream& os, const Army& a)
{
	if (a.GetUnits().size() <= 0)
		std::cout << "No units" << std::endl;
	else
	for (size_t i = 0; i < a.GetUnits().size(); i++)
	{
		os << "(" << i + 1 << ") " << a.GetUnits()[i] << std::endl;;
	}
	return os;
}*/

