#include "Base.h"

Base::Base()
{
	field = new Field();
	money = 1500;
}

Base::Base(Field *pf, int pmoney)
{
	field = pf;
	money = pmoney;
}

Base::~Base()
{
	delete &field;
}

bool Base::AddBuilding(BuildingFactory *buildingFactory, const char *name)
{
	if (buildingFactory == NULL)
		std::cout << "Building factory not initialised" << std::endl;
	else
	{
		Building* building = buildingFactory->build(name);
		if (building != nullptr)
		{
			Zone zoneToBuild = field->FindEmptyZone(building->getWidth(), building->getHeight());
			if (!zoneToBuild.isEmpty())
			{
				building->setId(_currentId);
				zoneToBuild.setId(_currentId);
				_currentId++;
				field->Build(zoneToBuild);
				buildings.push_back(building);
				return true;
			}
			else
				std::cout << "No more space for building" << std::endl;
			
		}
		else
			std::cout << "Building name does not exist" << std::endl;
	}
	std::cout << "Fail to build building" << std::endl;
	return false;
}

void Base::printBuildings()
{
	if (buildings.size() <= 0)
		std::cout << "No buildings";
	else
	{
		for (int i = 0; i < buildings.size(); i++)
		{
			std::cout << *(buildings[i]) << std::endl;
		}
	}
}

Field* Base::getField()
{
	return field;
}