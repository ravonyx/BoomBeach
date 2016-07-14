#pragma once
#include <iostream>
#include "Zone.h"
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

class Field
{
	public:
		Field();
		Field(int, int);
		Field(const Field &field);
		Field& Field::operator=(const Field& field);
		~Field();

		bool IsEmpty(Zone);

		Zone FindEmptyZone(int w, int h);
		Zone FindEmptyZoneWithInd(int w, int h, int px, int py);

		bool Build(Zone &z);
		void Erase(Zone z);
		int GetNearestBuilding(int, int); 
		//void ShortestPath(int, int, int, int)​;

		int getWidth() const;
		int getHeight() const;
		int* getData();

		std::vector<std::vector<int>> getBuilings();

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