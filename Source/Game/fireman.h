#pragma once

#ifndef FIREMAN_H
#define FIREMAN_H
#include "../Game/myCharacter.h"

class Fireman : public Character {
public:
	bool IsRightButtonClick = false;
	bool IsLeftButtonClick = false;
	bool IsUpButtonClick = false;

	void IsMoving();
	void IsButtonUp(UINT);
	void IsButtonDown(UINT);
};

#endif