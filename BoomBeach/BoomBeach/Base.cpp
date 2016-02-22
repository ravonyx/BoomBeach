#include "Base.h"
#include <algorithm> 

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

bool Base::DestroyBuilding(int id)
{
	Building* building = GetBuilding(id);
	if (building != nullptr)
	{
		std::cout << "Erase building " << building->getId() << std::endl;
		std::vector<Building*>::iterator it;
		it = find(buildings.begin(), buildings.end(), building);
		buildings.erase(it);
		field->Erase(building->getZone());
		return true;
	}

	std::cout << "L'id n'existe pas" << std::endl;
	return false;
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
				building->setZone(zoneToBuild);
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
	myfile.open("base.txt", std::ofstream::out | std::ofstream::trunc);
	if (myfile.is_open())
	{
		myfile << money;
		myfile << *field;

	}
	myfile.close();

}

void Base::loadBase()
{
	Field *f;
	int mon;
	int h ;
	int w;
	std::string line;
	std::ifstream myfile("base.txt", std::ios::in);
	if (myfile.is_open())
	{

		//On trouve l'argent
		std::getline(myfile, line) ; //On récupère money
		myfile >> mon;

		//On trouve la largeur 
		std::getline(myfile, line);
		std::string token = line.substr(0, line.find(" "));
		line.erase(0, line.find(" ") + 1);
		w = std::stoi(line);

		//On trouve la hauteur
		std::getline(myfile, line);
		token = line.substr(0, line.find(" "));
		line.erase(0, line.find(" ") + 1);
		h = std::stoi(line);


		f = new Field(w, h);
		int i = 0;
		while (std::getline(myfile, line))
		{
			if (i < w*h)
			{
				f->getData()[i] = std::stoi(line);
				i++;
			}
			
		}
		myfile.close();
	}

	else std::cout << "Impossible d'ouvrir Base";
	
	//return Base(f, mon);
}

Building* Base::GetBuilding(int id)
{
	for (int i = 0; i < buildings.size(); i++)
	{
		if (buildings[i]->getId() == id)
		{
			return buildings[i];
		}
	}
	return nullptr;
}

Field* Base::getField()
{
	return field;
}
