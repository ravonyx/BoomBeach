#include "Zone.h"

Zone::Zone()
{
}

bool Zone::isEmpty()
{
	if (width == 0 && height == 0)
		return true;
	return false;
}