#pragma once

#ifndef WATERGIRL_H
#define WATERGIRL_H

#include "../Game/myCharacter.h"
#include <chrono>
using clock_type = std::chrono::high_resolution_clock;
using time_type = std::chrono::duration<double, std::chrono::milliseconds::period>;
typedef unsigned int UINT;

class Watergirl : public Character {
public:
	bool IsAButtonClick = false;
	bool IsDButtonClick = false;
	bool IsWButtonClick = false;
	std::chrono::time_point<clock_type> start;

	void IsMoving();
	void IsButtonUp(UINT);
	void IsButtonDown(UINT);
	bool IsTimesUp();
	void IsDropDown();
};

#endif