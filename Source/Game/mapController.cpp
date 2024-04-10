#include "stdafx.h"
#include "../Game/mapController.h"

void MapController::generateObject() {
	mapController[0].LoadBitmap({ "Resources/object/controller_yellow_1.bmp", "Resources/object/controller_yellow_2.bmp" }, RGB(0, 255, 0));
	mapController[1].LoadBitmap({ "Resources/object/controller_white_1.bmp", "Resources/object/controller_white_2.bmp" }, RGB(0, 255, 0));
	mapController[2].LoadBitmap({ "Resources/object/controller_green_1.bmp", "Resources/object/controller_green_2.bmp" }, RGB(255, 0, 0));
	mapController[3].LoadBitmap({ "Resources/object/controller_purple_1.bmp", "Resources/object/controller_purple_2.bmp" }, RGB(0, 255, 0));
	mapController[4].LoadBitmap({ "Resources/object/controller_red_1.bmp", "Resources/object/controller_red_2.bmp" }, RGB(0, 255, 0));
	mapController[5].LoadBitmap({ "Resources/object/controller_blue_1.bmp", "Resources/object/controller_blue_2.bmp" }, RGB(0, 255, 0));
	
	
	for (int i = 0; i < 6; i++) {
		mapController[i].SetTopLeft(0, 0);
		controllerState[i] = false;
	}
}

void MapController::showObject(int map_stage) {
	switch (map_stage) {
	case 1: {
		mapController[0].SetTopLeft(280, 650);
		mapController[0].ShowBitmap();
		break;
	}

	case 3: {
		mapController[0].SetTopLeft(380, 350);
		mapController[1].SetTopLeft(70, 775);
		mapController[2].SetTopLeft(70, 910);
		mapController[3].SetTopLeft(1230, 910);
		
		for (int i = 0; i < 4; i++) {
			mapController[i].ShowBitmap();
		}
		
		break;
	}

	case 5: {
		mapController[5].SetTopLeft(315, 210);
		mapController[3].SetTopLeft(700, 133);
		mapController[2].SetTopLeft(835, 98);
		mapController[1].SetTopLeft(995, 133);
		mapController[4].SetTopLeft(1260, 640);

		for (int i = 1; i < 6; i++) {
			mapController[i].ShowBitmap();
		}

		break;
	}

	}
}