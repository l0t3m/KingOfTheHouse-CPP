#include "Combat.h"

namespace Combat 
{
    bool Attack(Entity::Entity* attacker, Entity::Entity* defender)
    {
        Utils::PrintAndColor(attacker->Name + " has dealt " + to_string(attacker->BaseDamage) + " damage to " + defender->Name, 
            to_string(attacker->BaseDamage) + " damage", Utils::ConsoleColor::BrightRed);
        cin.get();

        return defender->RemoveHP(attacker->BaseDamage);
    }

    bool Attack(Entity::Player* player, Entity::Enemy* enemy, Item::Weapon* weapon)
    {
        Utils::PrintAndColor(player->Name + " has dealt " + to_string(weapon->Damage) + " damage to " + enemy->Name,
            to_string(weapon->Damage) + " damage", Utils::ConsoleColor::BrightRed);
        
        cin.get();

        if (weapon->RemoveDurability())
        {
            player->DestroyWeapon(weapon);
        }
        
        return enemy->RemoveHP(weapon->Damage);
    }

    void Flee(Entity::Entity* attacker, Entity::Entity* defender)
    {
        if (rand() % 100 < 20) 
        {
            cout << "As you attempt to flee, the enemy delivers a final blow...\n";
            Attack(attacker, defender);
            cin.get();
        }
    }
    
    void EndFight(Entity::Player* player, Entity::Enemy* enemy)
    {
        Utils::PrintAndColor(enemy->Name + " had died.", Utils::ConsoleColor::BrightRed);
        cin.get();
        system("CLS");
        player->AddHP((int)(enemy->MaxHP / 4));
        player->GainXP(enemy->CalculateXPWorth());
    }

    void PrintFightMenu()
    {
        cout << "\nWhat action will you take?" << endl;
        cout << "1. Attack [Normal Attack]" << endl;
        cout << "2. Attack using a weapon" << endl;
        cout << "3. Flee\n" << endl;
    }

    void PrintWeaponFindingMenu(Entity::Player* player)
    {
        cout << "\n\nWhat would you like to do?";
        if (!player->IsWeaponInventoryFull())
            cout << "\n1. Take it";
        else
            cout << "\n1. Replace it with one of your weapons [Inventory is full]";
        cout << "\n2. Leave it\n";
    }

    void PrintWeaponSelectionMenu(Entity::Player* player)
    {
        player->SortWeapons();

        cout << "\nEnter the number of the weapon you want to use\n";

        cout << "\n--> WEAPONS: [" << player->CountOccupiedWeaponSlots() << "/" << player->WeaponSlots << "]";
        for (int i = 0; i < player->WeaponSlots; i++)
        {
            if (player->Weapons[i] != nullptr)
            {
                cout << "\n| " << i+1 << ". " << player->Weapons[i]->Name << ": " << player->Weapons[i]->Damage << " damage | " << player->Weapons[i]->Durability << " uses left";
            }
        }
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

    void StartWeaponFindingMenu(Entity::Player* player, Item::Weapon* weapon)
    {
        Utils::PrintAndColor("You let out a relieved purr after defeating the enemy, then suddenly spot a " + weapon->Name + ".", 
            weapon->Name, Utils::ConsoleColor::Yellow);
        weapon->PrintWeapon();
        PrintWeaponFindingMenu(player);

        int choice;
        try
        {
            cin >> choice;
            cin.ignore();
            system("CLS");

            switch (choice)
            {
            case 1:
                if (player->IsWeaponInventoryFull())
                    cout << "weapon switch menu";
                    // weapon switch menu
                else
                {
                    cout << "You chose to take it";
                    player->AddWeapon(weapon);
                }
                break;
            case 2:
                cout << "You chose to leave it\n";
                break;
            default:
                StartWeaponFindingMenu(player, weapon);
                break;
            }
        }
        catch (...)
        {
            system("CLS");
        }

        cout << "\nPress enter to continue" << endl;
        cin.get();
    }

    void StartWeaponSelection(Entity::Player* player, Entity::Enemy* enemy)
    {
        system("CLS");
        PrintFightMember(player, enemy);
        PrintWeaponSelectionMenu(player);
        
        int choice;
        try
        {
            int backChoice = player->CountOccupiedWeaponSlots() + 1;
            cout << "\n| " << backChoice << ". Go back\n";

            cin >> choice;
            cin.ignore();
            system("CLS");
            if (choice == backChoice)
            {
                return;
            }
            
            Attack(player, enemy, player->Weapons[choice - 1]);
        }
        catch (...)
        {
            system("CLS");
            StartWeaponSelection(player, enemy);
        }

        if (enemy->IsAlive)
            Attack(enemy, player);
        else
            EndFight(player, enemy);
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
                        EndFight(player, enemy);
                    break;
                case 2:
                    StartWeaponSelection(player, enemy);
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

        if (!player->IsAlive)
            return false;
        if ((rand() % 100) < 80 && !fled)
        {
            system("CLS");
            StartWeaponFindingMenu(player, Item::GenerateNewWeapon(enemy->Level));
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
                    StartWeaponSelection(player, boss);
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