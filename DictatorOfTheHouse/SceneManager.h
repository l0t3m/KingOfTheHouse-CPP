#pragma once
#include "Map.h"
#include "Player.h"
#include "Boss.h"

using namespace Navigation;

namespace Game
{
	extern Room* CurrentRoom;
	extern int DaysCounter;
	extern Entity::Player* Player;
	extern Entity::Boss* Boss;
	extern bool IsGameOver;
}

