#include "stdafx.h"
#include "../Game/fireman.h"

void Fireman::IsMoving(){
	if (this->IsRightButtonClick)
		this->moveRight();
	if (this->IsLeftButtonClick)
		this->moveLeft();
	if (this->IsUpButtonClick && this->IsRightButtonClick) {
		if (this->jumpHeight <= 3) {
			this->moveRightJumpUp();
			this->jumpHeight++;
		}
		else if (this->jumpHeight >= 4 && this->jumpHeight <= 7) {
			this->moveRightJumpDown();
			this->jumpHeight++;
		}
		Sleep(25);
	}
	if (this->IsUpButtonClick && this->IsLeftButtonClick) {
		if (this->jumpHeight <= 3) {
			this->moveLeftJumpUp();
			this->jumpHeight++;
		}
		else if (this->jumpHeight >= 4 && this->jumpHeight <= 7) {
			this->moveLeftJumpDown();
			this->jumpHeight++;
		}
		Sleep(25);
	}
}

void Fireman::IsButtonDown(UINT nChar) {
	switch (nChar)
	{
	case VK_RIGHT:
		this->IsRightButtonClick = true;
		break;
	case VK_LEFT:
		this->IsLeftButtonClick = true;
		break;
	case VK_UP:
		this->IsUpButtonClick = true;
		break;
	}
}

void Fireman::IsButtonUp(UINT nChar) {
	switch (nChar)
	{
	case VK_RIGHT:
		this->IsRightButtonClick = false;
		break;
	case VK_LEFT:
		this->IsLeftButtonClick = false;
		break;
	case VK_UP:
		this->IsUpButtonClick = false;
		this->jumpHeight = 0;
		break;
	}
}