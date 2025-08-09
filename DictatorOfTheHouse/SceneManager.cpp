#include "SceneManager.h"

namespace Game 
{
	Room* CurrentRoom = &Navigation::EntranceArea;
	int DaysCounter = 0;
	Entity::Player* Player = Entity::CreatePlayer();
	Entity::Boss* Boss = new Entity::Boss("Koda", 125, 18, 15);
	bool IsGameOver = false;
}
