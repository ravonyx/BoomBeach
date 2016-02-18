#include "Base.h"



Base::Base(Field f, int m)
{
	field = Field(20, 20);
}


Base::~Base()
{
}

void Base::saveBase()
{
	std::ofstream myfile;
	myfile.open("example.txt");
	myfile << "Writing this to a file.\n";
	myfile.close();
}
