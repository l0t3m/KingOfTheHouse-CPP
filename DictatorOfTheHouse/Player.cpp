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

	// ---------------------------------------  Methods: --------------------------------------- //

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
		SavePlayer(this);
	}

	// ----------------------------------- XP Methods: ----------------------------------- //

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

	// ------------------------------------ Weapon Methods: ------------------------------------ //

	bool Player::AddWeapon(Item::Weapon* weapon) // new
	{
		SortWeapons();

		for (int i = 0; i < WeaponSlots; ++i) {
			if (Weapons[i] == nullptr)
			{
				Weapons[i] = weapon;
				Utils::PrintAndColor("\nAdded " + weapon->Name + " to your weapon inventory", Utils::ConsoleColor::Green);
				return true;
			}
		}
		return false;
	}

	bool Player::SwitchWeapon(Item::Weapon* oldWeapon, Item::Weapon* newWeapon)
	{
		SortWeapons();

		for (int i = 0; i < WeaponSlots; ++i) {
			if (Weapons[i] == oldWeapon)
			{
				Weapons[i] = newWeapon;
				Utils::PrintAndColor("\nSwitched " + oldWeapon->Name + " with " + newWeapon->Name, Utils::ConsoleColor::Green);
				return true;
			}
		}
		return false;
	}

	void Player::DestroyWeapon(Item::Weapon* targetWeapon) // new
	{
		for (int i = 0; i < WeaponSlots; ++i) {
			if (Weapons[i] == targetWeapon)
			{
				Weapons[i] = nullptr;
				Utils::PrintAndColor("\nYour " + targetWeapon->Name + " has ran out of uses and broke\n", Utils::ConsoleColor::Red);
				break;
			}
		}
		SortWeapons();
	}

	void Player::SortWeapons() // new
	{
		/*Item::Weapon** sortedWeapons = new Item::Weapon * [WeaponSlots];

		for (int i = 0; i < WeaponSlots; i++) {
			sortedWeapons[i] = nullptr;
		}

		int index = 0;
		for (int i = 0; i < WeaponSlots; i++) {
			if (Weapons[i] != nullptr) {
				sortedWeapons[index] = Weapons[i];
				index++;
			}
		}

		for (int i = 0; i < WeaponSlots; i++)
		{
			Weapons[i] = sortedWeapons[i];
		}

		delete[] sortedWeapons;*/

		int index = 0;

		for (int i = 0; i < WeaponSlots; i++) {
			if (Weapons[i] != nullptr) {
				Weapons[index] = Weapons[i];
				index++;
			}
		}

		for (int i = index; i < WeaponSlots; i++) {
			Weapons[i] = nullptr;
		}
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

	bool Player::IsWeaponInventoryFull() // new
	{
		return this->CountOccupiedWeaponSlots() == WeaponSlots;
	}

	

	// -------------------------------- Personal Prints: -------------------------------- //

	void Player::PrintStats()
	{
		cout << "--> STATS:";
		cout << "\n| [lvl." + to_string(this->Level) + "] " + this->Name + " | " + to_string(this->HP) + "/" + to_string(this->MaxHP) + "HP";
		cout << "\n|  " + to_string(this->BaseDamage) + " base damage" << endl;

		this->PrintWeapons();
	}

	void Player::PrintWeapons()
	{
		cout << "\n--> WEAPONS: [" << this->CountOccupiedWeaponSlots() << "/" << WeaponSlots << "]";

		for (int i = 0; i < WeaponSlots; ++i) {
			if (Weapons[i] != nullptr)
				Weapons[i]->PrintWeapon();
		}
	}
	Player* CreatePlayer()
	{
		ifstream playerFile("player.json");
		if (playerFile.good())
		{
			json loaded;
			playerFile >> loaded;
			Player* player = new Player(loaded.at("name"));
			player->WeaponSlots = loaded.at("slots");
			player->XP = loaded.at("xp");
			player->HP = loaded.at("hp");
			player->MaxHP = loaded.at("maxHP");
			player->BaseDamage = loaded.at("dmg");
			player->Level = loaded.at("level");
			playerFile.close();
			return player;
		}
		else
		{
			playerFile.close();
			Player* player = new Player("player");
			SavePlayer(player);

			return player;
		}
		return nullptr;
	}

	void SavePlayer(Player* player)
	{
		ofstream playerFile("player.json");
		json load;
		load = json{ {"name", player->Name},
				{"slots", player->WeaponSlots},
				{"xp", player->XP},
				{"hp", player->HP},
				{"maxHP", player->MaxHP},
				{"dmg", player->BaseDamage},
				{"level", player->Level } };
		playerFile << load.dump();
		playerFile.close();
	}
}

