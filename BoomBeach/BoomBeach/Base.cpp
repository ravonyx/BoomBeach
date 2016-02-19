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
		return false;
	else
	{
		Zone zoneToBuild = field->FindEmptyZone(2, 2);
		Building* building = buildingFactory->build(name);
		if (building != nullptr)
		{
			field->Build(zoneToBuild);
			return true;
		}
			
		else
			return false;
	}

}

Field* Base::GetField()
{
	return field;
}