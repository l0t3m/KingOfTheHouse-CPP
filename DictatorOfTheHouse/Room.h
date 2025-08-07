#pragma once
#include <string>
#include <vector>

using namespace std;

namespace Navigation 
{
	class Room
	{
	public:
		// Attributes:
		string Name;
		string Description;
		vector<Room*> ConnectedRooms;

		// Enemy Related:
		int MinLevel = 0;
		int MaxLevel = 0;

		// Item Related:
		string ItemFindDescription;
		bool CanItemsSpawn = true;


		// Constructors:
		Room() : Name("Unset Room") { }
		Room(string name) : Name(name) { }
		Room(string name, int minLevel, int maxLevel) : Name(name), MinLevel(minLevel), MaxLevel(maxLevel) { }
	};
}