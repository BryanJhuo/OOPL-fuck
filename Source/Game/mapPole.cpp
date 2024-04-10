#include "stdafx.h"
#include "../Game/mapPole.h"

void MapPole::generateObject() {
	mapPole[0].LoadBitmap({ "Resources/object/pole4_yellow_1.bmp", "Resources/object/pole4_yellow_2.bmp" }, RGB(0, 255, 0));
	mapPole[1].LoadBitmap({ "Resources/object/pole4_red_1.bmp", "Resources/object/pole4_red_2.bmp" }, RGB(0, 255, 0));	
	mapPole[2].LoadBitmap({ "Resources/object/pole4_purple_1.bmp", "Resources/object/pole4_purple_2.bmp" }, RGB(0, 255, 0));
	mapPole[3].LoadBitmap({ "Resources/object/pole4_white_1.bmp", "Resources/object/pole4_white_2.bmp" }, RGB(0, 255, 0));

	mapPole[4].LoadBitmap({ "Resources/object/pole3_blue_1.bmp", "Resources/object/pole3_blue_2.bmp" }, RGB(0, 255, 0));
	mapPole[5].LoadBitmap({ "Resources/object/pole3_green_1.bmp", "Resources/object/pole3_green_2.bmp" });
	mapPole[6].LoadBitmap({ "Resources/object/pole3_green2_1.bmp", "Resources/object/pole3_green2_2.bmp" });
	mapPole[7].LoadBitmap({ "Resources/object/pole3_purple2_1.bmp", "Resources/object/pole3_purple2_2.bmp" }, RGB(0, 255, 0));
	mapPole[8].LoadBitmap({ "Resources/object/pole3_red_1.bmp", "Resources/object/pole3_red_2.bmp" }, RGB(0, 255, 0));
	mapPole[9].LoadBitmap({ "Resources/object/pole3_white_1.bmp", "Resources/object/pole3_white_2.bmp" }, RGB(0, 255, 0));
	mapPole[10].LoadBitmap({ "Resources/object/pole3_yellow_1.bmp", "Resources/object/pole3_yellow_2.bmp" }, RGB(0, 255, 0));
	mapPole[11].LoadBitmap({ "Resources/object/pole3_purple2_1.bmp", "Resources/object/pole3_purple2_2.bmp" }, RGB(0, 255, 0));
	mapPole[12].LoadBitmap({ "Resources/object/pole3_white_1.bmp", "Resources/object/pole3_white_2.bmp" }, RGB(0, 255, 0));
	mapPole[13].LoadBitmap({ "Resources/object/pole3_purple_1.bmp", "Resources/object/pole3_purple_2.bmp" }, RGB(0, 255, 0));
	mapPole[14].LoadBitmap({ "Resources/object/pole3_white_1.bmp", "Resources/object/pole3_white_2.bmp" }, RGB(0, 255, 0));
	mapPole[15].LoadBitmap({ "Resources/object/pole3_white_1.bmp", "Resources/object/pole3_white_2.bmp" }, RGB(0, 255, 0));
	mapPole[16].LoadBitmap({ "Resources/object/pole3_green_1.bmp", "Resources/object/pole3_green_2.bmp" });

	for (int i = 0; i < 17; i++) {
		mapPole[i].SetTopLeft(0, 0);
	}
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

	case 3: {
		mapPole[1].SetTopLeft(107, 560);
		mapPole[8].SetTopLeft(560, 420);
		mapPole[4].SetTopLeft(670, 455);
		mapPole[6].SetTopLeft(670, 595);
		mapPole[7].SetTopLeft(530, 877);
		mapPole[11].SetTopLeft(665, 877);
		mapPole[10].SetTopLeft(700, 140);
		mapPole[2].SetTopLeft(1157, 280);
		mapPole[3].SetTopLeft(1155, 700);

		mapPole[1].ShowBitmap();
		mapPole[8].ShowBitmap();
		mapPole[4].ShowBitmap();
		mapPole[6].ShowBitmap();
		mapPole[7].ShowBitmap();
		mapPole[11].ShowBitmap();
		mapPole[10].ShowBitmap();
		mapPole[2].ShowBitmap();
		mapPole[3].ShowBitmap();

		break;
	}

	case 5: {
		mapPole[4].SetTopLeft(590, 35);
		mapPole[5].SetTopLeft(145, 270);
		mapPole[9].SetTopLeft(420, 420);
		mapPole[12].SetTopLeft(455, 560);
		mapPole[6].SetTopLeft(560, 595);
		mapPole[13].SetTopLeft(175, 840);
		mapPole[8].SetTopLeft(1260, 280);
		mapPole[14].SetTopLeft(950, 420);
		mapPole[7].SetTopLeft(1050, 455);
		mapPole[15].SetTopLeft(805, 700);
		mapPole[16].SetTopLeft(1120, 700);

		mapPole[4].ShowBitmap();
		mapPole[5].ShowBitmap();
		mapPole[9].ShowBitmap();
		mapPole[12].ShowBitmap();
		mapPole[6].ShowBitmap();
		mapPole[13].ShowBitmap();
		mapPole[8].ShowBitmap();
		mapPole[14].ShowBitmap();
		mapPole[7].ShowBitmap();
		mapPole[15].ShowBitmap();
		mapPole[16].ShowBitmap();

		break;
	}

	}
}