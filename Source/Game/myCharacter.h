#pragma once

#ifndef myCharacter_h
#define myCharacter_h
#include "../Library/gameutil.h"
#include "../Game/myMap.h"

class Character {
public:
	game_framework::CMovingBitmap character;

	virtual void IsMoving(Map &map) = 0;
	virtual void IsButtonUp(UINT) = 0;
	virtual void IsButtonDown(UINT) = 0;
	void moveRight();
	void moveLeft();
	void moveJumpUp();
	void moveJumpDown();
	void isDropDown(Map &map);
	int findClosePlace(Map &map, int x, int y, int height);
	// int findBounder(Map& map, int x, int y);

};

#endif // !"myCharacter.h"
