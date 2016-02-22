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
			os << "Id: " << building.id << " Name:" << building.name << " Life:" << building.life << " Cost: " << building.cost << " Max instances: " << building.maxInstances
				<< " Width: " << building.width << " Height: " << building.height;
			return os;
		}
		int nextUpdateCost();
		int levelUp();
		friend std::ostream& operator<<(std::ostream& os, const Building &building);

		std::string getName();
		int getWidth();
		int getHeight();
		int getId();
		Zone getZone();
		int getCost();

		void setId(int pid);
		void setZone(Zone pzone);
};