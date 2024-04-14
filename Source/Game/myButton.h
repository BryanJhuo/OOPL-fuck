#pragma once
#ifndef MYBUTTON_H
#define MYBUTTON_H
#include "../Library/gameutil.h"

class Button {
public:
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
	game_framework::CMovingBitmap button[20];

	void loadButton();
	void showButton(int page_phase);
	
	bool ifOverlap(int index, const CPoint& pt) {
		auto& btn = button[index];
		CPoint pos = { btn.GetLeft(), btn.GetTop() };
		int height = btn.GetHeight();
		int width = btn.GetWidth();

		return (pt.x >= pos.x && pt.y >= pos.y) &&
			(pt.x <= pos.x + width && pt.y <= pos.y + height);
	}
	

	void isClick(int num);


};
#endif // !MYBUTTON_H