#include "Field.h"



Field::Field()
{
}

Field::Field(int w, int h)
{
	width = w;
	height = h;
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
	for (int i = 0; i < width*height;i++)
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

std::ostream & operator<<(std::ostream os, Field& f)
{
	// TODO: insert return statement here
	os << "Name:" << std::endl;
	return os;
}
