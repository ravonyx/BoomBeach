#include "Base.h"

Base::Base()
{
	field = new Field(20, 20);
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
