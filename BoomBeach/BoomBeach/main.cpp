#include "Building.h"
#include "Base.h"
#include <iostream>

void main()
{
	std::cout << "Hi !" << std::endl;
	std::cout << "Welcome in Ravonyxland" << std::endl << std::endl;
	std::cout << "Initialization" << std::endl;
	Base *base = new Base();
	
	Army *army = new Army();
	std::cout << "/////////////////////////////////" << std::endl << std::endl;

	int exitCode = 0;
	while (exitCode != 1)
	{
		std::cout << "What do you want to do ?" << std::endl;
		std::cout << "(1) View base" << std::endl;
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
				std::cout << "--------------------------------" << std::endl;
				std::cout << *(base->getField());
				std::cout << "--------------------------------" << std::endl;
				std::cout << "-1 : Empty ";
				std::cout << "-2 : Loading Zone ";
				std::cout << "-3 : Tree" << std::endl;
				while (exitCode != 1)
				{
					std::cout  << std::endl;
					std::cout << "What do you want to see ?" << std::endl;
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
							std::cout << std::endl;
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
								base->enhanceBuilding(input);
								std::cout << "Upgrade Suceed" << std::endl;
								break;
							}
							case 2:
							{
								std::cout << "Which ?" << std::endl;
								std::cin >> input;
								base->destroyBuilding(input);
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
							std::cout << *army;
							std::cout << std::endl;
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
								std::cout << "Which ?" << std::endl;
								std::cin >> input;
								if(input>0 && input < army->GetUnits().size()+1)
									std::cout << "Updated for " << army->GetUnits()[input-1].levelUp() << " gold" << std::endl;
								break;
							}
							case 2:
							{
								std::cout << "Which ?" << std::endl;
								std::cin >> input;
								if (input>0 && input < army->GetUnits().size() + 1)
									army->DeleteUnit(army->GetUnits()[input-1].getType(), army->GetUnits()[input - 1].getLevel());
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
					std::cout << std::endl;
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
							base->addBuilding(name.c_str());
							break;
						}
						case 2:
						{
							base->printBuildingsPossibilies();
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
			case 3:
			{
				while (exitCode != 1)
				{
					std::cout << std::endl;
					std::cout << "You have " << army->getMoney() << " gold to army" << std::endl;

					std::cout << "You can create:" << std::endl;
					for (size_t i = 0; i < army->GetFactory().UnitList().size(); i++)
					{
						std::cout << "(" << i + 1 << ") " << army->GetFactory().UnitList()[i] << std::endl;;
					}
					std::cout << "(0) Back" << std::endl;
					int input;
					std::cin >> input;
					if(input == 0)
						exitCode = 1;
					else {
						army->GetFactory().CreateUnit(unitType(input - 1), army);
					}
						
				}
				exitCode = 0;
				break;
			}
			case 4:
			{
                base->saveBase();
				army->SaveArmy();
				break;
			}
			case 5:
			{
				base->loadBase();
				army->LoadArmy();
				break;
            }
			default:
				std::cout << "This is not a valid input" << std::endl;
				break;
		}
		std::cout << "//////////////////////////////////" << std::endl << std::endl;
	}
}
