#include "stdafx.h"
#include "../Game/fireman.h"

void Fireman::IsMoving(){
	if (this->IsRightButtonClick)
		this->moveRight();
	if (this->IsLeftButtonClick)
		this->moveLeft();
	if (this->IsUpButtonClick) {
		if (Fireman::IsTimesUp()) {
			this->IsUpButtonClick = false;
		}
		else
			this->moveJumpUp();
	}
	// Drop down
	Fireman::IsDropDown();
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
		this->start = clock_type::now();
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
		if (!Fireman::IsTimesUp()){
			this->IsUpButtonClick = false;
			Fireman::IsDropDown();
		}
		break;
	}
}

bool Fireman::IsTimesUp(){
	if (std::chrono::duration_cast<time_type>(clock_type::now() - this->start).count() < 400)
		return false;
	else
		return true;
}

void Fireman::IsDropDown() {
	if (this->character.GetTop() + this->character.GetHeight() < 975 && !this->IsUpButtonClick)
		this->moveJumpDown();
}