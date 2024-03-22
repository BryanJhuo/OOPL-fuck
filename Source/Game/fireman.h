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

	void IsMoving();
	void IsButtonUp(UINT);
	void IsButtonDown(UINT);
	bool IsTimesUp();
	void IsDropDown();
};

#endif