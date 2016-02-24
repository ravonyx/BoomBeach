#pragma once
#include <string>
#include "Zone.h"
#include <fstream>

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
		friend std::ofstream& operator<< (std::ofstream& os, const Building &building)
		{
			os << building.id << std::endl;
			os << building.name << std::endl;
			os << building.level << std::endl;
			os << building.zone.getX() << std::endl;
			os << building.zone.getY() << std::endl;
			return os;
		}

		friend std::ostream& operator<< (std::ostream& os, const Building &building)
		{
			os << std::endl;
			os << "Id: " << building.id << " Name: " << building.name << " Level: " << building.level << " Life: " << building.life <<
				" Cost: " << building.cost << " X: " << building.zone.getX() << " Y: " << building.zone.getY();
			return os;
		}
		int nextUpdateCost();
		int levelUp();
		void setHeathCost(int baseLife, int baseCost, int plevel);

		int getId() const;
		std::string getName() const;
		int getLife() const;
		int getCost() const;

		float getHealthUpdateRate() const;
		float getCostUpdateRate() const;
		int getWidth() const;
		int getHeight() const;
		int getMaxInstances() const;

		Zone getZone() const;
		
		void setId(int pid);
		void setZone(Zone pzone);
};
