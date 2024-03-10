#include "stdafx.h"
#include "../Core/Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "../Library/audio.h"
#include "../Library/gameutil.h"
#include "../Library/gamecore.h"
#include "mygame.h"
#include "sstream"

using namespace game_framework;

/////////////////////////////////////////////////////////////////////////////
// 這個class為遊戲的遊戲執行物件，主要的遊戲程式都在這裡
/////////////////////////////////////////////////////////////////////////////

CGameStateRun::CGameStateRun(CGame *g) : CGameState(g)
{

}

CGameStateRun::~CGameStateRun()
{
}

void CGameStateRun::OnBeginState()
{
}

void CGameStateRun::OnMove()							// 移動遊戲元素
{
	if (IsRightButtonDown && !IsRightButtonUp)
		character.SetTopLeft(character.GetLeft() + 5, character.GetTop());
	if (IsLeftButtonDown && !IsLeftButtonUp)
		character.SetTopLeft(character.GetLeft() - 5, character.GetTop());
	if (IsUpButtonDown && !IsUpButtonUp)
		character.SetTopLeft(character.GetLeft(), character.GetTop() - 5);
}

void CGameStateRun::OnInit()  								// 遊戲的初值及圖形設定
{
	background.LoadBitmapByString({
		"Resources/home_page/background.bmp",
		"Resources/menu/background.bmp",
		"Resources/map/map1.bmp",
		"Resources/map/block1.bmp"
		});
	background.SetTopLeft(0, 0);

	/*
	home: (0)play  (1)setting
	menu: (2)stage1, 2, 3, 4 (3)back 
	map: (4)paused
	window-
	settig: (5)muic (6)effect (7)end
	paused: (8)end (9)resume (10)retry
	die: (11)menu (12)retry (13)skip 
	pass: (14)continue
	*/
	button[0].LoadBitmapByString({ "Resources/home_page/button_play.bmp" }); 
	button[0].SetTopLeft(553, 530);
	button[1].LoadBitmapByString({ "Resources/home_page/button_setting.bmp" });
	button[1].SetTopLeft(100, 890);
	button[2].LoadBitmapByString({ "Resources/menu/stage_gray.bmp", "Resources/menu/stage_green.bmp", "Resources/menu/stage_orange.bmp", "Resources/menu/stage_purple.bmp" });
	button[2].SetTopLeft(0, 0);
	button[3].LoadBitmapByString({ "Resources/menu/button_back.bmp" });
	button[3].SetTopLeft(30, 830);
	button[4].LoadBitmapByString({ "Resources/map/button_paused.bmp" });
	button[4].SetTopLeft(1320, 10);
	button[5].LoadBitmapByString({ "Resources/window/setting/button_music_1.bmp", "Resources/window/setting/button_music_2.bmp" });
	button[5].SetTopLeft(0, 0);
	button[6].LoadBitmapByString({ "Resources/window/setting/button_effec_1.bmp", "Resources/window/setting/button_effec_2.bmp" });
	button[6].SetTopLeft(0, 0);
	button[7].LoadBitmapByString({ "Resources/window/setting/button_end.bmp" });
	button[7].SetTopLeft(90, 800);
	button[8].LoadBitmapByString({ "Resources/window/paused/button_end.bmp" });	//跟button7的差異在一個回home 一個map
	button[8].SetTopLeft(0, 0);
	button[9].LoadBitmapByString({ "Resources/window/paused/button_resume.bmp" });
	button[9].SetTopLeft(0, 0);
	button[10].LoadBitmapByString({ "Resources/window/paused/button_retry.bmp" });
	button[10].SetTopLeft(0, 0);
	button[11].LoadBitmapByString({ "Resources/window/die/button_menu.bmp" });
	button[11].SetTopLeft(0, 0);
	button[12].LoadBitmapByString({ "Resources/window/die/button_retry.bmp" });
	button[12].SetTopLeft(0, 0);
	button[13].LoadBitmapByString({ "Resources/window/die/button_skip.bmp" });
	button[13].SetTopLeft(0, 0);
	button[14].LoadBitmapByString({ "Resources/window/pass/button_continue.bmp" });
	button[14].SetTopLeft(0, 0);

	//window(setting paused die pass) select
	window[0].LoadBitmapByString({ "Resources/window/setting/background.bmp" });
	window[1].LoadBitmapByString({ "Resources/window/paused/background.bmp" });
	window[2].LoadBitmapByString({ "Resources/window/die/background.bmp" });
	window[3].LoadBitmapByString({ "Resources/window/pass/background.bmp" });
	for (int i = 0; i < 4; i++) {
		window[i].SetTopLeft(80, 215);
	}
	

	map_box.LoadBitmapByString({ "Resources/object/box.bmp" });
	map_button[0].LoadBitmapByString({ "Resources/object/button_blue_1.bmp", "Resources/object/button_blue_2.bmp" , "Resources/object/button_blue_3.bmp" });	//blue purple red
	map_button[1].LoadBitmapByString({ "Resources/object/button_purple_1.bmp", "Resources/object/button_purple_2.bmp" , "Resources/object/button_purple_3.bmp" });
	map_button[2].LoadBitmapByString({ "Resources/object/button_red_1.bmp", "Resources/object/button_red_2.bmp" , "Resources/object/button_red_3.bmp" });
	map_controller[0].LoadBitmapByString({ "Resources/object/controller_yellow_1.bmp", "Resources/object/controller_yellow_2.bmp" });	//yellow blue green red white
	map_controller[1].LoadBitmapByString({ "Resources/object/controller_blue_1.bmp", "Resources/object/controller_blue_2.bmp" });
	map_controller[2].LoadBitmapByString({ "Resources/object/controller_green_1.bmp", "Resources/object/controller_green_2.bmp" });
	map_controller[3].LoadBitmapByString({ "Resources/object/controller_red_1.bmp", "Resources/object/controller_red_2.bmp" });
	map_controller[4].LoadBitmapByString({ "Resources/object/controller_white_1.bmp", "Resources/object/controller_white_2.bmp" });
	map_diamond[0].LoadBitmapByString({"Resources/object/diamond_red.bmp"});	//red blue white
	map_diamond[1].LoadBitmapByString({ "Resources/object/diamond_blue.bmp" });
	map_diamond[2].LoadBitmapByString({ "Resources/object/diamond_white.bmp" });
	map_door[0].LoadBitmapByString({ "Resources/object/door_fire_1.bmp", "Resources/object/door_fire_2.bmp" });	//fire water
	map_door[1].LoadBitmapByString({ "Resources/object/door_water_1.bmp", "Resources/object/door_water_2.bmp" });
	map_pole[0].LoadBitmapByString({ "Resources/object/pole_M1_yellow_1.bmp", "Resources/object/pole_M1_yellow_2.bmp" });
	map_pole[1].LoadBitmapByString({"Resources/object/pole_M1_purple_1.bmp", "Resources/object/pole_M1_purple_2.bmp" });
	
	character.LoadBitmapByString({ "Resources/characters/fireman_front_1.bmp" });
	character.SetTopLeft(50, 905);
	
}

