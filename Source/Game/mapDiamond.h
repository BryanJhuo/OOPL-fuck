#pragma once

#ifndef MAPDIAMOND_H
#define MAPDIAMOND_H
#include "../Game/myObject.h"

class MapDiamond : public Object {
public:
	game_framework::CMovingBitmap redDiamond[11];
	game_framework::CMovingBitmap blueDiamond[11];
	game_framework::CMovingBitmap whiteDiamond;

	void generateObject();
	void showObject(int map_stage);

};

#endif // !MAPDIAMOND_H