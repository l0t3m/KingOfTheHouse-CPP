#pragma once
#include "Functions.h"
#include "Entity.h"
#include "Weapon.h"
#include <fstream>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;
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

			// Level Related Methods:
			int CalculateNextLevelXP();

			int CalculateUntilNextLevelXP();

			void GainXP(int xpAmount);

			void LevelUp();

			// Weapon Related Methods:
			bool AddWeapon(Item::Weapon* weapon); // new

			bool SwitchWeapon(Item::Weapon* oldWeapon, Item::Weapon* newWeapon); // new

			void DestroyWeapon(Item::Weapon* targetWeapon); // new

			void SortWeapons(); // new

			int CountOccupiedWeaponSlots();

			bool IsWeaponInventoryFull(); // new

			// Prints Related Methods:
			void PrintStats() override;

			void PrintWeapons();
	};

	Player* CreatePlayer();

	void SavePlayer(Player* player);
}

