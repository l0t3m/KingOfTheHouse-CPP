#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Player.h"
#include "Enemy.h"

using namespace std;

namespace Combat
{
    bool Attack(Entity::Entity& attacker, Entity::Entity& defender);

    void PrintFightMenu();

    bool StartFight(Entity::Player* player, Entity::Enemy* enemy);
}