#include "Base.h"

Base::Base()
{
	field = Field(20, 20);
	money = 1500;
}

Base::Base(Field &pf, int pmoney)
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
		Building* building = buildingFactory->build(name);
		if (building != nullptr)
			return true;
		else
			return false;
	}

}

void Base::EnhanceBuilding(int id)
{
	if (money < buildings[id].getLevel())
	{
		buildings[id].levelUp();
	}
}

void Base::DestroyBuilding()
{

}

void Base::ListBuildings()
{
	std::cout << "Liste des Batiements" << std::endl;
	for (int i = 0; i < buildings.size(); i++) {
		std::cout << buildings[i] << std::endl;
	}
}

Building Base::GetBuilding(int id)
{
	/*
	for (int i = 0; i < buildings.size(); i++) {

	}
	*/
	return buildings[id];
}

void Base::saveBase()
{
	std::cout << "Saving" << std::endl;
	std::ofstream myfile;
	myfile.open("base.txt");
	myfile << "FIELD";
	myfile << field.getHeight();
	myfile << field.getWidth();
	for (int i = 0; i < field.getWidth()*field.getHeight(); i++) {
		myfile << field[i];
	}
	/*
	myfile << "BUILDINGS";
	for (int i = 0; i < buildings.size(); i++) {	
		myfile << buildings[i].getLevel();
		myfile << "#";
	}
	*/
	myfile << "END";
	myfile.close();
}

Base Base::loadBase()
{
	std::string line;
	std::ifstream myfile("base.txt");
	if (myfile.is_open())
	{
		std::getline(myfile, line); //On récupère "FIELD" 
		while (std::getline(myfile, line))
		{
			/*if (std::string::compare("BUILDINGS", line)) {

			}*/
			std::cout << line << '\n';
		}
		myfile.close();
	}

	else std::cout << "Unable to open file";
	return Base();
}
