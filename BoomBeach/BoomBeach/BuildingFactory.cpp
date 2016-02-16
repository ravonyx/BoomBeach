#include "BuildingFactory.h"

BuildingFactory::BuildingFactory()
{
	buildingList.push_back("Example");
	buildingList.push_back("Example1");
}

bool BuildingFactory::nameInList(std::string name)
{
	for (int i = 0; i < buildingList.size(); i++)
	{
		if (name == buildingList[i])
		{
			return true;
		}
	}
	return false;
}

Building* BuildingFactory::readNextBuilding(std::istream &stream)
{
	std::string readline;
	getline(stream, readline);
	return nullptr;
}