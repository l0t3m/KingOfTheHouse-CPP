#include "Exploration.h"
#include "Functions.h"

using namespace std;

void Exploration::Explore() 
{
    Utils::PrintRoom();
	//cout << Game::CurrentRoom->Name;

    cout << "\n\nWhat would you like to do?";
    cout << "\n1. Examine the room";
    cout << "\n2. View stats and inventory";
    cout << "\n3. Leave the room";

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
                if (Game::CurrentRoom->DangerStatus == Dangerous)
                    LookForEnemies();
                if (Game::CurrentRoom->DangerStatus == Safe)
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
    // print room
    // print leave room
    cout << "You chose to leave the room, choose a path" << endl;

    cout << "1. Stay\n";
    map<int, Room*> roomDict;
    int counter = 2;
    for (Room* room : Game::CurrentRoom->ConnectedRooms) {
        roomDict[counter] = room;

        cout << counter << ". " << room->Name << endl;
        /*Functions::PrintAndColor(std::to_string(counter) + ". " + room->Name + " " + room->status,
            room->status, room->statusColor);*/
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
        /*if (selectedRoom->isBossRoom && selectedRoom->boss.isAlive) {
            if (SceneManager::player->level >= selectedRoom->boss.level) {
                SceneManager::currentEnemy = &selectedRoom->boss;
                Combat::StartBossFight();
            }
            else {
                Functions::TypeLine("As you get closer to Koda, he grows more intimidating with each step. You shake your head, your tail drooping between your legs.");
                Functions::PrintAndColorType("\nIn that moment, you decide to turn around and avoid facing him.",
                    "turn around and avoid facing him", ConsoleColor::DarkRed);
                std::cout << "\nPress enter to continue."; std::cin.get(); std::system("CLS");
            }
        }
        else {
            SceneManager::currentRoom = selectedRoom;
        }*/
        Game::CurrentRoom = selectedRoom;
    }
    catch (...) {
        Move();
    }
}

void Exploration::Examine()
{
    Game::CurrentRoom->DiscoveredStatus = true;

    if (Game::CurrentRoom->DangerStatus == Dangerous)
        //Functions::PrintAndColor("This area feels dangerous...", "dangerous", SceneManager::currentRoom->statusColor);
        cout << "This area feels dangerous..." << endl;
    else if (Game::CurrentRoom->DangerStatus == Neutral)
        //Functions::PrintAndColor("This area looks neutral but still not safe enough.", "neutral", SceneManager::currentRoom->statusColor);
        cout << "This area looks neutral but still not safe enough." << endl;
    else
        //Functions::PrintAndColor("This area looks safe, enemies can't reach this area.", "safe", SceneManager::currentRoom->statusColor);
        cout << "This area looks safe, enemies can't reach this area." << endl;

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