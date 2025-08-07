#pragma once
#include <vector>
#include <string>

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
		int MinLevel;
		int MaxLevel;

		// Item Related:
		string ItemFindDescription;
		bool CanItemsSpawn = true;


		// Constructors:
		Room() : Name("Unset Room") { }
		Room(string name) : Name(name) { }
		Room(string name, int minLevel, int maxLevel) : Name(name), MinLevel(minLevel), MaxLevel(maxLevel) { }
	};
}