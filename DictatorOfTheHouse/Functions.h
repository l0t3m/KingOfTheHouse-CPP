#pragma once
#include "Exploration.h"
#include "Map.h"

using namespace std;

namespace Utils 
{
	enum class ConsoleColor {
		Black = 30,
		Red = 31,
		Green = 32,
		Yellow = 33,
		Blue = 34,
		Magenta = 35,
		Cyan = 36,
		White = 37,
		BrightBlack = 90,
		BrightRed = 91,
		BrightGreen = 92,
		BrightYellow = 93,
		BrightBlue = 94,
		BrightMagenta = 95,
		BrightCyan = 96,
		BrightWhite = 97

	};

	void PrintRoom() 
	{
		Room* CurrentRoom = Game::CurrentRoom;
		// player

		cout << "You're currently in " << CurrentRoom->Name << ". " << CurrentRoom->DangerStatus << endl;
		cout << CurrentRoom->Description << endl;

		if (CurrentRoom->ConnectedRooms.size() > 1)
			cout << "You notice " + std::to_string(CurrentRoom->ConnectedRooms.size()) + " different paths to take.", std::to_string(numPaths) << endl;
		else
			cout << "You notice a single path you can take." << endl;
	}
}
