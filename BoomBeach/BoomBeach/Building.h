#pragma once
#include <string>
#include "Zone.h"

class Building
{
	private:
		Building();
		std::string name;
		int maxInstances;
		int cost;

		int width;
		int height;

		int life;
		int level;

		float healthUpdateRate;
		float costUpdateRate;

		Zone zone;

	public:
		friend class BuildingFactory;
		int nextUpdateCost();
		int levelUp();
		int getLevel();
		friend std::ostream& operator<<(std::ostream& os, const Building &building);
		
};