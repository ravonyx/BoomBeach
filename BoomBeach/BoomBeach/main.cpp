#include "Base.h"
#include <iostream>

void main()
{
	std::cout << "Hi !" << std::endl;
	std::cout << "Create Base and building factory";
	Base *base = new Base();
	BuildingFactory *buildingFactory = new BuildingFactory();
	bool ret = base->AddBuilding(buildingFactory, "Example2");
	if (ret == false)
		std::cout << " Fail" << std::endl;
	else
		std::cout << " Suceed" << std::endl;

	std::cout << "End" << std::endl;
	getchar();
}