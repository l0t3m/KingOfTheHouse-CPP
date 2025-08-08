#include "SceneManager.h"

namespace Game {
	Room* CurrentRoom = &Navigation::EntranceArea;
	int DaysCounter = 0;
	Entity::Enemy* CurrentEnemy = nullptr;
}
