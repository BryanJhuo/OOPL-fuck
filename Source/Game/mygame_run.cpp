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
// �o��class���C�����C�����檫��A�D�n���C���{�����b�o��
/////////////////////////////////////////////////////////////////////////////

CGameStateRun::CGameStateRun(CGame* g) : CGameState(g)
{

}

CGameStateRun::~CGameStateRun()
{
}

void CGameStateRun::OnBeginState()
{
}

void CGameStateRun::OnMove()							// ���ʹC������
{
	if (this->page_phase == 6){
		fireman.IsMoving(this->map, this->mapPole);
		watergirl.IsMoving(this->map, this->mapPole);
		
		if (!fireman.IsUpButtonClick) this->fireman.isDropDown(this->map);
		if (!watergirl.IsWButtonClick) this->watergirl.isDropDown(this->map);
		this->isControllerOverlap(this->page_phase - 5);
		this->isButtonOverlap(this->page_phase - 5);
		
	}
}

void CGameStateRun::OnInit()  								// �C������Ȥιϧγ]�w
{
	/*
	background[3]: home, menu, map
	window[4]: setting, paused, die, pass
	*/
	scene.loadScene();

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
	button.loadButton();


	fireman.character.LoadBitmapByString({ "Resources/characters/fireman_front_1.bmp" }, RGB(0, 255, 0));
	fireman.character.SetTopLeft(38, 877);
	watergirl.character.LoadBitmapByString({ "Resources/characters/watergirl_front_1.bmp" }, RGB(0, 255, 0));
	watergirl.character.SetTopLeft(38, 737);

	map.generateMap();
	mapButton.generateObject();
	mapController.generateObject();
	mapPole.generateObject();
	mapBox.generateObject();
	mapDoor.generateObject();
	mapDiamond.generateObject();
	mapPool.generateObject();
	mapFan.generateObject();
}

void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	fireman.IsButtonDown(nChar);
	watergirl.IsButtonDown(nChar);

}

void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	fireman.IsButtonUp(nChar);
	watergirl.IsButtonUp(nChar);
}

void CGameStateRun::OnLButtonDown(UINT nFlags, CPoint point)  // �B�z�ƹ����ʧ@
{
	if (nFlags == VK_LBUTTON) {
		IsMouseOverlap(point.x, point.y);

	}

}

void CGameStateRun::OnLButtonUp(UINT nFlags, CPoint point)	// �B�z�ƹ����ʧ@
{
}

void CGameStateRun::OnMouseMove(UINT nFlags, CPoint point)	// �B�z�ƹ����ʧ@
{

}

void CGameStateRun::OnRButtonDown(UINT nFlags, CPoint point)  // �B�z�ƹ����ʧ@
{
}

void CGameStateRun::OnRButtonUp(UINT nFlags, CPoint point)	// �B�z�ƹ����ʧ@
{
}

