#pragma once

#ifndef WATERGIRL_H
#define WATERGIRL_H
#include <chrono>
#include "../Game/myCharacter.h"
typedef unsigned int UINT;

using clock_type = std::chrono::high_resolution_clock;
using time_type = std::chrono::duration<double, std::chrono::milliseconds::period>;

class Watergirl : public Character {
public:
	bool IsAButtonClick = false;
	bool IsDButtonClick = false;
	bool IsWButtonClick = false;
	std::chrono::time_point<clock_type> start;

	void IsMoving(Map map);
	void IsButtonUp(UINT);
	void IsButtonDown(UINT);

	bool IsTimesUp();
};

#endif