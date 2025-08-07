#pragma once
#include <string>
#include <vector>
#include "Functions.h"

using namespace std;

namespace Navigation 
{
	enum class RoomDangerStatus 
	{
		Safe,
		Neutral,
		Dangerous
	};

	inline string StatusToString(RoomDangerStatus danger)
	{
		switch (danger) {
		case RoomDangerStatus::Safe: 
			return "Safe";
		case RoomDangerStatus::Neutral: 
			return "Neutral";
		case RoomDangerStatus::Dangerous: 
			return "Dangerous";
		default:
			return "Unknown";
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
		//IsBossRoom
		//Boss

		// Item Related:
		string ItemFindDescription;
		bool CanItemsSpawn = true;
		//ItemsVector


		// Constructors:
		Room() : Name("Unset Room") { }
		Room(string name) : Name(name) { }
		Room(string name, int minLevel, int maxLevel) : Name(name), MinLevel(minLevel), MaxLevel(maxLevel), DangerStatus(RoomDangerStatus::Dangerous) { }
	
		// Methods:
		Utils::ConsoleColor GetDangerStatusColor() {
			switch (DangerStatus) {
			case RoomDangerStatus::Safe: return Utils::ConsoleColor::Green; break;
			case RoomDangerStatus::Neutral: return Utils::ConsoleColor::Yellow; break;
			case RoomDangerStatus::Dangerous: return Utils::ConsoleColor::Red; break;
			default:
				return Utils::ConsoleColor::White; break;
			}
		}
	};
}