void CGameStateRun::OnShow()
{
	scene.showScene(page_phase);

	//Map1
	if (page_phase == 6) {
		map.showMap(page_phase - 5);
		mapButton.showObject(page_phase - 5);
		mapController.showObject(page_phase - 5);
		mapPole.showObject(page_phase - 5);
		mapBox.showObject(page_phase - 5);
		mapDoor.showObject(page_phase - 5);
		mapDiamond.showObject(page_phase - 5);
		mapPool.showObject(page_phase - 5);

		fireman.character.ShowBitmap();		//(38, 877)
		watergirl.character.ShowBitmap();	//(38, 737)
	}

	//Map2
	if (page_phase == 7) {
		map.showMap(page_phase - 5);

		mapDoor.showObject(page_phase - 5);
		mapDiamond.showObject(page_phase - 5);
		mapPool.showObject(page_phase - 5);

		fireman.character.ShowBitmap();		//(1200, 70)
		watergirl.character.ShowBitmap();	//(70, 460)
	}

	//Map3
	if (page_phase == 8) {
		map.showMap(page_phase - 5);

		mapDoor.showObject(page_phase - 5);
		mapDiamond.showObject(page_phase - 5);
		mapPole.showObject(page_phase - 5);
		mapController.showObject(page_phase - 5);
		mapButton.showObject(page_phase - 5);

		fireman.character.ShowBitmap();		//(1020, 745)
		watergirl.character.ShowBitmap();	//(905, 745)
	}

	//Map4
	if (page_phase == 9) {
		map.showMap(page_phase - 5);

		mapDoor.showObject(page_phase - 5);
		mapFan.showObject(page_phase - 5);
		mapPool.showObject(page_phase - 5);
		mapDiamond.showObject(page_phase - 5);

		fireman.character.ShowBitmap();		//(50, 875)
		watergirl.character.ShowBitmap();	//(1285, 875)
	}

	//Map5
	if (page_phase == 10) {
		map.showMap(page_phase - 5);

		mapDoor.showObject(page_phase - 5);
		mapPole.showObject(page_phase - 5);
		mapController.showObject(page_phase - 5);
		mapDiamond.showObject(page_phase - 5);
		

		fireman.character.ShowBitmap();		//(130, 875)
		watergirl.character.ShowBitmap();	//(1140, 41)
	}


	ShowWindowCoordinate();
	button.showButton(page_phase);



}


void CGameStateRun::ShowWindowCoordinate() {
	// �y���ন�r��
	string text;
	stringstream ss;
	// �ŧi��ܤ�r�u��
	CDC* pDC = CDDraw::GetBackCDC();
	// Window ���U��API
	POINT pt;							// �y��
	HWND hWnd = GetForegroundWindow();	// �ŧi�è��o��e�������y�`
	BOOL bReturn = GetCursorPos(&pt);	// ���o��e���ЦbScreen�W���y��(�Y�Lreturn false)
	ScreenToClient(hWnd, &pt);			// �N���oScreen���y���ন��e�����y�`���y��
	if (bReturn != 0) {
		ss << pt.x << ", " << pt.y;
		text = ss.str();
		CTextDraw::Print(pDC, 5, 5, text);
	}
	CDDraw::ReleaseBackCDC();
}



void CGameStateRun::IsMouseOverlap(int mouse_x, int mouse_y) {

	//playButton at Home
	if (button.ifOverlap(0, CPoint(mouse_x, mouse_y)) && page_phase == 0) {
		page_phase = 6;
	}
	//settingButton at Home
	if (button.ifOverlap(1, CPoint(mouse_x, mouse_y)) && page_phase == 0) {
		page_phase = 2;
	}



	//stageButton at Menu
	for (int i = 2; i < 7; i++) {
		if (button.ifOverlap(i, CPoint(mouse_x, mouse_y)) && page_phase == 1) {
			page_phase = i + 4;
		}
	}
	//backButton at Menu
	if (button.ifOverlap(7, CPoint(mouse_x, mouse_y)) && page_phase == 1) {
		page_phase = 0;
	}
	//pausedButton at Map
	if (button.ifOverlap(8, CPoint(mouse_x, mouse_y)) && page_phase >= 6) {
		page_phase = 3;
	}

	if (button.ifOverlap(9, CPoint(mouse_x, mouse_y)) && page_phase == 2) {
		//music on/off
	}
	if (button.ifOverlap(10, CPoint(mouse_x, mouse_y)) && page_phase == 2) {
		//effect on/of
	}
	//backButton at setting
	if (button.ifOverlap(11, CPoint(mouse_x, mouse_y)) && page_phase == 2) {
		page_phase = 1;
	}
	//at paused
	if (button.ifOverlap(12, CPoint(mouse_x, mouse_y)) && page_phase == 3) {
		//end
		page_phase = 1;
	}
	if (button.ifOverlap(13, CPoint(mouse_x, mouse_y)) && page_phase == 3) {
		//resume
	}
	if (button.ifOverlap(14, CPoint(mouse_x, mouse_y)) && page_phase == 3) {
		//skip
	}
	//at die
	if (button.ifOverlap(15, CPoint(mouse_x, mouse_y)) && page_phase == 4) {
		//menu
		page_phase = 1;
	}
	if (button.ifOverlap(16, CPoint(mouse_x, mouse_y)) && page_phase == 4) {
		//retry
		page_phase = 1;
	}
	if (button.ifOverlap(17, CPoint(mouse_x, mouse_y)) && page_phase == 4) {
		//skip
		page_phase = 1;
	}
	//continueButton at pass
	if (button.ifOverlap(18, CPoint(mouse_x, mouse_y)) && page_phase == 5) {
		page_phase = 1;
	}

}

