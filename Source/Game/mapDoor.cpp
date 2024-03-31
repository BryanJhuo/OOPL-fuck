#include "stdafx.h"
#include "../Game/mapDoor.h"

void MapDoor::generateObject() {
	mapDoor[0].LoadBitmap({ "Resources/object/door_fire_1.bmp", "Resources/object/door_fire_2.bmp" }, RGB(0, 255, 0));
	mapDoor[1].LoadBitmap({ "Resources/object/door_water_1.bmp", "Resources/object/door_water_2.bmp" }, RGB(0, 255, 0));
	mapDoor[0].SetTopLeft(1120, 110);
	mapDoor[1].SetTopLeft(1230, 110);

}

void MapDoor::showObject(int map_stage) {
	switch (map_stage) {
	case 1: {
		mapDoor[0].SetTopLeft(1120, 110);
		mapDoor[1].SetTopLeft(1230, 110);
		for (int i = 0; i < 2; i++) {
			mapDoor[i].ShowBitmap();
		}
		break;
	}
	case 2: {
		mapDoor[0].SetTopLeft(1195, 427);
		mapDoor[1].SetTopLeft(150, 884);
		for (int i = 0; i < 2; i++) {
			mapDoor[i].ShowBitmap();
		}
		break;
	}
	case 3: {
		mapDoor[0].SetTopLeft(50, 40);
		mapDoor[1].SetTopLeft(150, 40);
		for (int i = 0; i < 2; i++) {
			mapDoor[i].ShowBitmap();
		}
		break;
	}
	case 4: {
		mapDoor[0].SetTopLeft(390, 528);
		mapDoor[1].SetTopLeft(930, 529);
		for (int i = 0; i < 2; i++) {
			mapDoor[i].ShowBitmap();
		}
		break;
	}
	case 5: {
		mapDoor[0].SetTopLeft(50, 40);
		mapDoor[1].SetTopLeft(150, 40);
		for (int i = 0; i < 2; i++) {
			mapDoor[i].ShowBitmap();
		}
		break;
	}

	}
}