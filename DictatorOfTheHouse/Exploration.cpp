#include "Exploration.h"
#include "Functions.h"

using namespace std;

void Exploration::Explore() 
{
    Utils::PrintRoom();

    try {
        int choice;
        cin >> choice;
        cin.ignore();
        system("CLS");

        switch (choice) {
        case 1: 
            Examine(); 
            break;
        case 2: 
            Stats(); 
            break;
        case 3: 
            Move(); 
            break;
        case 4:
            if (Game::CurrentRoom->DiscoveredStatus) {
                if (Game::CurrentRoom->DangerStatus == RoomDangerStatus::Dangerous)
                    LookForEnemies();
                if (Game::CurrentRoom->DangerStatus == RoomDangerStatus::Safe)
                    DoRest();
            }
            break;
        default:
            Explore(); 
            break;
        }
    }
    catch (...) {
        system("CLS");
    }
}

void Exploration::Move() 
{
    system("CLS");

    Utils::PrintRoom();
    Utils::PrintAndColor("\n\nYou chose to leave the room, which path will you take?", "leave");

    cout << "\n1. Stay\n";
    map<int, Room*> roomDict;
    int counter = 2;

    for (Room* room : Game::CurrentRoom->ConnectedRooms) {
        roomDict[counter] = room;

        Utils::PrintAndColor(to_string(counter) + ". " + room->Name + " [" + Utils::GetDangerStatusDiscovered(room) + "]",
            Utils::GetDangerStatusDiscovered(room),
            Utils::GetDangerStatusColor(room));
        
        counter++;
    }

    try {
        int choice;
        cin >> choice;
        cin.ignore();
        system("CLS");

        if (choice == 1) {
            Explore();
            return;
        }

        Room* selectedRoom = roomDict[choice];

        if (selectedRoom->IsBossRoom) 
        {
            cout << "As you get closer to Koda, he grows more intimidating with each step. You shake your head, your tail drooping between your legs.";
            Utils::PrintAndColor("\nIn that moment, you decide to turn around and avoid facing him.",
                "turn around and avoid facing him", Utils::ConsoleColor::Red);
            std::cout << "\nPress enter to continue."; std::cin.get(); std::system("CLS");
        }
        else {
            Game::CurrentRoom = selectedRoom;
        }
        /*
        if (selectedRoom->isBossRoom && selectedRoom->boss.isAlive) {
            if (SceneManager::player->level >= selectedRoom->boss.level) {
                SceneManager::currentEnemy = &selectedRoom->boss;
                Combat::StartBossFight();
            }
            else {
                Functions::TypeLine("As you get closer to Koda, he grows more intimidating with each step. You shake your head, your tail drooping between your legs.");
                Utils::PrintAndColorType("\nIn that moment, you decide to turn around and avoid facing him.",
                    "turn around and avoid facing him", ConsoleColor::DarkRed);
                std::cout << "\nPress enter to continue."; std::cin.get(); std::system("CLS");
            }
        }
        else {
            SceneManager::currentRoom = selectedRoom;
        }*/
    }
    catch (...) {
        Move();
    }
}

void Exploration::Examine()
{
    Game::CurrentRoom->DiscoveredStatus = true;

    if (Game::CurrentRoom->DangerStatus == RoomDangerStatus::Dangerous)
        Utils::PrintAndColor("This area feels dangerous...", "dangerous", Utils::GetDangerStatusColor());
    else if (Game::CurrentRoom->DangerStatus == RoomDangerStatus::Neutral)
        Utils::PrintAndColor("This area looks neutral but still not safe enough.", "neutral", Utils::GetDangerStatusColor());
    else
        Utils::PrintAndColor("This area looks safe, enemies can't reach this area.", "safe", Utils::GetDangerStatusColor());

    /*if (!SceneManager::currentRoom->ItemsArr.empty() && SceneManager::currentRoom->ItemsArr[0] != nullptr) {
        std::cout << "\n";
        Functions::ItemFindingMenu(SceneManager::currentRoom->ItemsArr[0]);
    }*/

    cout << "\nPress enter to continue."; 
    cin.get(); 
    system("CLS");
}

void Exploration::LookForEnemies()
{
    /*if (rand() % 100 < 95) {
        if (!Combat::StartFight(Enemy::GenerateNewEnemy())) {
            DoRespawn();
        }
    }
    else {
        std::cout << "You didn't find any enemies.";
        std::cout << "\nPress enter to continue."; std::cin.get(); std::system("CLS");
    }*/

    cout << "You didn't find any enemies.";
    cout << "\nPress enter to continue."; 
    cin.get(); 
    system("CLS");
}

void Exploration::DoRest()
{
    //SceneManager::player->DoRest();
    cout << "A day has passed...";
    cout << "\nHP has been restored to max";
    cout << "\nPress enter to wake up.";
    cin.get(); 
    system("CLS");
}

void Exploration::Stats()
{
    //SceneManager::player->PrintStats();
    cout << "\nPress enter to continue."; 
    cin.get(); 
    system("CLS");
}

void Exploration::DoRespawn()
{
    std::cout << "\nPress enter to continue."; 
    std::cin.get(); 
    std::system("CLS");

    //SceneManager::player->DoRest();
    Game::CurrentRoom = &Navigation::LivingRoom;
}