#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Entity.h"

using namespace std;

namespace Entity
{
	class Enemy : public Entity
	{
	public:
		// Attributes
		bool IsDistracted = false;

		// Constructor:
		Enemy(string name, int maxHP, int baseDamage, int level);

		// Methods:
		bool RemoveHP(int amount) override;

		// AttackPlayer
		
		int CalculateXPWorth();

		void PrintStats() override;
	};

	Enemy GenerateNewEnemy();

	string GenerateEnemyName();

	int GenerateEnemyMaxHP(int level);

	int GenerateEnemyBaseDamage(int level);
}

