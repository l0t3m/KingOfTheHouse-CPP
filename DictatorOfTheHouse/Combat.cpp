#include "Combat.h"

using namespace std;

namespace Combat 
{
    bool Attack(Entity::Entity* attacker, Entity::Entity* defender)
    {
        Utils::PrintAndColor(attacker->Name + " has dealt " + to_string(attacker->BaseDamage) + " damage to " + defender->Name, 
            to_string(attacker->BaseDamage) + " damage", Utils::ConsoleColor::BrightRed);
        cin.get();

        return defender->RemoveHP(attacker->BaseDamage);
    }

    void Flee(Entity::Entity* attacker, Entity::Entity* defender)
    {
        if (rand() % 100 < 80) 
        {
            cout << "As you attempt to flee, the enemy delivers a final blow...\n";
            Attack(attacker, defender);
            cin.get();
        }
    }

    void PrintFightMenu()
    {
        cout << "\nWhat action will you take?" << endl;
        cout << "1. Attack [Normal Attack]" << endl;
        cout << "2. Attack using a weapon" << endl;
        cout << "3. Flee\n" << endl;
    }

    void PrintFightMember(Entity::Player* player, Entity::Enemy* enemy)
    {
        Utils::PrintAndColor(
            player->Name + " [lvl." + to_string(player->Level) + "]: " + to_string(player->HP) + " HP | " + to_string(player->BaseDamage) + " DMG",
            player->Name, Utils::ConsoleColor::BrightMagenta);
        Utils::PrintAndColor(
            enemy->Name + " [lvl." + to_string(enemy->Level) + "]: " + to_string(enemy->HP) + " HP | " + to_string(enemy->BaseDamage) + " DMG",
            enemy->Name, Utils::ConsoleColor::BrightRed);
    }

    void PrintBossFightDialog()
    {
        cout << "\nKodaaaa";
        cout << "\nPress enter to start the fight." << endl;
        cin.get();
    }

	bool StartFight(Entity::Player* player, Entity::Enemy* enemy)
	{
        int choice;
        bool fled = false;

		Utils::PrintAndColor("While looking around for enemies, you encounter a [lvl." + to_string(enemy->Level) + " " + enemy->Name + "]\n", "[lvl." + to_string(enemy->Level) + " " + enemy->Name + "]\n", Utils::ConsoleColor::BrightRed);
        cout << "Press enter to continue." << endl;
        cin.get();

        while (player->IsAlive && enemy->IsAlive && !fled)
        {
            system("CLS");
            PrintFightMember(player, enemy);
            PrintFightMenu();

            try {
            
                cin >> choice;
                cin.ignore();
                system("CLS");

                switch (choice) {
                case 1:
                    Attack(player, enemy);

                    if (enemy->IsAlive)
                        Attack(enemy, player);
                    else
                    {
                        Utils::PrintAndColor(enemy->Name + " had died.", Utils::ConsoleColor::BrightRed);
                        cin.get();
                        system("CLS");
                        player->AddHP((int)(enemy->MaxHP / 4));
                        player->GainXP(enemy->CalculateXPWorth());
                        cin.get();
                    }
                    break;
                case 2:
                    // attack using weapon
                    break;
                case 3:
                    fled = true;
                    Flee(enemy, player);
                    break;
                default:
                    StartFight(player, enemy);
                    break;
                }
            }
            catch (...) {
                system("CLS");
            }
        }

        system("CLS");
        return player->IsAlive;
	}

    bool StartFight(Entity::Player* player, Entity::Boss* boss)
	{
        PrintBossFightDialog(); // comment if you don't want the dialog
        
        while (player->IsAlive && boss->IsAlive)
        {
            int choice;
            system("CLS");
            PrintFightMember(player, boss);
            PrintFightMenu();

            try {
            
                cin >> choice;
                cin.ignore();
                system("CLS");

                switch (choice) {
                case 1:
                    Attack(player, boss);

                    if (boss->IsAlive)
                        Attack(boss, player);
                    else
                    {
                        Utils::PrintAndColor(boss->Name + " had died.", Utils::ConsoleColor::BrightRed);
                        cin.get();
                        system("CLS");
                    }
                    break;
                case 2:
                    // attack using weapon
                    break;
                case 3:
                    cout << "Now that you stand in front of Koda, there is no escape...";
                    cin.get();
                    break;
                default:
                    StartFight(player, boss);
                    break;
                }
            }
            catch (...) {
                system("CLS");
            }
        }

        system("CLS");
        return player->IsAlive;
	}
}