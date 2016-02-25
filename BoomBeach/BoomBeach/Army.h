#pragma once
#include "Unit.h"
#include <vector>
#include <iostream>
#include "UnitFactory.h"

class Army
{
private : 
	int money = 10000;
	std::vector<Unit> _unitArray;
	UnitFactory *unitFactory;
public:
	Army();
	void AddUnit(Unit &unit);
	void DeleteUnit(Unit &unit);
	void DeleteUnit(unitType type, int level);
	int NumberOfInstance(unitType type);
	std::vector<Unit> GetUnits() const { return _unitArray; }
	int LevelUpUnit(int i) { return _unitArray[i].levelUp(); }
	UnitFactory& GetFactory() const { return *unitFactory; }

	void SaveArmy();
	void LoadArmy();

	int getMoney() { return money; }
	void setMoney(int _money) { money = _money; }

	~Army() { delete unitFactory; };

};

inline std::ofstream& operator << (std::ofstream& of, const Army& a)
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
}

