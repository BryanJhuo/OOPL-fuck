#include "stdafx.h"
#include "../Game/mapPool.h"

void MapPool::generateObject() {
	mapPool[0].LoadBitmap({ "Resources/object/pool_fire4_1.bmp"}, RGB(0, 255, 0));
	mapPool[1].LoadBitmap({ "Resources/object/pool_water4_1.bmp"}, RGB(0, 255, 0));
	mapPool[2].LoadBitmap({ "Resources/object/pool_green4_1.bmp"}, RGB(255, 0, 0));
	mapPool[0].SetTopLeft(620, 975);
	mapPool[1].SetTopLeft(900, 975);
	mapPool[2].SetTopLeft(870, 765);

}

void MapPool::showObject(int map_stage) {
	switch (map_stage) {
	case 1: {
		for (int i = 0; i < 3; i++) {
			mapPool[i].ShowBitmap();
		}
		break;
	}

	}
}