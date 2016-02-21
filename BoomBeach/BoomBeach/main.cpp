#include "Building.h"
#include "UnitFactory.h"
#include <iostream>

void main()
{
	Building *building = new Building();
	Army *army = new Army();
	std::cout << building << std::endl;
	std::cout << "You can create:" << std::endl;
	UnitFactory *unitFactory = new UnitFactory();
	for (size_t i = 0; i < unitFactory->UnitList().size(); i++)
	{
		std::cout << "(" << i +1 << ") " << unitFactory->UnitList()[i] << std::endl;;
	}
	unitFactory->Create(unitType(0), *army);
	unitFactory->Create(unitType(1), *army);
	army->SaveArmy();
	unitFactory->Create(unitType(1), *army);
	army->LoadArmy();
	unitFactory->Create(unitType(0), *army);
	army->SaveArmy();
	int a;
	std::cin >> a;
}