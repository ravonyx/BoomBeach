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
	private:
		int height;
		int width;


};

std::ostream& operator << (std::ostream os,  Field& f); //Ecrit dans le flux la largeur, la hauteur et le contenu de chaque case

std::istream& operator >> (std::istream os, Field& f); //qui lira dans le flux la largeur, la hauteur et le contenu de chaque case, et modifiera le Field en conséquences.
