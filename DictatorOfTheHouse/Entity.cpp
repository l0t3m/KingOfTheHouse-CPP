#include "Entity.h"

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

	void Entity::AddHP(int amount)
	{
		this->HP += amount;
		if (this->HP > this->MaxHP)
			this->HP = this->MaxHP;
		Utils::PrintAndColor(this->Name + " has healed for " + to_string(amount) + " HP by defeating an enemy\n", Utils::ConsoleColor::Green);
	}

	void Entity::PrintStats() { }
}
