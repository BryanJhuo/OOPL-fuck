#include "stdafx.h"
#include "../Game/myScene.h"

void Scene::loadScene() {
	//home menu map
	background[0].LoadBitmapByString({ "Resources/home_page/background.bmp" });
	background[1].LoadBitmapByString({ "Resources/menu/background.bmp" });
	background[2].LoadBitmapByString({ "Resources/map/map0.bmp" });
	for (int i = 0; i < 3; i++) {
		background[i].SetTopLeft(0, 0);
	}
	
	//window(setting paused die pass)
	window[0].LoadBitmapByString({ "Resources/window/setting/background.bmp" });
	window[1].LoadBitmapByString({ "Resources/window/paused/background.bmp" });
	window[2].LoadBitmapByString({ "Resources/window/die/background.bmp" });
	window[3].LoadBitmapByString({ "Resources/window/pass/background.bmp" });
	for (int i = 0; i < 4; i++) {
		window[i].SetTopLeft(80, 215);
	}
	
}

void Scene::showScene(int page_phase) {
	//Home page
	if (page_phase == 0) {
		background[0].ShowBitmap();		//home
	}

	//Menu page
	if (page_phase == 1) {
		background[1].ShowBitmap();		//menu
	}

	//setting window
	if (page_phase == 2) {
		window[0].ShowBitmap();		//window
	}

	//paused window
	if (page_phase == 3) {
		window[1].ShowBitmap();		//window
	}

	//diw window
	if (page_phase == 4) {
		window[2].ShowBitmap();		//window
	}

	//pass window
	if (page_phase == 5) {
		window[3].ShowBitmap();		//window
	}
	
	//map
	if (page_phase >= 6) {
		background[2].ShowBitmap();		//map
	}

}