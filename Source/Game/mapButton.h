#pragma once

#ifndef MAPBUTTON_H
#define MAPBUTTON_H
#include "../Game/myObject.h"

class MapButton : public Object {
public:
	game_framework::CMovingBitmap mapButton[2];

	void generateObject();
	void showObject(int map_stage);

};

#endif // !MAPBUTTON_H