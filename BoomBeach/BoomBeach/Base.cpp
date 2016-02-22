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
		std::cout << "Building factory not initialised" << std::endl;
	else
	{
		Building* building = buildingFactory->build(name);
		if (building != nullptr)
		{
			Zone zoneToBuild = field->FindEmptyZone(building->getWidth(), building->getHeight());
			if (!zoneToBuild.isEmpty())
			{
				building->setId(_currentId);
				zoneToBuild.setId(_currentId);
				_currentId++;
				field->Build(zoneToBuild);
				buildings.push_back(building);
				return true;
			}
			else
				std::cout << "No more space for building" << std::endl;
			
		}
		else
			std::cout << "Building name does not exist" << std::endl;
	}
	std::cout << "Fail to build building" << std::endl;
	return false;
}

void Base::printBuildings()
{
	if (buildings.size() <= 0)
		std::cout << "No buildings";
	else
	{
		for (int i = 0; i < buildings.size(); i++)
		{
			std::cout << *(buildings[i]) << std::endl;
		}
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
