#pragma once
#include "Room.h"

namespace Navigation 
{
	struct Map 
	{
	public:
		Room EntranceArea = Room("the entrance area");
		Room Koda = Room("Koda's territory");
		Room Toilet = Room("the toilet");
		Room Stairs = Room("front of the stairs");
		Room LivingRoom = Room("the living room");
		Room DiningTable = Room("front of the dining area", 1, 3);
		Room Hallway = Room("the hallway");
		Room BackEntranceArea = Room("the back entrance area", 7, 9);
		Room Kitchen = Room("the kitchen", 4, 6);
		Room Miklat = Room("the Miklat", 10, 13);
	};

	Map SetupRooms() 
	{
        Map map = Map();

        // Each room's connected rooms:
        map.EntranceArea.ConnectedRooms = { map.Koda, map.LivingRoom, map.DiningTable, map.Hallway };
        map.Koda.ConnectedRooms = { map.Toilet, map.Stairs, map.EntranceArea, map.DiningTable };
        map.Toilet.ConnectedRooms = { map.Koda };
        map.Stairs.ConnectedRooms = { map.Koda };
        map.LivingRoom.ConnectedRooms = { map.EntranceArea, map.DiningTable };
        map.DiningTable.ConnectedRooms = { map.EntranceArea, map.Koda, map.Hallway, map.LivingRoom };
        map.Hallway.ConnectedRooms = { map.BackEntranceArea, map.Kitchen, map.Miklat, map.EntranceArea, map.DiningTable };
        map.BackEntranceArea.ConnectedRooms = { map.Hallway, map.Miklat, map.Kitchen };
        map.Kitchen.ConnectedRooms = { map.Hallway, map.Miklat, map.BackEntranceArea };
        map.Miklat.ConnectedRooms = { map.Hallway, map.BackEntranceArea, map.Kitchen };


        //SceneManager.currentRoom = EntranceArea; // change if you want to start in a different room
        //Koda.isBossRoom = true;
        //Koda.boss = new Boss("Koda", 125, 18, 15);
        //LivingRoom.isSafeZone = true;

        // Each room descriptions:
        map.EntranceArea.Description = "This area is tidy, with the exception of a few shoes scattered by the door.";
        map.EntranceArea.ItemFindDescription = "Your eyes fall on a pair of shoes, and you decide to look inside one of them, finding";
        map.Koda.Description = "A beautiful white Samoyed is staring at you with a look of clear dissatisfaction on its face.";
        map.Koda.CanItemsSpawn = false;
        map.Toilet.Description = "An ordinary white toilet sits facing a small sink, with a shelf positioned above it.";
        map.Toilet.CanItemsSpawn = false;
        map.Stairs.Description = "A long set of light gray marble stairs.";
        map.Stairs.CanItemsSpawn = false;
        map.LivingRoom.Description = "The room features an 'L' shaped black sofa, littered with scratch marks scattered across its surface. A small white coffee table sits at the center, and a large TV faces the sofa. The overall design of the space is modern, standing out in contrast to the more traditional decor of the other rooms on that floor.";
        map.LivingRoom.ItemFindDescription = "You spot two drawers in the coffee table; one of them is slightly open. You manage to slide it fully open and find";
        map.DiningTable.Description = "A long white dining table, flanked by three white chairs on each side, with scratch marks covering the tops of the chairs. In the center of the table, a beautiful decorative bowl with a marble texture adds an elegant touch to the otherwise simple setup.";
        map.DiningTable.ItemFindDescription = "You glance inside the decorative bowl and spot";
        map.Hallway.Description = "A short hallway connects several rooms, lined with a cozy carpet that adds warmth and comfort to the space.";
        map.Hallway.CanItemsSpawn = false;
        map.BackEntranceArea.Description = "A large wooden door with scratches on its lower part stands near two refrigerators, one black and one white.";
        map.BackEntranceArea.ItemFindDescription = "You spot a small gap behind the white refrigerator, and find";
        map.Kitchen.Description = "The kitchen is filled with bright wood cabinets and a variety of appliances. A wide, short window lets in a gentle stream of light, brightening the space.";
        map.Kitchen.ItemFindDescription = "You hop onto the counter and explore the window sill, where you locate";
        map.Miklat.Description = "A small, cramped room filled with shelves and cluttered with various items and junk.";
        map.Miklat.ItemFindDescription = "You scan the shelves and spot";

        return map;
	}
}

