#pragma once

#ifndef myCharacter_h
#define myCharacter_h
#include "../Library/gameutil.h"

class Character {
public:
	game_framework::CMovingBitmap character;
	int jumpHeight = 0;

	virtual void IsMoving() = 0;
	virtual void IsButtonUp(UINT) = 0;
	virtual void IsButtonDown(UINT) = 0;
	void moveRight();
	void moveLeft();
	void moveRightJumpUp();
	void moveRightJumpDown();
	void moveLeftJumpUp();
	void moveLeftJumpDown();
};

#endif // !"myCharacter.h"
