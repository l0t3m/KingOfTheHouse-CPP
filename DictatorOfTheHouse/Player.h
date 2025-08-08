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
			Player(string name, int weaponSlots = 3)
				: Entity::Entity(name, 10, 4, 1 , true), WeaponSlots(weaponSlots) { }

			// Methods:
			bool RemoveHP(int amount) override
			{
				this->HP -= amount;
				if (this->HP <= 0) // player died 
				{
					//Utils::PrintAndColor("\nYou've been knocked out.", Utils::ConsoleColor::Magenta);
					this->IsAlive = false;
					return true;
				}
				return false;
			}

			void DoRest()
			{
				this->IsAlive = true;
				this->HP = this->MaxHP;
				//Game::DaysCounter++;
			}
	};
}

