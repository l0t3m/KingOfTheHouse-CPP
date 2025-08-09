#include "Player.h"

namespace Entity
{
	Player::Player(string name, int weaponSlots)
		: Entity::Entity(name, 10, 4, 1, true), WeaponSlots(weaponSlots) 
	{
		Weapons = new Item::Weapon * [weaponSlots]; // allocate array of Weapon pointers

		for (int i = 0; i < weaponSlots; ++i) {
			Weapons[i] = nullptr; // set them to null initially
		}
	}

	Player::Player(string name, bool isGod, int weaponSlots)
		: Entity::Entity(name, 500, 50, 500, true), WeaponSlots(weaponSlots) 
	{
		Weapons = new Item::Weapon * [weaponSlots]; // allocate array of Weapon pointers

		for (int i = 0; i < weaponSlots; ++i) {
			Weapons[i] = nullptr; // set them to null initially
		}
		Weapons[0] = Item::GenerateNewWeapon(20);
	}

	bool Player::RemoveHP(int amount)
	{
		this->HP -= amount;
		if (this->HP <= 0) // player died 
		{
			Utils::PrintAndColor("You've been knocked out.", Utils::ConsoleColor::Red);
			cin.get();
			this->IsAlive = false;
			return true;
		}
		return false;
	}

	void Player::DoRest()
	{
		this->IsAlive = true;
		this->HP = this->MaxHP;
	}

	int Player::CalculateNextLevelXP()
	{
		return this->Level * 9 + (this->Level * this->Level);
	}

	int Player::CalculateUntilNextLevelXP()
	{
		return this->CalculateNextLevelXP() - this->XP;
	}

	void Player::GainXP(int xpAmount)
	{
		this->XP += xpAmount;
		int xpDif = CalculateUntilNextLevelXP();

		while (xpDif <= 0)
		{
			this->XP = abs(xpDif);
			this->LevelUp();
			xpDif = CalculateUntilNextLevelXP();
		}
	}

	void Player::LevelUp()
	{
		this->Level++;
		if (this->Level != 2)
			this->MaxHP = (int)(this->Level * 3.75);
		this->BaseDamage = (int)(4 + this->Level * 0.5);
		this->HP = MaxHP;

		Utils::PrintAndColor("Level up, You're now level " + to_string(this->Level) + "!",
			to_string(this->Level), Utils::ConsoleColor::Yellow);
		Utils::PrintAndColor("+ Stats improved");
		Utils::PrintAndColor("+ You've been fully healed", Utils::ConsoleColor::BrightGreen);
		cout << "\nPress enter to continue\n"; 
		cin.get();
	}

	void Player::PrintStats() 
	{
		cout << "--> STATS:";
		cout << "\n| [lvl." + to_string(this->Level) + "] " + this->Name + " | " + to_string(this->HP) + "/" + to_string(this->MaxHP) + "HP";
		cout << "\n| " + to_string(this->BaseDamage) + " base damage" << endl;

		this->PrintWeapons();
	}

	int Player::CountOccupiedWeaponSlots()
	{
		int slotsOccupied = 0;
		for (int i = 0; i < WeaponSlots; ++i) {
			if (Weapons[i] != nullptr)
				slotsOccupied++;
		}
		return slotsOccupied;
	}

	void Player::PrintWeapons()
	{
		cout << "\n--> WEAPONS: [" << this->CountOccupiedWeaponSlots() << "/" << WeaponSlots << "]";

		for (int i = 0; i < WeaponSlots; ++i) {
			if (Weapons[i] != nullptr)
				Weapons[i]->PrintWeapon();
		}
	}

}

