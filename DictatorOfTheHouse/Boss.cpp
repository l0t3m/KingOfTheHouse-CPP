#include "Boss.h"

namespace Entity
{
	Boss::Boss(string name, int maxHP, int baseDamage, int level)
		: Enemy::Enemy(name, maxHP, baseDamage, level) { }

	bool Boss::RemoveHP(int amount)
	{
		this->HP -= amount;
		if (this->HP <= 0)
		{
			this->IsAlive = false;
			return true;
		}
		return false;
	}

	int Boss::CalculateXPWorth()
	{
		return this->Level * 6 * (1 + rand() % 2);
	}

	void Boss::PrintStats()
	{
		cout << "\n-----------------------------";
		cout << this->Name + " (" + (this->IsAlive ? "Alive" : "Dead") + ")" << endl;
		cout << this->HP << " / " << this->MaxHP << " HP" << endl;
		cout << "level " << this->Level << endl;
		cout << " " << this->BaseDamage << " base damage" << endl;
		cout << "-----------------------------\n";
	}
}

