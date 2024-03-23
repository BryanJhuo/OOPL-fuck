#include "stdafx.h"
#include "../Game/mapController.h"

void MapController::generateObject() {
	mapController[0].LoadBitmap({ "Resources/object/controller_yellow_1.bmp", "Resources/object/controller_yellow_2.bmp" }, RGB(0, 255, 0));
	mapController[0].SetTopLeft(280, 650);
	

}

void MapController::showObject(int map_stage) {
	switch (map_stage) {
	case 1: {
		mapController[0].ShowBitmap();
		break;
	}

	}
}