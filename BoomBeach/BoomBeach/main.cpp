#include "Building.h"
#include "UnitFactory.h"
#include <iostream>

void main()
{
	Building *building = new Building();
	std::cout << building << std::endl;
	std::cout << "You can create:" << std::endl;
	UnitFactory *unitFactory = new UnitFactory();
	for (size_t i = 0; i < unitFactory->UnitList().size(); i++)
	{
		std::cout << "(" << i +1 << ") " << unitFactory->UnitList()[i] << std::endl;;
	}
	int a;
	std::cin >> a;
}