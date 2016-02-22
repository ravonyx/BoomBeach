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

void Base::saveBase()
{
	std::cout << "Saving" << std::endl;
	std::ofstream myfile;
	myfile.open("base.txt");
	myfile << money;
	myfile << "FIELD";
	myfile << field.getHeight();
	myfile << field.getWidth();
	
	for (int i = 0; i < field.getWidth()*field.getHeight(); i++) {
		myfile << field[i]; //Operateur sur field qui donne un index de data
	}

	myfile.close();
}

Base Base::loadBase()
{
	Field *f;
	int mon;
	int h ;
	int w;
	std::string line;
	std::ifstream myfile("base.txt");
	if (myfile.is_open())
	{
		mon = std::getline(myfile, line); //On récupère money
		std::getline(myfile, line); //On récupère "FIELD" 
		h = std::getline(myfile, line); //On récupère Height
		w = std::getline(myfile, line); //On récupère Width
		
		while (std::getline(myfile, line))
		{
			//Récupérer une case du field
			
			std::cout << line << '\n';
		}
		myfile.close();
	}

	else std::cout << "Unable to open file";
	
	return Base(f, mon);
}

Field* Base::GetField()
{
	return field;
}