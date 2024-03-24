#pragma once

#ifndef MAPDIAMOND_H
#define MAPDIAMOND_H
#include "../Game/myObject.h"

class MapDiamond : public Object {
public:
	game_framework::CMovingBitmap mapDiamond[7];

	void generateObject();
	void showObject(int map_stage);

};

#endif // !MAPDIAMOND_H