#pragma once
#include <string>
#include "Zone.h"

class Building
{
	private:
		
		Building();
		Building(const Building& model);
		Building(std::string pname, int plife, int pcost, int phealthUpdateRate, int pcostUpdateRate, int pmaxInstances, int pwidth, int pheight);

		int id;
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
		friend std::ostream& operator<<(std::ostream& os, const Building &building)
		{
			os << "Id: " << building.id << " Name: " << building.name << " Level: " << building.level;
			return os;
		}
		int nextUpdateCost();
		int levelUp();

		std::string getName();
		int getWidth();
		int getHeight();
		int getId();
		int getLife();
		Zone getZone();
		int getCost();
		int getMaxInstances();

		void setId(int pid);
		void setZone(Zone pzone);
};
