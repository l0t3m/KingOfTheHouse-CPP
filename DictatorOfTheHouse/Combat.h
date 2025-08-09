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

    bool Attack(Entity::Entity* attacker, Entity::Entity* defender, Item::Weapon* weapon);

    void EndFight(Entity::Player* player, Entity::Enemy* enemy);

    void PrintFightMenu();

    void PrintWeaponSelectionMenu(Entity::Player* player);

    void PrintBossFightDialog();

    void StartWeaponSelection(Entity::Player* player, Entity::Enemy* enemy);

    bool StartFight(Entity::Player* player, Entity::Enemy* enemy);

    bool StartFight(Entity::Player* player, Entity::Boss* boss);
}