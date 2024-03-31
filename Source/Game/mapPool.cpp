#include "stdafx.h"
#include "../Game/mapPool.h"

void MapPool::generateObject() {
	redPool[0].LoadBitmap({ "Resources/object/pool_fire4_1.bmp" }, RGB(0, 255, 0));
	redPool[1].LoadBitmap({ "Resources/object/pool_fire3_1.bmp" }, RGB(0, 255, 0));
	redPool[2].LoadBitmap({ "Resources/object/pool_fire3_1.bmp" }, RGB(0, 255, 0));
	redPool[3].LoadBitmap({ "Resources/object/pool_fire3_1.bmp" }, RGB(0, 255, 0));
	redPool[4].LoadBitmap({ "Resources/object/pool_fire3_1.bmp" }, RGB(0, 255, 0));
	redPool[5].LoadBitmap({ "Resources/object/pool_fire2_1.bmp" }, RGB(0, 255, 0));
	redPool[6].LoadBitmap({ "Resources/object/pool_fire6_1.bmp" }, RGB(0, 255, 0));
	redPool[7].LoadBitmap({ "Resources/object/pool_fire6_1.bmp" }, RGB(0, 255, 0));

	bluePool[0].LoadBitmap({ "Resources/object/pool_water4_1.bmp" }, RGB(0, 255, 0));
	bluePool[1].LoadBitmap({ "Resources/object/pool_water3_1.bmp" }, RGB(0, 255, 0));
	bluePool[2].LoadBitmap({ "Resources/object/pool_water3_1.bmp" }, RGB(0, 255, 0));
	bluePool[3].LoadBitmap({ "Resources/object/pool_water3_1.bmp" }, RGB(0, 255, 0));
	bluePool[4].LoadBitmap({ "Resources/object/pool_water3_1.bmp" }, RGB(0, 255, 0));
	bluePool[5].LoadBitmap({ "Resources/object/pool_water2_1.bmp" }, RGB(0, 255, 0));
	bluePool[6].LoadBitmap({ "Resources/object/pool_water6_1.bmp" }, RGB(0, 255, 0));
	bluePool[7].LoadBitmap({ "Resources/object/pool_water6_1.bmp" }, RGB(0, 255, 0));

	for (int i = 0; i < 8; i++) {
		redPool[i].SetTopLeft(0, 0);
		bluePool[i].SetTopLeft(0, 0);
	}
	greenPool.LoadBitmap({ "Resources/object/pool_green4_1.bmp" }, RGB(255, 0, 0));
	greenPool.SetTopLeft(0, 0);


}

void MapPool::showObject(int map_stage) {
	switch (map_stage) {
	case 1: {
		redPool[0].SetTopLeft(620, 975);
		bluePool[0].SetTopLeft(900, 975);
		greenPool.SetTopLeft(870, 765);
		for (int i = 0; i < 1; i++) {
			redPool[i].ShowBitmap();
			bluePool[i].ShowBitmap();
		}
		greenPool.ShowBitmap();
		break;
	}
		  
	case 2: {
		redPool[1].SetTopLeft(750, 840-3);
		redPool[2].SetTopLeft(750, 630-3);
		redPool[3].SetTopLeft(550, 630-3);
		redPool[4].SetTopLeft(350, 630-3);
		bluePool[1].SetTopLeft(945, 245-3);
		bluePool[2].SetTopLeft(745, 245-3);
		bluePool[3].SetTopLeft(545, 245-3);
		bluePool[4].SetTopLeft(570, 4203-3);

		for (int i = 1; i < 5; i++) {
			redPool[i].ShowBitmap();
			bluePool[i].ShowBitmap();
		}
		break;
	}
	case 4: {
		redPool[5].SetTopLeft(360, 455 - 3);
		redPool[6].SetTopLeft(1020, 802 - 3);
		redPool[7].SetTopLeft(280, 980 - 3);
		bluePool[5].SetTopLeft(965, 455 - 3);
		bluePool[6].SetTopLeft(180, 802 - 3);
		bluePool[7].SetTopLeft(915, 980 - 3);

		for (int i = 5; i < 8; i++) {
			redPool[i].ShowBitmap();
			bluePool[i].ShowBitmap();
		}
		break;
	}

	

	}
}