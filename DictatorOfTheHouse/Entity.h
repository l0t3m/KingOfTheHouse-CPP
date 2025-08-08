#pragma once
#include <cstdlib>
#include <ctime>
#include "Room.h" 

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

		Entity(string name, int maxHP, int baseDamage, int level); // for boss and enemies
			//: Name(name), HP(maxHP), MaxHP(maxHP), BaseDamage(baseDamage), Level(level) { }

		Entity(string name, int maxHP, int baseDamage, int level, bool isPlayer); // for player (isPlayer is temp until weapons)
			/*: Name(name), HP(maxHP), MaxHP(maxHP), BaseDamage(baseDamage), Level(level);*/

		// Methods:
		virtual bool RemoveHP(int amount);

		virtual void AddHP(int amount, bool isFromItem);

		virtual void PrintStats();
	};
}
