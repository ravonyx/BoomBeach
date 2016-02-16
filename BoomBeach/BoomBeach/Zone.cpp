#include "Zone.h"

Zone::Zone()
{
	id = -1;
	width = 0;
	height = 0;
	x = 0;
	y = 0;
}

Zone::Zone(int pwidth, int pheight, int px, int py)
{
	id = 0;
	width = pwidth;
	height = pheight;
	x = px;
	y = py;
}

bool Zone::isEmpty()
{
	if (width == 0 && height == 0)
		return true;
	return false;
}


void Zone::setWidth(int pwidth)
{
	width = pwidth;
}

void Zone::setHeight(const int pheight)
{
	height = pheight;
}