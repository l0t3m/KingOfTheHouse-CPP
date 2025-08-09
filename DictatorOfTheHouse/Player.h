#pragma once
#include "Functions.h"
#include "Entity.h"

using namespace std;

namespace Entity 
{
	class Player : public Entity
	{
		public:
			// Attributes
			int XP = 0;
			// itemInventorySlots = 3
			// ItemInventory
			int WeaponSlots = 3;

			// Constructor:
			Player(string name, int weaponSlots = 3);
			Player(string name, int weaponSlots = 3, bool isGod = true);

			// Methods:
			bool RemoveHP(int amount) override;

			void DoRest();

			int CalculateNextLevelXP();

			int CalculateUntilNextLevelXP();

			void GainXP(int xpAmount);

			void LevelUp();

			// Prints Related Methods:
			void PrintStats() override;
	};
}

