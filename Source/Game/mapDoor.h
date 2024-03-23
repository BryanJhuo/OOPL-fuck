#pragma once

#ifndef MAPDOOR_H
#define MAPDOOR_H
#include "../Game/myObject.h"

class MapDoor : public Object {
public:
	game_framework::CMovingBitmap mapDoor[2];

	void generateObject();
	void showObject(int map_stage);

};

#endif // !MAPDOOR_H