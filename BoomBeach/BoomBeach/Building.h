#pragma once
#include <string>
#include "Zone.h"

class Building
{
	private:
		
		Building();
		Building(const Building& model);
		Building(int pid, std::string pname, int plife, int pcost, int plevel, float phealthUpdateRate, 
			float pcostUpdateRate, int pmaxInstances, int pwidth, int pheight, Zone zone);

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
			os << "Id: " << building.id << " Name: " << building.name << " Level: " << building.level << " X: " << 
				building.zone.getX() << " Y: " << building.zone.getY() << std::endl;
			return os;
		}
		int nextUpdateCost();
		int levelUp();

		int getId();
		std::string getName();
		int getLife();
		int getCost();

		float getHealthUpdateRate();
		float getCostUpdateRate();
		int getWidth();
		int getHeight();
		int getMaxInstances();

		Zone getZone();
		
		void setId(int pid);
		void setZone(Zone pzone);
};
