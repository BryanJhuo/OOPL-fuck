#pragma once

#ifndef MAPPOLE_H
#define MAPMAPPOLE_HCONTROLLER_H
#include "../Game/myObject.h"

class MapPole: public Object {
public:
	game_framework::CMovingBitmap mapPole[2];

	void generateObject();
	void showObject(int map_stage);

};

#endif // !MAPPOLE_H