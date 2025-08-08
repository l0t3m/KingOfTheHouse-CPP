#pragma once
#include "Functions.h"
#include "Entity.h"

using namespace std;

namespace Entity
{
	class Boss : public Enemy
	{
	public:
		// Constructor:
		Boss(string name, int maxHP, int baseDamage, int level)
			: Enemy(name, maxHP, baseDamage, level) {}

		// Methods:
		void RemoveHP(int amount) override
		{
			this->HP -= amount;
			if (this->HP <= 0) // player died 
			{
				Utils::PrintAndColor("\nThe boss" + this->Name + " was defeated.", Utils::ConsoleColor::Red);
				this->IsAlive = false;
				// scenemanager currentenemy = nullptr;
			}
		}

		// AttackPlayer

		int CalculateXPWorth()
		{
			return this->Level * 6 * (1 + rand() % 2);
		}

		void PrintStats() override
		{
			cout << "\n-----------------------------";
			cout << this->Name + " (" + (this->IsAlive ? "Alive" : "Dead") + ")" << endl;
			cout << this->HP << " / " << this->MaxHP << " HP" << endl;
			cout << "level " << this->Level << endl;
			cout << this->BaseDamage << " base damage" << endl;
			cout << "-----------------------------\n";
		}
	};
}

