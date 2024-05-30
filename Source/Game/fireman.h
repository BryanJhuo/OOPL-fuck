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
	int frame = 0;
	
	std::chrono::time_point<clock_type> start;

	void IsMoving(Map &map, Object::MapPole& pole, int page);
	void IsButtonUp(UINT);
	void IsButtonDown(UINT);
	void resetMap(int map_stage);
	void SetFrame();
	bool isBumpHead(Map& map, Object::MapPole &pole, int page);
	bool isBumpRightWall(Map &map, Object::MapPole& pole, int page);
	bool isBumpLeftWall(Map &map, Object::MapPole& pole, int page);
	bool IsTimesUp();

};

#endif