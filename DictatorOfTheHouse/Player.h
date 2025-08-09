#pragma once
#include "Functions.h"
#include "Entity.h"
#include "Weapon.h"

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
			Item::Weapon** Weapons;

			// Constructor:
			Player(string name, int weaponSlots = 3);
			Player(string name, bool IsGod, int weaponSlots = 3);

			// Methods:
			bool RemoveHP(int amount) override;

			void DoRest();

			int CalculateNextLevelXP();

			int CalculateUntilNextLevelXP();

			void GainXP(int xpAmount);

			void LevelUp();

			int CountOccupiedWeaponSlots();

			// Prints Related Methods:
			void PrintStats() override;
			void PrintWeapons();
	};
}

