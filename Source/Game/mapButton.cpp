#include "stdafx.h"
#include "../Game/mapButton.h"



void MapButton::generateObject() {
	for (int i = 0; i < 2; i++) {
		mapButton[i].LoadBitmap({ "Resources/object/button_purple_1.bmp", "Resources/object/button_purple_3.bmp" }, RGB(0,255,0));
	}
	mapButton[0].SetTopLeft(350, 490);
	mapButton[1].SetTopLeft(1090, 350);

}

void MapButton::showObject(int map_stage) {
	switch (map_stage) {
		case 1: {
			for (int i = 0; i < 2; i++) {
				mapButton[i].ShowBitmap();
			}
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