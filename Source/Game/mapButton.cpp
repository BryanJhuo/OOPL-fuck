#include "stdafx.h"
#include "../Game/mapButton.h"



void MapButton::generateObject() {
	for (int i = 0; i < 2; i++) {
		mapButton[i].LoadBitmap({ "Resources/object/button_purple_1.bmp", "Resources/object/button_purple_3.bmp" }, RGB(0,255,0));
	}
	mapButton[2].LoadBitmap({ "Resources/object/button_blue_1.bmp", "Resources/object/button_blue_3.bmp" }, RGB(0, 255, 0));
	mapButton[3].LoadBitmap({ "Resources/object/button_red_1.bmp", "Resources/object/button_red_3.bmp" }, RGB(0, 255, 0));
	
	for (int i = 0; i < 4; i++) {
		mapButton[i].SetTopLeft(0, 0);
	}
}

void MapButton::showObject(int map_stage) {
	switch (map_stage) {
		case 1: {
			mapButton[0].SetTopLeft(350, 490);
			mapButton[1].SetTopLeft(1090, 350);

			for (int i = 0; i < 2; i++) {
				mapButton[i].ShowBitmap();
			}
			break;
		}

		case 3: {
			mapButton[2].SetTopLeft(70, 665);
			mapButton[0].SetTopLeft(915, 103);
			mapButton[3].SetTopLeft(560, 665);

			mapButton[2].ShowBitmap();
			mapButton[0].ShowBitmap();
			mapButton[3].ShowBitmap();
			break;
		}

	}
}

/*
void MapButton::overlapReturn(game_framework::CMovingBitmap character) {
	if (game_framework::CMovingBitmap::IsOverlap(mapButton[0], character)) {
		mapButton[0].SetFrameIndexOfBitmap[1];
	}
	else {
		//mapButton[0].SetFrameIndexOfBitmap[0];
	}
}
*/