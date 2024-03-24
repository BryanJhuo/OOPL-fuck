#pragma once

#ifndef MYMAP_H

#define MYMAP_H
#include "../Library/gameutil.h"

class Map{
public:
	int map[29][40];

	game_framework::CMovingBitmap mapResource1[29][40];
	game_framework::CMovingBitmap mapResource2[29][40];
	game_framework::CMovingBitmap mapResource3[29][40];
	game_framework::CMovingBitmap mapResource4[29][40];
	game_framework::CMovingBitmap mapResource5[29][40];

	void generateMap();
	void showMap(int map_stage);

};
#endif // !MYMAP_H