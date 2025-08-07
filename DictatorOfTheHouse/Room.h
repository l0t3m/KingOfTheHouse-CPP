#pragma once
#include <string>
#include <vector>

using namespace std;

namespace Navigation 
{
	enum class RoomDangerStatus 
	{
		Unknown,
		Safe,
		Neutral,
		Dangerous
	};

	inline string StatusToString(RoomDangerStatus danger)
	{
		switch (danger) {
		case RoomDangerStatus::Unknown:
			return "Unknown";
		case RoomDangerStatus::Safe: 
			return "Safe";
		case RoomDangerStatus::Neutral: 
			return "Neutral";
		case RoomDangerStatus::Dangerous: 
			return "Dangerous";
		default:
			return "Not Set";
		}
	}

	class Room
	{
	public:
		// Attributes:
		string Name;
		string Description;
		vector<Room*> ConnectedRooms;

		RoomDangerStatus DangerStatus = RoomDangerStatus::Neutral;
		bool DiscoveredStatus = false;

		// Enemy Related:
		int MinLevel = 0;
		int MaxLevel = 0;
		bool IsBossRoom = false;
		//Boss

		// Item Related:
		string ItemFindDescription;
		bool CanItemsSpawn = true;
		//ItemsVector


		// Constructors:
		Room() : Name("Unset Room") { }
		Room(string name) : Name(name) { }
		// Enemy Room
		Room(string name, int minLevel, int maxLevel) 
			: Name(name), MinLevel(minLevel), MaxLevel(maxLevel), DangerStatus(RoomDangerStatus::Dangerous) { }
		// Boss Room
		Room(string name, int minLevel)
			: Name(name), MinLevel(minLevel), DangerStatus(RoomDangerStatus::Dangerous), IsBossRoom(true), DiscoveredStatus(true) {
		}
	};
}