void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{	
	switch (nChar)
	{
	case VK_RIGHT :
		IsRightButtonDown = true;
		break;
	case VK_LEFT:
		IsLeftButtonDown = true;
		break;
	case VK_UP:
		IsUpButtonDown = true;
		break;
	default:
		IsRightButtonDown = false;
		IsLeftButtonDown = false;
		IsUpButtonDown = false;
		break;
	}
	
}

void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	switch (nChar)
	{
	case VK_RIGHT:
		IsRightButtonUp = true;
		break;
	case VK_LEFT:
		IsLeftButtonUp = true;
		break;
	case VK_UP:
		IsUpButtonUp = true;
		break;
	default:
		IsRightButtonUp = false;
		IsLeftButtonUp = false;
		IsUpButtonUp = false;
		break;
	}
}

void CGameStateRun::OnLButtonDown(UINT nFlags, CPoint point)  // 處理滑鼠的動作
{
	if (nFlags == VK_LBUTTON) {
		IsMouseOverlap(point.x, point.y);
	}
	
}

void CGameStateRun::OnLButtonUp(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
}

void CGameStateRun::OnMouseMove(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
}

void CGameStateRun::OnRButtonDown(UINT nFlags, CPoint point)  // 處理滑鼠的動作
{
}

void CGameStateRun::OnRButtonUp(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
}

void CGameStateRun::OnShow()
{		
	if (call_window) {
		show_window();
	}
	else {
		show_page();
	}
	ShowWindowCoordinate();
	
}

void CGameStateRun::show_page() {
	if (page_phase == 0) {	//home page
		background.SetFrameIndexOfBitmap(0);
		background.ShowBitmap();
		button[0].ShowBitmap();	//button_play
		button[1].ShowBitmap();	//button_setting
	}
	if (page_phase == 1) {	//menu
		background.SetFrameIndexOfBitmap(1);
		background.ShowBitmap();
		button[3].ShowBitmap();	//back
	}
	if (page_phase == 2) {	//map1
		// background.SetFrameIndexOfBitmap(2);
		//這邊你先當我在對位子，之後地圖(block)再改生成方法
		background.ShowBitmap();
		button[4].ShowBitmap();
		map_diamond[0].SetTopLeft(720, 950);
		map_diamond[0].ShowBitmap();
		map_diamond[1].SetTopLeft(1000, 950);
		map_diamond[1].ShowBitmap();
		map_diamond[0].SetTopLeft(250, 470);
		map_diamond[0].ShowBitmap();
		map_diamond[1].SetTopLeft(850, 500);
		map_diamond[1].ShowBitmap();
		map_diamond[1].SetTopLeft(60, 200);
		map_diamond[1].ShowBitmap();
		map_diamond[0].SetTopLeft(370, 70);
		map_diamond[0].ShowBitmap();
		map_diamond[1].SetTopLeft(800, 150);
		map_diamond[1].ShowBitmap();
		map_controller[0].SetTopLeft(310, 663);
		map_controller[0].ShowBitmap();
		map_pole[0].SetTopLeft(40, 540);	//40,685
		map_pole[0].ShowBitmap();
		map_pole[1].SetTopLeft(1226, 400);	//1226,545
		map_pole[1].ShowBitmap();
		map_button[0].SetTopLeft(470, 509);
		map_button[0].ShowBitmap();
		map_button[0].SetTopLeft(1020, 360);
		map_button[0].ShowBitmap();
		map_box.SetTopLeft(725, 255);
		map_box.ShowBitmap();
		map_door[0].SetTopLeft(1130, 120);
		map_door[0].ShowBitmap();
		map_door[1].SetTopLeft(1240, 120);
		map_door[1].ShowBitmap();
		character.ShowBitmap();
	}
}

