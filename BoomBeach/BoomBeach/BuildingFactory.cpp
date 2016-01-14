#include "BuildingFactory.h"

BuildingFactory::BuildingFactory()
{

}

Building* BuildingFactory::build(std::string name)
{
	if (name != "")
	{
		Building *building = new Building();
		return building;
	}
	return nullptr;
}

Building* BuildingFactory::readNextBuilding(std::istream &stream)
{
	std::string readline;
	getline(stream, readline);
}