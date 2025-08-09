#pragma once
#include <iostream>
#include <string>

using namespace std;

namespace Item
{
	class Weapon
	{
	public:
		string Name;
		int Durability;
		int Damage;

		Weapon();

		Weapon(string name, int durability, int damage);

		bool RemoveDurability();

		void PrintWeapon();
	};

	Weapon* GenerateNewWeapon(int level);

	string GenerateWeaponName();
}