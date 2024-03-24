#pragma once
#pragma once

#ifndef MAPBOX_H
#define MAPBOX_H
#include "../Game/myObject.h"

class MapBox: public Object {
public:
	game_framework::CMovingBitmap mapBox[1];

	void generateObject();
	void showObject(int map_stage);

};

#endif // !MAPBOX_H