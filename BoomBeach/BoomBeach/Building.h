#pragma once
#include <string>
#include "Zone.h"
#include <fstream>

class Building
{
	private:
		
		Building();
		Building(const Building& model);
		Building(int pid, std::string pname, int type, int plife, int pcost, int plevel, float phealthUpdateRate,
			float pcostUpdateRate, int pmaxInstances, int pwidth, int pheight, Zone zone);

		int id;
		std::string name;
		int maxInstances;
		int cost;

		int width;
		int height;

		int life;
		int level;
		int type;

		float healthUpdateRate;
		float costUpdateRate;
		
		Zone zone;

	public:
		friend class BuildingFactory;
		friend std::ofstream& operator<< (std::ofstream& os, const Building &building);
		friend std::ostream& operator<< (std::ostream& os, const Building &building);

		int nextUpdateCost();
		int levelUp();
		void setHeathCost(int baseLife, int baseCost, int plevel);

		int getId() const;
		std::string getName() const;
		int getType() const;

		int getLife() const;
		int getLevel() const;
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
