#pragma once

#ifndef WATERGIRL_H
#define WATERGIRL_H

#include "../Game/myCharacter.h"
typedef unsigned int UINT;

class Watergirl : public Character {
public:
	bool IsAButtonClick = false;
	bool IsDButtonClick = false;
	bool IsWButtonClick = false;

	void IsMoving();
	void IsButtonUp(UINT);
	void IsButtonDown(UINT);
};

#endif