#pragma once

#ifndef MAPP0OL_H
#define MAPP0OL_H
#include "../Game/myObject.h"

class MapPool : public Object {
public:
	game_framework::CMovingBitmap redPool[8];
	game_framework::CMovingBitmap bluePool[8];
	game_framework::CMovingBitmap greenPool;
	void generateObject();
	void showObject(int map_stage);

};

#endif // !MAPP0OL_H