#pragma once
#include "Entity.h"

using namespace std;

namespace Entity
{
	Entity::Entity(string name, int maxHP, int baseDamage, int level) 
		: Name(name), HP(maxHP), MaxHP(maxHP), BaseDamage(baseDamage), Level(level) { }

	Entity::Entity(string name, int maxHP, int baseDamage, int level, bool isPlayer)
		: Name(name), HP(maxHP), MaxHP(maxHP), BaseDamage(baseDamage), Level(level) { }

	bool Entity::RemoveHP(int amount) 
	{
		return false;
	}

	void Entity::AddHP(int amount, bool isFromItem) { }

	void Entity::PrintStats() { }
}
