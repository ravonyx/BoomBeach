#include "Building.h"
#include "Base.h"
#include <iostream>

void main()
{
	std::cout << "Hi !" << std::endl;
	std::cout << "Create Base and building factory";
	Base *base = new Base();
	BuildingFactory *buildingFactory = new BuildingFactory();

	

	/*Army *army = new Army();
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
	std::cin >> a;*/
	int exitCode = 0;
	while (exitCode != 1)
	{
		std::cout << "What do you want to do ?" << std::endl;
		std::cout << "(1) View map" << std::endl;
		std::cout << "(2) Select Building Factory" << std::endl;
		std::cout << "(3) Select Unit Factory" << std::endl;
		std::cout << "(4) Save base" << std::endl;
		std::cout << "(5) Load a base" << std::endl;
		std::cout << "(0) Exit application" << std::endl;
		int input;
		std::cin >> input;
		switch (input)
		{
			case 0:
				exitCode = 1;
				break;
			case 1:
			{
				std::cout << *(base->getField());
				while (exitCode != 1)
				{
					std::cout << "What do you want to do ?" << std::endl;
					std::cout << "(1) List of building" << std::endl;
					std::cout << "(2) List of units" << std::endl;
					std::cout << "(0) Back To Menu" << std::endl;
					int input;
					std::cin >> input;
					switch (input)
					{
					case 0:
						exitCode = 1;
						break;
					case 1:
						base->printBuildings();
						while (exitCode != 1)
						{
							std::cout << "What do you want to do ?" << std::endl;
							std::cout << "(1) Upgrade building" << std::endl;
							std::cout << "(2) Delete building" << std::endl;
							std::cout << "(0) Back To Menu" << std::endl;
							int input;
							std::cin >> input;
							switch (input)
							{
							case 0:
								exitCode = 1;
								break;
							case 1: 
							{
								std::cout << "Which ?" << std::endl;
								std::cin >> input;
								std::cout << "Upgrade Suceed" << std::endl;
								break;
							}
							case 2:
							{
								std::cout << "Which ?" << std::endl;
								std::cin >> input;
								base->DestroyBuilding(input);
								std::cout << "Delete Suceed" << std::endl;
								break;
							}
							
							default:
								std::cout << "This is not a valid input" << std::endl;
								break;
							}
						}
						exitCode = 0;
						break;
					case 2:
					{
						while (exitCode != 1)
						{
							std::cout << "What do you want to do ?" << std::endl;
							std::cout << "(1) Upgrade unit" << std::endl;
							std::cout << "(2) Delete unit" << std::endl;
							std::cout << "(0) Back To Menu" << std::endl;
							int input;
							std::cin >> input;
							switch (input)
							{
							case 0:
								exitCode = 1;
								break;
							case 1:
							{
								std::cout << "Wich ?" << std::endl;
								break;
							}
							case 2:
							{
								std::cout << "Wich ?" << std::endl;
								break;
							}
						
							default:
								std::cout << "This is not a valid input" << std::endl;
								break;
							}
						}
						exitCode = 0;
						break;
					}
					default:
						std::cout << "This is not a valid input" << std::endl;
						break;
					}
				}
				exitCode = 0;
				break;
			}
			case 2:
			{
				while (exitCode != 1)
				{
					std::cout << "What do you want to do ?" << std::endl;
					std::cout << "(1) Build building" << std::endl;
					std::cout << "(2) View building Possibilities" << std::endl;
					std::cout << "(0) Back To Menu" << std::endl;
					int input;
					std::cin >> input;
					switch (input)
					{
						case 0:
							exitCode = 1;
							break;
						case 1:
						{
							std::string name;
							std::cout << "Name: ";
							std::cin >> name;
							base->AddBuilding(buildingFactory, name.c_str());
							break;
						}
						case 2:
						{
							std::cout << *buildingFactory << std::endl;
							break;
						}
						default:
							std::cout << "This is not a valid input" << std::endl;
							break;
					}
				}
				exitCode = 0;
				break;
			}
			case 4:
			{
				base->saveBase();
				break;
			}
			default:
				std::cout << "This is not a valid input" << std::endl;
				break;
		}
		std::cout << "//////////////////////////////////" << std::endl;
	}
}
