#include "stdafx.h"
#include "../Game/mapDiamond.h"

void MapDiamond::generateObject() {
	for (int i = 0; i < 11; i++) {
		redDiamond[i].LoadBitmap({ "Resources/object/diamond_red.bmp", "Resources/object/diamond_0.bmp" }, RGB(0, 255, 0));
		blueDiamond[i].LoadBitmap({ "Resources/object/diamond_blue.bmp", "Resources/object/diamond_0.bmp" }, RGB(0, 255, 0));
		redDiamond[i].SetTopLeft(0, 0);
		blueDiamond[i].SetTopLeft(0, 0);
	}
	whiteDiamond.LoadBitmapByString({ "Resources/object/diamond_white.bmp", "Resources/object/diamond_white0.bmp" }, RGB(0, 255, 0));
	whiteDiamond.SetTopLeft(0, 0);
}

void MapDiamond::showObject(int map_stage) {
	switch (map_stage) {
	case 1: {
		redDiamond[0].SetTopLeft(665, 890);
		redDiamond[1].SetTopLeft(215, 440);
		redDiamond[2].SetTopLeft(335, 55);
		blueDiamond[0].SetTopLeft(940, 890);
		blueDiamond[1].SetTopLeft(770, 445);
		blueDiamond[2].SetTopLeft(55, 165);
		blueDiamond[3].SetTopLeft(680, 115);

		for (int i = 0; i < 3; i++) {
			redDiamond[i].ShowBitmap();;
		}
		for (int i = 0; i < 4; i++) {
			blueDiamond[i].ShowBitmap();
		}
		break;
	}

	case 2: {
		redDiamond[0].SetTopLeft(870, 150);
		redDiamond[1].SetTopLeft(700, 150);
		redDiamond[2].SetTopLeft(530, 150);
		redDiamond[3].SetTopLeft(330, 85);
		redDiamond[4].SetTopLeft(190, 170);
		redDiamond[5].SetTopLeft(115, 325);
		redDiamond[6].SetTopLeft(570, 325);
		redDiamond[7].SetTopLeft(910, 325);

		blueDiamond[0].SetTopLeft(470, 550);
		blueDiamond[1].SetTopLeft(665, 550);
		blueDiamond[2].SetTopLeft(860, 550);
		blueDiamond[3].SetTopLeft(990, 485);
		blueDiamond[4].SetTopLeft(1165, 585);
		blueDiamond[5].SetTopLeft(1200, 755);
		blueDiamond[6].SetTopLeft(750, 720);
		blueDiamond[7].SetTopLeft(470, 720);;

		for (int i = 0; i < 8; i++) {
			redDiamond[i].ShowBitmap();
			blueDiamond[i].ShowBitmap();
		}
		break;
	}

	case 3: {
		redDiamond[0].SetTopLeft(350, 60);
		redDiamond[1].SetTopLeft(290, 195);
		redDiamond[2].SetTopLeft(245, 335);
		redDiamond[3].SetTopLeft(310, 475);
		redDiamond[4].SetTopLeft(1090, 55);
		redDiamond[5].SetTopLeft(1070, 475);
		redDiamond[6].SetTopLeft(850, 620);
		redDiamond[7].SetTopLeft(905, 895);


		blueDiamond[0].SetTopLeft(460, 60);
		blueDiamond[1].SetTopLeft(190, 755);
		blueDiamond[2].SetTopLeft(190, 895);
		blueDiamond[3].SetTopLeft(1195, 55);
		blueDiamond[4].SetTopLeft(915, 195);
		blueDiamond[5].SetTopLeft(870, 335);
		blueDiamond[6].SetTopLeft(870, 475);
		blueDiamond[7].SetTopLeft(960, 620);;

		for (int i = 0; i < 8; i++) {
			redDiamond[i].ShowBitmap();
			blueDiamond[i].ShowBitmap();
		}
		break;
	}

	case 4: {
		redDiamond[0].SetTopLeft(270, 890);
		redDiamond[1].SetTopLeft(390, 890);
		redDiamond[2].SetTopLeft(465, 850);
		redDiamond[3].SetTopLeft(1040, 715);
		redDiamond[4].SetTopLeft(1140, 715);
		redDiamond[5].SetTopLeft(1260, 380);
		redDiamond[6].SetTopLeft(1260, 260);
		redDiamond[7].SetTopLeft(1260, 150);
		redDiamond[8].SetTopLeft(800, 55);
		redDiamond[9].SetTopLeft(770, 265);
		redDiamond[10].SetTopLeft(375, 360);


		blueDiamond[0].SetTopLeft(1080, 890);
		blueDiamond[1].SetTopLeft(970, 890);
		blueDiamond[2].SetTopLeft(890, 850);
		blueDiamond[3].SetTopLeft(300, 715);
		blueDiamond[4].SetTopLeft(195, 715);
		blueDiamond[5].SetTopLeft(80, 380);
		blueDiamond[6].SetTopLeft(80, 260);
		blueDiamond[7].SetTopLeft(80, 150);
		blueDiamond[8].SetTopLeft(480, 55);
		blueDiamond[9].SetTopLeft(548, 265);
		blueDiamond[10].SetTopLeft(978, 360);

		for (int i = 0; i < 11; i++) {
			redDiamond[i].ShowBitmap();
			blueDiamond[i].ShowBitmap();
		}
		break;
	}

	case 5: {
		whiteDiamond.SetTopLeft(50, 190);
		whiteDiamond.ShowBitmap();
	}

	}
}