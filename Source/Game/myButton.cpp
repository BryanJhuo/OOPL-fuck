#include "stdafx.h"
#include "../Game/myButton.h"

void Button::loadButton() {
	/*
	home: (0)play  (1)setting
	menu: (2,3,4,5,6)stage1, 2, 3, 4 (7)back
	map: (8)paused
	window-
	settig: (9)muic (10)effect (11)back
	paused: (12)end (13)resume (14)retry
	die: (15)menu (16)retry (17)skip
	pass: (18)continue
	*/
	
	button[0].LoadBitmapByString({ "Resources/home_page/button_play.bmp" });
	button[0].SetTopLeft(553, 530);		//playButton at Home
	button[1].LoadBitmapByString({ "Resources/home_page/button_setting.bmp" });
	button[1].SetTopLeft(100, 890);		//settingButton at Home  100, 890
	button[2].LoadBitmapByString({ "Resources/menu/stage_gray.bmp", "Resources/menu/stage_green.bmp", "Resources/menu/stage_orange.bmp", "Resources/menu/stage_purple.bmp" });
	button[2].SetTopLeft(600, 830);		//stage1
	button[3].LoadBitmapByString({ "Resources/menu/stage_gray.bmp", "Resources/menu/stage_green.bmp", "Resources/menu/stage_orange.bmp", "Resources/menu/stage_purple.bmp" });
	button[3].SetTopLeft(600, 630);		//stage2
	button[4].LoadBitmapByString({ "Resources/menu/stage_gray.bmp", "Resources/menu/stage_green.bmp", "Resources/menu/stage_orange.bmp", "Resources/menu/stage_purple.bmp" });
	button[4].SetTopLeft(600, 430);		//stage3
	button[5].LoadBitmapByString({ "Resources/menu/stage_gray.bmp", "Resources/menu/stage_green.bmp", "Resources/menu/stage_orange.bmp", "Resources/menu/stage_purple.bmp" });
	button[5].SetTopLeft(600, 230);		//stage4
	button[6].LoadBitmapByString({ "Resources/menu/stage_gray.bmp", "Resources/menu/stage_green.bmp", "Resources/menu/stage_orange.bmp", "Resources/menu/stage_purple.bmp" });
	button[6].SetTopLeft(600, 30);		//stage5
	button[7].LoadBitmapByString({ "Resources/menu/button_back.bmp" });
	button[7].SetTopLeft(30, 830);		//backButton at menu
	button[8].LoadBitmapByString({ "Resources/map/button_paused.bmp" }, RGB(0, 255, 0));
	button[8].SetTopLeft(1320, 10);		//pausedButton at map
	button[9].LoadBitmapByString({ "Resources/window/setting/button_music_1.bmp", "Resources/window/setting/button_music_2.bmp" });
	button[9].SetTopLeft(823, 490);		
	button[10].LoadBitmapByString({ "Resources/window/setting/button_effec_1.bmp", "Resources/window/setting/button_effec_2.bmp" });
	button[10].SetTopLeft(405, 506);
	button[11].LoadBitmapByString({ "Resources/window/setting/button_back.bmp" });
	button[11].SetTopLeft(560, 720);
	button[12].LoadBitmapByString({ "Resources/window/paused/button_end.bmp" });	//跟button7的差異在一個回home 一個map
	button[12].SetTopLeft(290, 560);	//end
	button[13].LoadBitmapByString({ "Resources/window/paused/button_resume.bmp" });
	button[13].SetTopLeft(820, 560);	//resume
	button[14].LoadBitmapByString({ "Resources/window/paused/button_retry.bmp" });
	button[14].SetTopLeft(560, 690);	//retry
	button[15].LoadBitmapByString({ "Resources/window/die/button_menu.bmp" });
	button[15].SetTopLeft(200, 660);
	button[16].LoadBitmapByString({ "Resources/window/die/button_retry.bmp" });
	button[16].SetTopLeft(550, 660);
	button[17].LoadBitmapByString({ "Resources/window/die/button_skip.bmp" });
	button[17].SetTopLeft(920, 660);
	button[18].LoadBitmapByString({ "Resources/window/pass/button_continue.bmp" });
	button[18].SetTopLeft(480, 720);
}



void Button::showButton(int page_phase) {
	//Home page
	if (page_phase == 0) {
		button[0].ShowBitmap();	//playButton at home
		button[1].ShowBitmap();	//settingButton at home
	}

	//Menu page
	if (page_phase == 1) {
		button[7].ShowBitmap();	//backButton at menu
		button[2].ShowBitmap();	//stage1
		button[3].ShowBitmap();	//stage2
		button[4].ShowBitmap();	//stage3
		button[5].ShowBitmap();	//stage4
		button[6].ShowBitmap();	//stage5
	}

	//setting window
	if (page_phase == 2) {
		button[9].ShowBitmap();		//musicButton
		button[10].ShowBitmap();	//effectButton
		button[11].ShowBitmap();	//endButton
	}

	//paused window
	if (page_phase == 3) {
		button[12].ShowBitmap();	//endButton
		button[13].ShowBitmap();	//resumeButton
		button[14].ShowBitmap();	//retryButton
	}

	//diw window
	if (page_phase == 4) {
		button[15].ShowBitmap();	//menuButton
		button[16].ShowBitmap();	//retryButton
		button[17].ShowBitmap();	//skipButton
	}

	//pass window
	if (page_phase == 5) {
		button[18].ShowBitmap();	//continueButton
	}

	//map
	if (page_phase >= 6) {
		button[8].ShowBitmap();		//pausedButton at map
	}

}



void Button::isClick(int num) {
	if (num == 9 ) {
		if (button[9].GetFrameIndexOfBitmap() == 0) {
			button[9].SetFrameIndexOfBitmap(1);
		}
		else if (button[9].GetFrameIndexOfBitmap() == 1) {
			button[9].SetFrameIndexOfBitmap(0);
		}
	}
	if (num == 10) {
		if (button[10].GetFrameIndexOfBitmap() == 0) {
			button[10].SetFrameIndexOfBitmap(1);
		}
		else if (button[10].GetFrameIndexOfBitmap() == 1) {
			button[10].SetFrameIndexOfBitmap(0);
		}
	}
}
