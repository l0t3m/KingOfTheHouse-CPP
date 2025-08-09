#include "Enemy.h"

namespace Entity
{
	Enemy::Enemy(string name, int maxHP, int baseDamage, int level)
		: Entity::Entity(name, maxHP, baseDamage, level) { }

	bool Enemy::RemoveHP(int amount)
	{
		this->HP -= amount;
		if (this->HP <= 0)
		{
			this->IsAlive = false;
			return true;
		}
		return false;
	}

	int Enemy::CalculateXPWorth()
	{
		return this->Level * 5 * (1 + rand() % 2);
	}

	void Enemy::PrintStats()
	{
		cout << "\n-----------------------------";
		cout << this->Name + " (" + (this->IsAlive ? "Alive" : "Dead") + ")" << endl;
		cout << this->HP << " / " << this->MaxHP << " HP" << endl;
		cout << "level " << this->Level << endl;
		cout << this->BaseDamage << " base damage" << endl;
		cout << "-----------------------------\n";
	}

	Enemy* GenerateNewEnemy(Navigation::Room* room)
	{
		srand(static_cast<unsigned>(time(nullptr))); // make it actually random
		int min = room->MinLevel;
		int max = room->MaxLevel;

		int level = min + rand() % (max - min + 1);
		return new Enemy(GenerateEnemyName(), GenerateEnemyMaxHP(level), GenerateEnemyBaseDamage(level), level);
	}

	string GenerateEnemyName()
	{
		const string enemyNames[] = { "Cricket", "Cockroach", "Ant", "Fly", "Mosquito" };
		const string enemyColors[] = { "Dark", "Brown", "Black" };

		int namesCount = sizeof(enemyNames) / sizeof(enemyNames[0]);
		int colorsCount = sizeof(enemyColors) / sizeof(enemyColors[0]);

		string name = enemyNames[rand() % namesCount];
		string color = enemyColors[rand() % colorsCount];

		return (color + " " + name);
	}

	int GenerateEnemyMaxHP(int level)
	{
		int randomStat = rand() % 100;
		int baseHP = 6;

		if (randomStat < 25)
			baseHP++;
		else if (randomStat < 50)
			baseHP--;

		return static_cast<int>(baseHP + (level * 0.125) + 4 * (level - 1));
	}

	int GenerateEnemyBaseDamage(int level)
	{
		int randomStat = rand() % 100;
		int baseDMG = 2;

		if (randomStat < 25)
			baseDMG++;
		else if (randomStat < 50)
			baseDMG--;

		return static_cast<int>(baseDMG + (level * 0.1) + 0.85 * (level - 1));
	}
};

