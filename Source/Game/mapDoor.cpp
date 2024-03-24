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
		for (int i = 0; i < 2; i++) {
			mapDoor[i].ShowBitmap();
		}
		break;
	}

	}
}