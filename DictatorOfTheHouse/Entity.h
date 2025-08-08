#pragma once
#include <cstdlib>
#include <ctime>
#include "Functions.h"

using namespace std;

namespace Entity
{
	class Entity 
	{
	public:
		// Attribues:
		string Name;
		int HP;
		int MaxHP;
		int BaseDamage;
		// weapons
		bool IsAlive = true;
		int Level = 1;

		Entity(string name, int maxHP, int baseDamage, int level) // for boss and enemies
			: Name(name), HP(maxHP), MaxHP(maxHP), BaseDamage(baseDamage), Level(level) { }

		Entity(string name, int maxHP, int baseDamage, int level, bool isPlayer) // for player (isPlayer is temp until weapons)
			: Name(name), HP(maxHP), MaxHP(maxHP), BaseDamage(baseDamage), Level(level) {
		}

		// Methods:
		virtual void RemoveHP(int amount) 
		{
			this->HP -= amount;
			if (this->HP <= 0)
				this->IsAlive = false;
		}

		virtual void AddHP(int amount, bool isFromItem = true) 
		{
			this->HP += amount;
			if (this->HP > this->MaxHP)
				this->HP = this->MaxHP;
			if (!isFromItem)
				Utils::PrintAndColor("\n" + this->Name + " has healed for " + to_string(amount) + " HP by defeating an enemy,");
		}

		virtual void PrintStats() 
		{
			cout << "\n-----------------------------";
			cout << this->Name + " (" + (this->IsAlive ? "Alive" : "Dead") + ")" << endl;
			cout << this->HP << " / " << this->MaxHP << " HP" << endl;
			cout << "level " << this->Level << endl;
			cout << "-----------------------------\n";
		}
	};
}
