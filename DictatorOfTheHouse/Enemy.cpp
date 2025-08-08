#pragma once
#include "Enemy.h"

using namespace std;

namespace Entity
{
	void Enemy::RemoveHP(int amount)
	{
		this->HP -= amount;
		if (this->HP <= 0) // player died 
		{
			Utils::PrintAndColor("\n" + this->Name + " has died.", Utils::ConsoleColor::Red);
			this->IsAlive = false;
			// scenemanager currentenemy = nullptr;
		}
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

	Enemy GenerateNewEnemy()
	{
		srand(static_cast<unsigned>(time(nullptr))); // make it actually random
		int min = Game::CurrentRoom->MinLevel;
		int max = Game::CurrentRoom->MaxLevel;

		int level = min + rand() % (max - min + 1);
		return Enemy("test", 2, 2, 1);
	}

	string GenerateEnemyName()
	{
		vector<string> enemyNames = { "Cricket", "Cockroach", "Ant", "Fly", "Mosquito" };
		vector<string> enemyColors = { "Dark", "Brown", "Black" };

		string name = enemyNames[rand() % enemyNames.size()];
		string color = enemyColors[rand() % enemyColors.size()];
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

