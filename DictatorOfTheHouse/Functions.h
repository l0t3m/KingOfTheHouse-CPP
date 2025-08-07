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
	void SetConsoleColor(ConsoleColor color) {
		cout << "\033[" << static_cast<int>(color) << "m";
	}

	// Resets to default color
	void ResetConsoleColor() {
		cout << "\033[0m";
	}

	void PrintAndColor(const string& text, const string& targetText, ConsoleColor color = ConsoleColor::Blue) {
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

	void PrintRoom() 
	{
		Room* CurrentRoom = Game::CurrentRoom;
		// player

		/*PrintAndColor("You're currently in " + CurrentRoom->Name + ". " + Navigation::StatusToString(CurrentRoom->DangerStatus), 
			Navigation::StatusToString(CurrentRoom->DangerStatus),
			CurrentRoom->GetDangerStatusColor());*/

		cout << "You're currently in " << CurrentRoom->Name << ". " << StatusToString(CurrentRoom->DangerStatus) << endl;
		cout << CurrentRoom->Description << endl;

		if (CurrentRoom->ConnectedRooms.size() > 1)
			cout << "You notice " + to_string(CurrentRoom->ConnectedRooms.size()) << " different paths to take.", to_string(CurrentRoom->ConnectedRooms.size());
		else
			cout << "You notice a single path you can take." << endl;
	}
}
