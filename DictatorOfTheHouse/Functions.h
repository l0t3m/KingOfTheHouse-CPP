#pragma once
#include <string>
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

	// Sets the text color
	void SetConsoleColor(ConsoleColor color) 
	{
		cout << "\033[" << static_cast<int>(color) << "m";
	}

	// Resets to default color
	void ResetConsoleColor() 
	{
		cout << "\033[0m";
	}

	void PrintAndColor(const string& text, const string& targetText, ConsoleColor color = ConsoleColor::BrightBlue) {
		if (targetText.empty()) {
			SetConsoleColor(color);
			cout << text << endl;
			ResetConsoleColor();
			return;
		}

		size_t index = text.find(targetText);
		if (index == string::npos) {
			cout << text << endl;
			return;
		}

		cout << text.substr(0, index);
		SetConsoleColor(color);
		cout << text.substr(index, targetText.length());
		ResetConsoleColor();
		cout << text.substr(index + targetText.length()) << endl;
	}

	// Checks if the status has been discovered and returns the required console color according to the danger status.
	Utils::ConsoleColor GetDangerStatusColor(Room* room) 
	{
		if (!room->DiscoveredStatus)
			return Utils::ConsoleColor::BrightBlack;

		switch (room->DangerStatus) {
		case RoomDangerStatus::Unknown: 
			return Utils::ConsoleColor::BrightWhite; 
			break;
		case RoomDangerStatus::Safe: 
			return Utils::ConsoleColor::BrightGreen; 
			break;
		case RoomDangerStatus::Neutral: 
			return Utils::ConsoleColor::BrightCyan; 
			break;
		case RoomDangerStatus::Dangerous: 
			if (room->IsBossRoom)
				return Utils::ConsoleColor::Red;
			return Utils::ConsoleColor::Yellow; 
			break;
		default:
			return Utils::ConsoleColor::White; 
			break;
		}
	}

	Utils::ConsoleColor GetDangerStatusColor()
	{
		if (!Game::CurrentRoom->DiscoveredStatus)
			return Utils::ConsoleColor::BrightBlack;

		switch (Game::CurrentRoom->DangerStatus) {
		case RoomDangerStatus::Unknown:
			return Utils::ConsoleColor::BrightWhite;
			break;
		case RoomDangerStatus::Safe:
			return Utils::ConsoleColor::BrightGreen;
			break;
		case RoomDangerStatus::Neutral:
			return Utils::ConsoleColor::BrightCyan;
			break;
		case RoomDangerStatus::Dangerous:
			if (Game::CurrentRoom->IsBossRoom)
				return Utils::ConsoleColor::Red;
			return Utils::ConsoleColor::Yellow;
			break;
		default:
			return Utils::ConsoleColor::White;
			break;
		}
	}

	// Checks if the current room's danger status has been discovered and returns the correct string.
	string GetDangerStatusDiscovered(Room* room) {
		if (room->DiscoveredStatus)
			return Navigation::StatusToString(room->DangerStatus);
		else
			return Navigation::StatusToString(RoomDangerStatus::Unknown);
	}

	void PrintRoom() 
	{
		Room* CurrentRoom = Game::CurrentRoom;
		// player

		PrintAndColor("You're currently in " + CurrentRoom->Name + ". [" + GetDangerStatusDiscovered(CurrentRoom) + "]",
			GetDangerStatusDiscovered(CurrentRoom),
			GetDangerStatusColor(CurrentRoom));

		cout << CurrentRoom->Description << endl;

		if (CurrentRoom->ConnectedRooms.size() > 1)
			Utils::PrintAndColor("You notice " + to_string(CurrentRoom->ConnectedRooms.size()) + " different paths to take.",
				to_string(CurrentRoom->ConnectedRooms.size()));
		else
			Utils::PrintAndColor("You notice a single path you can take.", "single");
	}
}
