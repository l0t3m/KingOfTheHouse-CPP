#include <iostream>
#include <cctype>
#include <string>
#include "Exploration.h"
#include "Map.h"

using namespace std;

int main()
{
    Navigation::SetupRooms();

    while (!Game::IsGameOver) 
    {
        Exploration::Explore();
    }

    system("CLS");
    if (Game::Boss->IsAlive)
        cout << "Game over! you ddddddddied!";
    else
        cout << "You won by killing the boss!";
}
