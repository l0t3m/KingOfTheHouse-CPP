#include <iostream>
#include <cctype>
#include <string>
#include "Exploration.h"
#include "Map.h"

using namespace std;

int main()
{
    Navigation::SetupRooms();

    while (true) 
    {
        Exploration::Explore();
    }
}
