#include "stdafx.h"
#include "../Game/mapFan.h"

void MapFan::generateObject() {
	mapFan[0].LoadBitmap({ "Resources/object/fan.bmp" }, RGB(0, 255, 0));
	mapFan[1].LoadBitmap({ "Resources/object/fan.bmp" }, RGB(0, 255, 0));
	mapFan[0].SetTopLeft(0, 0);
	mapFan[1].SetTopLeft(0, 0);

}

void MapFan::showObject(int map_stage) {
	switch (map_stage) {
	case 4: {
		mapFan[0].SetTopLeft(45, 490);
		mapFan[1].SetTopLeft(1240, 490);
		for (int i = 0; i < 2; i++) {
			mapFan[i].ShowBitmap();
		}
		break;
	}

	}
}