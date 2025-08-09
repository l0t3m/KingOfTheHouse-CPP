#include "Player.h"

namespace Entity
{
	Player::Player(string name, int weaponSlots)
		: Entity::Entity(name, 10, 4, 1, true), WeaponSlots(weaponSlots) { }

	bool Player::RemoveHP(int amount)
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

	void Player::DoRest()
	{
		this->IsAlive = true;
		this->HP = this->MaxHP;
		//Game::DaysCounter++;
	}
}

