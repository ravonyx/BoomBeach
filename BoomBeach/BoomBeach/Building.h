#pragma once
#include <string>
#include "Zone.h"
#include <fstream>
#include "Unit.h"

class Building
{
	private:
		
		Building();
		Building(const Building& model);
		Building(int pid, std::string pname, int type, int plife, int pcost, int plevel, int power, int range, int fireRate, bool area, float phealthUpdateRate,
			float pcostUpdateRate, int pmaxInstances, int pwidth, int pheight, Zone zone);

		int id;
		std::string name;
		int maxInstances;
		int cost;

		int width;
		int height;

		int life;
		int addedLife=0;
		int totalLife;
		int level;
		int type;

		int power;
		int range; // 1 : Around (Short), 2 : Two Panels (Medium), 3 : Three Panels (Long)
		int defenseBonus = 0;
		int fireRate;
		bool area;

		float healthUpdateRate;
		float costUpdateRate;

		int targetType;
		int lifeMax;
		// Target Types
		// 0 Nothing
		// 1 Low HP Units
		// 2 High HP Units
		// 3 Closest Unit
		// 4 Closest to HQ
		// 5 Strongest Unit
		// 6 Closest Support Unit
		
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

		int getLife() const; //Returns total Life
		int getLevel() const;
		int getCost() const;
		int getPower() const;
		int getRange() const;
		int getFireRate() const;
		bool getArea() const;

		float getHealthUpdateRate() const;
		float getCostUpdateRate() const;
		int getWidth() const;
		int getHeight() const;
		int getMaxInstances() const;
		int getTargetType() const;

		Zone getZone() const;
		
		void setId(int pid);
		void setZone(Zone pzone);
		void addLife(const int value);
		void setAddedLife(const int value);
		void setTargetType(const int value);

		void takeDamage(const int amount);
};
