#include "BuildingFactory.h"

BuildingFactory::BuildingFactory()
{

}

Building* BuildingFactory::readNextBuilding(std::istream &stream)
{
	std::string readline;
	getline(stream, readline);
	return nullptr;
}