#pragma once
#include <iostream>
#include "Zone.h"
#include <iomanip>
#include <fstream>
#include <string>

class Field
{
	public:
		Field();
		int* Panels;
		Field(int, int);
		bool IsEmpty(Zone);
		Zone FindEmptyZone(int, int);
		bool Build(Zone &z);
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
		//Ecrit dans le flux la largeur, la hauteur et le contenu de chaque case
		friend std::ostream& operator << (std::ostream& os, const Field& f)
		{
			os << "Width: " << f.width;
			os << " Height: " << f.height << std::endl;

			for (int j = 0; j < f.height; j++)
			{
				for (int i = 0; i < f.width; i++)
				{
					os << std::setw(2) << f.data[i + j * f.width];
				}
				os << std::endl;
			}

			os << std::endl;
			return os;
		}
		friend std::istream& operator >> (std::istream& is, Field& f)
		{
			std::string junk;
			is >> junk;
			is >> f.width;
			is >> junk;
			is >> f.height;

			const int size = f.width * f.height;
			int data;
			int index = 0;
			while (is.good())
			{
				is >> data;
				if (index < size)
				{
					f.data[index] = data;
					index++;
				}
			}
			return is;
		}


	private:
		int height;
		int width;

		int *data;
		

};