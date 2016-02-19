#include "Base.h"
#include <iostream>

void main()
{
	std::cout << "Hi !" << std::endl;
	std::cout << "Create Base and building factory";
	Base *base = new Base();
	BuildingFactory *buildingFactory = new BuildingFactory();
	bool ret = base->AddBuilding(buildingFactory, "Example1");
	ret = base->AddBuilding(buildingFactory, "Example");
	ret = base->AddBuilding(buildingFactory, "Example");
	ret = base->AddBuilding(buildingFactory, "Example");
	std::cout << "End" << std::endl;
	std::cout << *(base->GetField()) << std::endl;
	getchar();
}