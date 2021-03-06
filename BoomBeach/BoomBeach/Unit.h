#pragma once
#include <string>
#include <fstream>
#include <vector>

class Unit
{
	protected:
		Unit();
		Unit(const Unit& model);
		Unit(int pid, int ptype, std::string pname, int pcost, float phealthUpdateRate, float pcostUpdateRate, int pmaxInstances, float pattackupdaterate,
			float pfireupdaterate, float prangeupdaterate, int pattack, int pfirerate, int prange, int phealth, int pspeed, bool parea, bool deployed);
		
		int id;
		int type;
		std::string name;

		int maxInstances;
		int cost;
		int attack; //Montant des dommages/soins possibles
		int firerate; //Frequence d'action
		int range; //Distance d'action
		int health;
		int level;
		int speed;
		bool area;
		bool deployed;

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
		int getSpeed() const;

		float getHealthUpdateRate() const;
		float getCostUpdateRate() const;
		float getAttackUpdateRate() const;
		float getFireUpdateRate() const;
		float getRangeUpdateRate() const;
		int getMaxInstances() const;

		void setId(int pid);
		void setDeployed(bool pdeployed);
		bool getDeployed() const;
};
