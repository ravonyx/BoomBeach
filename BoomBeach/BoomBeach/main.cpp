#include "Building.h"
#include <iostream>
#include "Field.h"
#include "Base.h"

void main()
{
	int i(0);

	Base b = Base(Field(), 0);

	b.saveBase();

	std::cin >> i;
	//Building *building = new Building();
	//std::cout << building << std::endl;
}