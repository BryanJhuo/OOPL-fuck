#include "stdafx.h"
#include "../Game/mapDiamond.h"

void MapDiamond::generateObject() {
	for (int i = 0; i < 3; i++) {
		mapDiamond[i].LoadBitmap({ "Resources/object/diamond_red.bmp", "Resources/object/diamond_0.bmp" }, RGB(0, 255, 0));
	}
	for (int i = 3; i < 7; i++) {
		mapDiamond[i].LoadBitmap({ "Resources/object/diamond_blue.bmp", "Resources/object/diamond_0.bmp" }, RGB(0, 255, 0));
	}
	mapDiamond[0].SetTopLeft(665, 890);
	mapDiamond[1].SetTopLeft(215, 440);
	mapDiamond[2].SetTopLeft(335, 55);
	mapDiamond[3].SetTopLeft(940, 890);
	mapDiamond[4].SetTopLeft(770, 445);
	mapDiamond[5].SetTopLeft(55, 165);
	mapDiamond[6].SetTopLeft(680, 115);

}

void MapDiamond::showObject(int map_stage) {
	switch (map_stage) {
	case 1: {
		for (int i = 0; i < 7; i++) {
			mapDiamond[i].ShowBitmap();
		}
		break;
	}

	}
}