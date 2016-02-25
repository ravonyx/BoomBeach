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
			return _data[x + y * _width];
		}
		friend std::ofstream& operator << (std::ofstream& os, const Field& f);
		friend std::ostream& operator << (std::ostream& os, const Field& f);
		friend std::istream& operator >> (std::istream& is, Field& f);

	private:
		int _height;
		int _width;
		int *_data;
};