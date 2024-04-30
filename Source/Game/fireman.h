#pragma once

#ifndef FIREMAN_H
#define FIREMAN_H
#include "../Game/myCharacter.h"
#include <chrono>
using clock_type = std::chrono::high_resolution_clock;
using time_type = std::chrono::duration<double, std::chrono::milliseconds::period>;

class Fireman : public Character {
public:
	bool IsRightButtonClick = false;
	bool IsLeftButtonClick = false;
	bool IsUpButtonClick = false;
	
	std::chrono::time_point<clock_type> start;

	void IsMoving(Map &map, Object::MapPole& pole);
	void IsButtonUp(UINT);
	void IsButtonDown(UINT);
	void resetMap(int map_stage);
	bool isBumpHead(Map& map, Object::MapPole &pole);
	bool isBumpRightWall(Map &map);
	bool isBumpLeftWall(Map &map);
	bool IsTimesUp();

};

#endif