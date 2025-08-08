#pragma once
#include <cstdlib>
#include <ctime>
#include "Entity.h"

using namespace std;

namespace Entity
{
	class Enemy : public Entity::Entity
	{
	public:
		// Attributes
		bool IsDistracted = false;

		// Constructor:
		Enemy(string name, int maxHP, int baseDamage, int level)
			: Entity::Entity(name, maxHP, baseDamage, level) { }

		// Methods:
		void RemoveHP(int amount) override
		{
			this->HP -= amount;
			if (this->HP <= 0) // player died 
			{
				Utils::PrintAndColor("\n" + this->Name + " has died.", Utils::ConsoleColor::Red);
				this->IsAlive = false;
				// scenemanager currentenemy = nullptr;
			}
		}

		// AttackPlayer
		
		int CalculateXPWorth()
		{
			return this->Level * 5 * (1 + rand() % 2);
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

	static Enemy GenerateNewEnemy()
	{
		srand(static_cast<unsigned>(time(nullptr))); // make it actually random
		int min = Game::CurrentRoom->MinLevel;
		int max = Game::CurrentRoom->MaxLevel;

		int level = min + rand() % (max - min + 1);
		return Enemy("test", 2, 2, 1);
	}

	static string GenerateEnemyName()
	{
		vector<string> enemyNames = { "Cricket", "Cockroach", "Ant", "Fly", "Mosquito" };
		vector<string> enemyColors = { "Dark", "Brown", "Black" };

		string name = enemyNames[rand() % enemyNames.size()];
		string color = enemyColors[rand() % enemyColors.size()];
		return (color + " " + name);
	}

	static int GenerateEnemyMaxHP(int level)
	{
		int randomStat = rand() % 100;
		int baseHP = 6;

		if (randomStat < 25)
			baseHP++;
		else if (randomStat < 50)
			baseHP--;

		return static_cast<int>(baseHP + (level * 0.125) + 4 * (level - 1));
	}

	static int GenerateEnemyBaseDamage(int level) 
	{
		int randomStat = rand() % 100;
		int baseDMG = 2;

		if (randomStat < 25)
			baseDMG++;
		else if (randomStat < 50)
			baseDMG--;

		return static_cast<int>(baseDMG + (level * 0.1) + 0.85 * (level - 1));
	}
}