void CGameStateRun::show_window() {
	// setting window
	if (window_phase == 0) {
		window[0].ShowBitmap();
		button[7].ShowBitmap();
	}
	// paused window
	if (window_phase == 1) {
		window[1].ShowBitmap();
		button[8].ShowBitmap();		//end
		button[9].ShowBitmap();		//resume
		button[10].ShowBitmap();	//retry
	}
}

void CGameStateRun::ShowWindowCoordinate() {
	// 座標轉成字串
	string text;
	stringstream ss;
	// 宣告顯示文字工具
	CDC* pDC = CDDraw::GetBackCDC();
	// Window 底下的API
	POINT pt;							// 座標
	HWND hWnd = GetForegroundWindow();	// 宣告並取得當前視窗的句柄
	BOOL bReturn = GetCursorPos(&pt);	// 取得當前鼠標在Screen上的座標(若無return false)
	ScreenToClient(hWnd, &pt);			// 將取得Screen的座標轉成當前視窗句柄的座標
	if (bReturn != 0) {
		ss << pt.x << ", " << pt.y;
		text = ss.str();
		CTextDraw::Print(pDC, 5, 5, text);
	}
	CDDraw::ReleaseBackCDC();
}


void CGameStateRun::IsMouseOverlap(int mouse_x, int mouse_y) {
	// playButton at Home Page
	if ((mouse_x >= button[0].GetLeft() && mouse_x <= button[0].GetLeft() + 300) && (mouse_y >= button[0].GetTop() && mouse_y <= button[0].GetTop() + 120) && page_phase == 0) {
		background.SetFrameIndexOfBitmap(2);
		page_phase = 2;
	}
	// settingButton at Home Page
	if ((mouse_x >= button[1].GetLeft() && mouse_x <= button[1].GetLeft() + 110) && (mouse_y >= button[1].GetTop() && mouse_y <= button[1].GetTop() + 110) && page_phase == 0) {
		button[7].SetTopLeft(560, 700);
		window_phase = 0;
		call_window = true;
	}

	// backButton at Stage Menu
	if ((mouse_x >= button[3].GetLeft() && mouse_x <= button[3].GetLeft() + 340) && (mouse_y >= button[3].GetTop() && mouse_y <= button[3].GetTop() + 150) && page_phase == 1) {
		background.SetFrameIndexOfBitmap(0);
		page_phase = 0;
	}

	// backButton at Setting Menu
	if ((mouse_x >= button[7].GetLeft() && mouse_x <= button[7].GetLeft() + 340) && (mouse_y >= button[7].GetTop() && mouse_y <= button[7].GetTop() + 150) && call_window == true && window_phase == 0) {
		call_window = false;
		page_phase = 0;
	}
	// settingButton at Map 
	if ((mouse_x >= button[4].GetLeft() && mouse_x <= button[4].GetLeft() + 35) && (mouse_y >= button[4].GetTop() && mouse_y <= button[4].GetTop() + 40) && page_phase == 2) {
		button[8].SetTopLeft(290,560);		//end
		button[9].SetTopLeft(820,560);		//resume
		button[10].SetTopLeft(560,690);	//retry
		window_phase = 1;
		call_window = true;
	}

	// backButton at Paused Menu
	if ((mouse_x >= button[8].GetLeft() && mouse_x <= button[8].GetLeft() + 300) && (mouse_y >= button[8].GetTop() && mouse_y <= button[8].GetTop() + 125) && call_window == true && window_phase == 1) {
		call_window = false;
		page_phase = 1;		//menu		
	}

	// resumeButton at Paused Menu
	if ((mouse_x >= button[9].GetLeft() && mouse_x <= button[9].GetLeft() + 300) && (mouse_y >= button[8].GetTop() && mouse_y <= button[8].GetTop() + 125) && call_window == true && window_phase == 1) {
		call_window = false;
		page_phase = 2;		//map1 (可能要改 或偵測回哪張地圖
	}

	// retryButton at Paused Menu
	if ((mouse_x >= button[10].GetLeft() && mouse_x <= button[10].GetLeft() + 300) && (mouse_y >= button[10].GetTop() && mouse_y <= button[10].GetTop() + 125) && call_window == true && window_phase == 1) {
		call_window = false;
		page_phase = 2;		//map1 (可能要改 或偵測回哪張地圖
	}


}