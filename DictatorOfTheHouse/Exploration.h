#pragma once
#include <iostream>
#include <map>
#include "SceneManager.h"

namespace Navigation 
{
	class Exploration 
	{
    public:
        static void Explore();
        static void DoRespawn();

    private:
        static void Move();
        static void Examine();
        static void LookForEnemies();
        static void DoRest();
        static void Stats();
	};
}

