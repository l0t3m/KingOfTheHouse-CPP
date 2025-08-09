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

			// Methods:
			bool RemoveHP(int amount) override;

			void DoRest();
	};
}

