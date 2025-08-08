#pragma once
#include "Room.h"
#include "Map.h"
#include "Enemy.h"

using namespace Navigation;

namespace Game
{
	extern Room* CurrentRoom;
	extern int DaysCounter;
	extern Entity::Enemy* CurrentEnemy;
}

