#include "Exploration.h"

using namespace std;

void Exploration::Explore() 
{
    Utils::PrintRoom(Game::CurrentRoom);

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

    Utils::PrintRoom(Game::CurrentRoom);
    Utils::PrintAndColor("\nYou chose to leave the room, which path will you take?", "leave");

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

        if (selectedRoom->IsBossRoom && Game::Boss->IsAlive) 
        {
            if (Game::Player->Level >= Game::Boss->Level) // player can fight boss
            {
                Combat::StartFight(Game::Player, Game::Boss); // returns true if player died - game over
                Game::IsGameOver = true;
            }
            else // player level is too low
            {
                cout << "As you get closer to Koda, he grows more intimidating with each step. \nYou shake your head, your tail drooping between your legs.";
                Utils::PrintAndColor("\nIn that moment, you decide to turn around and avoid facing him.",
                    "turn around and avoid facing him", Utils::ConsoleColor::Red);
                std::cout << "\nPress enter to continue."; std::cin.get(); std::system("CLS");
            }
        }
        else {
            Game::CurrentRoom = selectedRoom;
        }
    }
    catch (...) {
        Move();
    }
}

void Exploration::Examine()
{
    Game::CurrentRoom->DiscoveredStatus = true;

    if (Game::CurrentRoom->DangerStatus == RoomDangerStatus::Dangerous)
        Utils::PrintAndColor("This area feels dangerous...", "dangerous", Utils::GetDangerStatusColor(Game::CurrentRoom));
    else if (Game::CurrentRoom->DangerStatus == RoomDangerStatus::Neutral)
        Utils::PrintAndColor("This area looks neutral but still not safe enough.", "neutral", Utils::GetDangerStatusColor(Game::CurrentRoom));
    else
        Utils::PrintAndColor("This area looks safe, enemies can't reach this area.", "safe", Utils::GetDangerStatusColor(Game::CurrentRoom));

    cout << "\nPress enter to continue."; 
    cin.get(); 
    system("CLS");
}

void Exploration::LookForEnemies()
{
    if (rand() % 100 < 95) {
        if (!Combat::StartFight(Game::Player, Entity::GenerateNewEnemy(Game::CurrentRoom))) {
            DoRespawn();
        }
    }
    else
    {
        cout << "You didn't find any enemies.";
        cout << "\nPress enter to continue."; 
        cin.get(); 
        system("CLS");
    }
}

void Exploration::DoRest()
{
    Game::Player->DoRest();
    Utils::PrintAndColor("A day has passed...", Utils::ConsoleColor::Yellow);
    Utils::PrintAndColor("\nHP has been restored to max", Utils::ConsoleColor::Green);
    cout << "\nPress enter to wake up...";
    cin.get(); 
    system("CLS");
}

void Exploration::Stats()
{
    Game::Player->PrintStats();
    cout << "\nPress enter to continue."; 
    cin.get(); 
    system("CLS");
}

void Exploration::DoRespawn()
{
    Game::Player->DoRest();
    Game::CurrentRoom = &Navigation::LivingRoom;
}