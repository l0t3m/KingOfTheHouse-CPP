#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Player.h"
#include "Boss.h"

using namespace std;

namespace Combat
{
    bool Attack(Entity::Entity& attacker, Entity::Entity& defender);

    void PrintFightMenu();

    void PrintBossFightDialog();

    bool StartFight(Entity::Player* player, Entity::Enemy* enemy);

    bool StartFight(Entity::Player* player, Entity::Boss* boss);
}