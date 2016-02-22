#pragma once
#include <iostream>
#include "Zone.h"

class Field
{
	public:
		Field();
		int* Panels;
		Field(int, int);
		bool IsEmpty(Zone);
		Zone FindEmptyZone(int, int);
		bool Build(Zone z);
		void Erase(Zone z);
		int GetNearestBuilding(int, int); 
		//void ShortestPath(int, int, int, int)​;
		~Field();

		int getWidth() const;
		int getHeight() const;
		int* getData();

		int& operator() (int x, int y)
		{
			return data[x + y * width];
		}

		int operator [] (int i) const
		{
			return data[i];
		}

	private:
		int height;
		int width;

		int *data;
		

};

//Ecrit dans le flux la largeur, la hauteur et le contenu de chaque case
/*std::ostream& operator << (std::ostream os, Field& f)
{
	int *data = f.getData();
	os << "Width: " << f.getWidth() <<  "Height" << f.getHeight() << std::endl;
	for (int i = 0; i < f.getWidth() * f.getHeight(); i++)
	{
		os << "Type:" << data[i];
	}

	os << std::endl;
	return os;
}

//qui lira dans le flux la largeur, la hauteur et le contenu de chaque case, et modifiera le Field en conséquences.
std::istream& operator >> (std::istream is, Field& f)
{

	return is;
}*/