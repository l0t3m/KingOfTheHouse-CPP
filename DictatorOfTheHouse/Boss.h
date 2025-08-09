#pragma once
#include "Functions.h"
#include "Enemy.h"

using namespace std;

namespace Entity
{
	class Boss : public Enemy
	{
	public:
		// Constructor:
		Boss(string name, int maxHP, int baseDamage, int level);

		// Methods:
		bool RemoveHP(int amount) override;

		// AttackPlayer

		int CalculateXPWorth();

		void PrintStats() override;
	};
}

