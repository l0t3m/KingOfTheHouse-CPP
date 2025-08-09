#include "Weapon.h"

namespace Item
{
	Weapon::Weapon()
		: Name("Unset"), Durability(1), Damage(1) { }

	Weapon::Weapon(string name, int durability, int damage)
	: Name(name), Durability(durability), Damage(damage) { }

	bool Weapon::RemoveDurability()
	{
		this->Durability--;
		return this->Durability <= 0;
	}

	void Weapon::PrintWeapon()
	{
		cout << "\n| " << this->Name << ":";
		cout << "\n|  "<< to_string(this->Damage) + " damage | " << to_string(this->Durability) << " uses left";
	}

	Weapon* GenerateNewWeapon(int level)
	{
		int baseDurability = 4;
		int baseDamage = 2;
		int randomStat = rand() % 100;

		if (randomStat < 25) {
			baseDamage++;

			if (rand() % 100 < 50)
				baseDurability++;
			else
				baseDurability--;
		}
		else if (randomStat < 50) {
			baseDamage += 2;

			if (rand() % 100 < 25)
				baseDurability += 2;
			else
				baseDurability++;
		}
		else {
			if (rand() % 100 < 60)
				baseDurability += 2;
			else
				baseDurability++;
		}

		return new Weapon(GenerateWeaponName(), baseDurability, static_cast<int>(baseDamage + level * 0.5));
	}

	string GenerateWeaponName()
	{
		const string WeaponNames[] = { "Sword", "Knife", "Katana", "Machete", "Axe", "Spear"};
		const string WeaponDescriptions[] = { "Sharp", "Keen", "Glossy", "Sparkling", "Polished", "Shiny", "Rusty", "Shattered", "Elegant", "Lightweight", "Mythical" };

		int namesCount = sizeof(WeaponNames) / sizeof(WeaponNames[0]);
		int descriptionsCount = sizeof(WeaponDescriptions) / sizeof(WeaponDescriptions[0]);

		string name = WeaponNames[rand() % namesCount];
		string description = WeaponDescriptions[rand() % descriptionsCount];

		return description + " " + name;
	}
}