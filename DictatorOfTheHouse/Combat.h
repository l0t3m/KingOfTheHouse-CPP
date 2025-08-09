#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Player.h"
#include "Boss.h"
#include "Weapon.h"

using namespace std;

namespace Combat
{
    bool Attack(Entity::Entity& attacker, Entity::Entity& defender);

    bool Attack(Entity::Player* player, Entity::Enemy* enemy, Item::Weapon* weapon);

    void EndFight(Entity::Player* player, Entity::Enemy* enemy);

    void PrintFightMenu();

    void PrintWeaponFindingMenu(Entity::Player* player); // new

    void PrintWeaponSelectionMenu(Entity::Player* player);

    void PrintBossFightDialog();

    void StartWeaponFindingMenu(Entity::Player* player, Item::Weapon* weapon); // new

    void StartWeaponSelection(Entity::Player* player, Entity::Enemy* enemy);

    bool StartFight(Entity::Player* player, Entity::Enemy* enemy);

    bool StartFight(Entity::Player* player, Entity::Boss* boss);
}