void CGameStateRun::isControllerOverlap(int page) {
	if (page == 1) {
		// overlap from right side (opening controller)
		if (CMovingBitmap::IsOverlap(this->fireman.character, this->mapController.mapController[0])
			&& this->fireman.character.GetLeft() > this->mapController.mapController[0].GetLeft() + 30){
			this->mapController.mapController[0].SetFrameIndexOfBitmap(1);
			this->mapController.controllerState[0] = true;
			this->controllerMode = 1;
		}
		// overlap from left side (closing controller)
		else if (CMovingBitmap::IsOverlap(this->fireman.character, this->mapController.mapController[0])
			&& this->fireman.character.GetLeft() + 35 < this->mapController.mapController[0].GetLeft()){
			this->mapController.mapController[0].SetFrameIndexOfBitmap(0);
			this->mapController.controllerState[0] = true;
			this->controllerMode = 2;
		}

		if (this->mapController.controllerState[0]) {
			this->movingPole(1, 0);
		}

	}
	
}

void CGameStateRun::movingPole(int page, int index) {
	int current_Height = this->mapPole.mapPole[index].GetTop();
	
	if (current_Height < 630 && this->controllerMode == 1) {
		this->mapPole.mapPole[index].SetTopLeft(this->mapPole.mapPole[index].GetLeft(), current_Height + 10);
	}
	else if (current_Height > 525 && this->controllerMode == 2) {
		this->mapPole.mapPole[index].SetTopLeft(this->mapPole.mapPole[index].GetLeft(), current_Height - 10);
	}
	else { 
		this->mapController.controllerState[0] = false; 
		this->controllerMode = 0;
	}
}



void CGameStateRun::isButtonOverlap(int page) {
	if (page == 1) {
		// Button Up
		if (CMovingBitmap::IsOverlap(this->fireman.character, this->mapButton.mapButton[0])) {
			this->mapButton.mapButton[0].SetFrameIndexOfBitmap(1);
			this->mapButton.buttonState[0] = true;
			this->buttonMode[0] = 1;
		}
		else if (CMovingBitmap::IsOverlap(this->fireman.character, this->mapButton.mapButton[1])) {
			this->mapButton.mapButton[1].SetFrameIndexOfBitmap(1);
			this->mapButton.buttonState[1] = true;
			this->buttonMode[1] = 1;
		}
		else {
			this->mapButton.mapButton[0].SetFrameIndexOfBitmap(0);
			this->mapButton.buttonState[0] = false;
			this->buttonMode[0] = 2;
			this->mapButton.mapButton[1].SetFrameIndexOfBitmap(0);
			this->mapButton.buttonState[1] = false;
			this->buttonMode[1] = 2;
		}
		this->movingPolefromButton(1, this->mapPole.mapPole[1]);
	}
}

void CGameStateRun::movingPolefromButton(int page, CMovingBitmap &pole) {
	int current_Height = pole.GetTop();

	if (current_Height < 525 && (this->buttonMode[0] == 1 || this->buttonMode[1] == 1)) {
		pole.SetTopLeft(pole.GetLeft(), current_Height + 10);
	}
	else if (current_Height > 425 && (this->buttonMode[0] == 2 || this->buttonMode[1] == 2)) {
		pole.SetTopLeft(pole.GetLeft(), current_Height - 10);
	}
	else {
		this->buttonMode[0] = 0;
		this->buttonMode[1] = 0;
	}
}