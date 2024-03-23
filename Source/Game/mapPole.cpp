#include "stdafx.h"
#include "../Game/mapPole.h"

void MapPole::generateObject() {
	mapPole[0].LoadBitmap({ "Resources/object/pole_M1_yellow_1.bmp", "Resources/object/pole_M1_yellow_1.bmp" }, RGB(0, 255, 0));
	mapPole[1].LoadBitmap({ "Resources/object/pole_M1_purple_1.bmp", "Resources/object/pole_M1_purple_2.bmp" }, RGB(0, 255, 0));
	mapPole[0].SetTopLeft(35, 525);
	mapPole[1].SetTopLeft(1225, 425);

}

void MapPole::showObject(int map_stage) {
	switch (map_stage) {
	case 1: {
		for (int i = 0; i < 2; i++) {
			mapPole[i].ShowBitmap();
		}
		break;
	}

	}
}