#include "stdafx.h"
#include "../Core/Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "../Library/audio.h"
#include "../Library/gameutil.h"
#include "../Library/gamecore.h"
#include "mygame.h"

using namespace game_framework;
/////////////////////////////////////////////////////////////////////////////
// 這個class為遊戲的遊戲開頭畫面物件
/////////////////////////////////////////////////////////////////////////////

CGameStateInit::CGameStateInit(CGame *g) : CGameState(g)
{
}

void CGameStateInit::OnInit()
{
	//
	// 當圖很多時，OnInit載入所有的圖要花很多時間。為避免玩遊戲的人
	//     等的不耐煩，遊戲會出現「Loading ...」，顯示Loading的進度。
	//
	ShowInitProgress(0, "Start Initialize...");	// 一開始的loading進度為0%
	//
	// 開始載入資料
	//
	Sleep(1000);				// 放慢，以便看清楚進度，實際遊戲請刪除此Sleep
	//
	// 此OnInit動作會接到CGameStaterRun::OnInit()，所以進度還沒到100%
	//

	
	CAudio* audio = CAudio::Instance();
	audio->Load(0, R"(Resources/audio/HomeMusic.wav)");		//Home
	audio->Load(1, R"(Resources/audio/MenuMusic.wav)");		//Menu
	audio->Load(2, R"(Resources/audio/MapMusic1.wav)");		//Map
	audio->Load(3, R"(Resources/audio/EndWindow.wav)");		//EndWindow
	audio->Load(4, R"(Resources/audio/PassWindow.wav)");	//PassWindow
	audio->Load(5, R"(Resources/audio/ButtonClick.wav)");
	audio->Load(6, R"(Resources/audio/Diamond.wav)");
	audio->Load(7, R"(Resources/audio/Door.wav)");
	audio->Play(0, true);
}

void CGameStateInit::OnBeginState()
{
}

void CGameStateInit::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{

}

void CGameStateInit::OnLButtonDown(UINT nFlags, CPoint point)
{
	CAudio* audio = CAudio::Instance();
	GotoGameState(GAME_STATE_RUN);		// 切換至GAME_STATE_RUN
}

void CGameStateInit::OnShow()
{
	//CAudio* audio = CAudio::Instance();
	
}
