#include "Map.h"

namespace Navigation {
    Room EntranceArea("the entrance area");
    Room Koda("Koda's territory");
    Room Toilet("the toilet");
    Room Stairs("front of the stairs");
    Room LivingRoom("the living room");
    Room DiningTable("front of the dining area", 1, 3);
    Room Hallway("the hallway");
    Room BackEntranceArea("the back entrance area", 7, 9);
    Room Kitchen("the kitchen", 4, 6);
    Room Miklat("the Miklat", 10, 13);

    void SetupRooms() {
        // Connections
        EntranceArea.ConnectedRooms = { &Koda, &LivingRoom, &DiningTable, &Hallway };
        Koda.ConnectedRooms = { &Toilet, &Stairs, &EntranceArea, &DiningTable };
        Toilet.ConnectedRooms = { &Koda };
        Stairs.ConnectedRooms = { &Koda };
        LivingRoom.ConnectedRooms = { &EntranceArea, &DiningTable };
        DiningTable.ConnectedRooms = { &EntranceArea, &Koda, &Hallway, &LivingRoom };
        Hallway.ConnectedRooms = { &BackEntranceArea, &Kitchen, &Miklat, &EntranceArea, &DiningTable };
        BackEntranceArea.ConnectedRooms = { &Hallway, &Miklat, &Kitchen };
        Kitchen.ConnectedRooms = { &Hallway, &Miklat, &BackEntranceArea };
        Miklat.ConnectedRooms = { &Hallway, &BackEntranceArea, &Kitchen };

        // Room properties
        /*
        Koda.isBossRoom = true;
        Koda.boss = new Boss("Koda", 125, 18, 15);
        */
        LivingRoom.DangerStatus = RoomDangerStatus::Safe;
        

        // Descriptions
        EntranceArea.Description = "This area is tidy, with the exception of a few shoes scattered by the door.";
        EntranceArea.ItemFindDescription = "Your eyes fall on a pair of shoes, and you decide to look inside one of them, finding";

        Koda.Description = "A beautiful white Samoyed is staring at you with a look of clear dissatisfaction on its face.";
        Koda.CanItemsSpawn = false;

        Toilet.Description = "An ordinary white toilet sits facing a small sink, with a shelf positioned above it.";
        Toilet.CanItemsSpawn = false;

        Stairs.Description = "A long set of light gray marble stairs.";
        Stairs.CanItemsSpawn = false;

        LivingRoom.Description = "The room features an 'L' shaped black sofa, littered with scratch marks scattered across its surface...";
        LivingRoom.ItemFindDescription = "You spot two drawers in the coffee table; one of them is slightly open. You manage to slide it fully open and find";

        DiningTable.Description = "A long white dining table, flanked by three white chairs on each side...";
        DiningTable.ItemFindDescription = "You glance inside the decorative bowl and spot";

        Hallway.Description = "A short hallway connects several rooms, lined with a cozy carpet that adds warmth and comfort to the space.";
        Hallway.CanItemsSpawn = false;

        BackEntranceArea.Description = "A large wooden door with scratches on its lower part stands near two refrigerators...";
        BackEntranceArea.ItemFindDescription = "You spot a small gap behind the white refrigerator, and find";

        Kitchen.Description = "The kitchen is filled with bright wood cabinets and a variety of appliances...";
        Kitchen.ItemFindDescription = "You hop onto the counter and explore the window sill, where you locate";

        Miklat.Description = "A small, cramped room filled with shelves and cluttered with various items and junk.";
        Miklat.ItemFindDescription = "You scan the shelves and spot";
    }

    
    void SetupItems() {
        /*
        EntranceArea.AddRoomItem(Item("blue ball", ItemEffect::Distract));
        DiningTable.AddRoomItem(Item("eye drops", ItemEffect::InstantDamage));
        LivingRoom.AddRoomItem(Item("salmon treats", ItemEffect::InstantHeal));
        Miklat.AddRoomItem(Item("dog food", ItemEffect::InstantHeal));
        */
    }
}