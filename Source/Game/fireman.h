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

	void IsMoving(Map map);
	void IsButtonUp(UINT);
	void IsButtonDown(UINT);
	bool isBumpHead(Map map);
	bool isBumpRightWall(Map map);
	bool isBumpLeftWall(Map map);
	bool IsTimesUp();

};

#endif