#pragma once

#ifndef MAPFAN_H
#define MAPFAN_H
#include "../Game/myObject.h"

class MapFan : public Object {
public:
	game_framework::CMovingBitmap mapFan[2];

	void generateObject();
	void showObject(int map_stage);

};

#endif // !MAPFAN_H