#pragma once
#include <string>
#include <fstream>

class Unit
{
	private:
		Unit();
		Unit(const Unit& model);
		Unit(int pid, int ptype, std::string pname, int pcost, float phealthUpdateRate, float pcostUpdateRate, int pmaxInstances, float pattackupdaterate,
			float pfireupdaterate, float prangeupdaterate, int pattack, int pfirerate, int prange, int phealth);

		int id;
		int type;
		std::string name;

		int maxInstances;
		int cost;
		int attack;
		int firerate;
		int range;
		int health;
		int level;

		float attackUpdateRate;
		float firerateUpdateRate;
		float rangeUpdateRate;
		float healthUpdateRate;
		float costUpdateRate;

	public:
		friend class UnitFactory;
		friend std::ofstream& operator<< (std::ofstream& os, const Unit &unit);
		friend std::ostream& operator<< (std::ostream& os, const Unit &unit);

		int nextUpdateCost();
		int levelUp();
		void setAttributes(int baseLife, int baseCost, int baseAttack, int baseFirerate, int baseRange, int plevel);

		std::string getName() const;
		int getId() const;
		int getType() const;
		int getLevel() const;

		int getLife() const;
		int getCost() const;
		int getAttack() const;
		int getFirerate() const;
		int getRange() const;

		float getHealthUpdateRate() const;
		float getCostUpdateRate() const;
		float getAttackUpdateRate() const;
		float getFireUpdateRate() const;
		float getRangeUpdateRate() const;
		int getMaxInstances() const;

		void setId(int pid);
};
