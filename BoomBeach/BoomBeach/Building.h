#pragma once
#include <string>
#include "Zone.h"

class Building
{
	private:
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
		Building();
		int nextUpdateCost();
		int levelUp();
		friend std::ostream& operator<<(std::ostream& os, const Building &building);
};