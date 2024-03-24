#pragma once

#ifndef MYOBJECT_H

#define MYOBJECT_H
#include "../Library/gameutil.h"

class Object {
public:


	virtual void generateObject() =0;
	virtual void showObject(int map_stage) = 0;


	bool isOverlap(game_framework::CMovingBitmap character, game_framework::CMovingBitmap object) {
		return  game_framework::CMovingBitmap::IsOverlap(character, object);
	}

	

};
#endif // !MYOBJECT_H