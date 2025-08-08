#pragma once
#include <string>
#include <iostream>
#include "Room.h"

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
	void SetConsoleColor(ConsoleColor color);

	// Resets to default color
	void ResetConsoleColor();

	void PrintAndColor(const string& text, const string& targetText, ConsoleColor color = ConsoleColor::BrightBlue);
	void PrintAndColor(const string& text, ConsoleColor color = ConsoleColor::BrightBlue);

	// Checks if the status has been discovered and returns the required console color according to the danger status.
	Utils::ConsoleColor GetDangerStatusColor(Navigation::Room* room);

	// Checks if the current room's danger status has been discovered and returns the correct string.
	string GetDangerStatusDiscovered(Navigation::Room* room);

	void PrintRoom(Navigation::Room* CurrentRoom);
}
