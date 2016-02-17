#include "Base.h"
#include <iostream>

void main()
{
	std::cout << "Hi !" << std::endl;
	std::cout << "Create Base and building factory";
	Base *base = new Base();
	BuildingFactory *buildingFactory = new BuildingFactory();
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
				for (size_t i = 0; i < 10; i++)
				{
					for (size_t i = 0; i < 10; i++)
					{
						std::cout << "O";
					}
					std::cout << std::endl;
				}
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
								std::cout << "Wich ?" << std::endl;
								std::cin >> input;
								std::cout << "Upgrade Suceed" << std::endl;
								break;
							}
							case 2:
							{
								std::cout << "Wich ?" << std::endl;
								std::cin >> input;
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
							bool ret = base->AddBuilding(buildingFactory, "Example2");
							if (ret == false)
								std::cout << " Fail" << std::endl;
							else
								std::cout << " Suceed" << std::endl;

							std::cout << "End" << std::endl;
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
		std::cout << "//////////////////////////////////" << std::endl;
	}
}