#include "Field.h"



Field::Field()
{
}

Field::Field(int, int)
{
}

bool Field::IsEmpty(Zone z)
{
	if (z.isEmpty())
		return true;
	else
		return false;
}

Zone Field::FindEmptyZone(int w, int h)
{
	Zone z = Zone();
	return Zone();
}

bool Field::Build(Zone z)
{
	return false;
}

void Field::Erase(Zone z)
{
}

int Field::GetNearestBuilding(int x, int y)
{
	return 0;
}


Field::~Field()
{
}

std::ostream & operator<<(std::ostream os, Field f)
{
	// TODO: insert return statement here
}

std::istream & operator>>(std::istream os, Field f)
{
	// TODO: insert return statement here
}
