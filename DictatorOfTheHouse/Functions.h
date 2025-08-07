#pragma once
#include "Exploration.h"
#include "Map.h"

using namespace std;

namespace Utils 
{
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
