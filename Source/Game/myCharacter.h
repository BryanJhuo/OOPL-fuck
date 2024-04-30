#pragma once

#ifndef myCharacter_h
#define myCharacter_h
#include "../Library/gameutil.h"
#include "../Game/myMap.h"
#include "../Game/myObject.h"

class Character {
public:
	game_framework::CMovingBitmap character;

	virtual void IsMoving(Map &map, Object::MapPole &pole) = 0;
	virtual void IsButtonUp(UINT) = 0;
	virtual void IsButtonDown(UINT) = 0;
	virtual void resetMap(int map_stage);
	void moveRight();
	void moveLeft();
	void moveJumpUp(int buttonState);
	void moveJumpDown();
	void isDropDown(Map &map, Object::MapPole &pole, Object::MapBox &box,int page);
	int findClosePlace(Map &map, int x, int y, int height);

};

#endif // !"myCharacter.h"
