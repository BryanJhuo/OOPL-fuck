#include "stdafx.h"
#include "../Game/watergirl.h"

const int VK_S = 0x53;
const int VK_D = 0x44;
const int VK_W = 0x57;

void Watergirl::IsMoving() {
	if (this->IsDButtonClick)
		this->moveRight();
	if (this->IsAButtonClick)
		this->moveLeft();
	if (this->IsWButtonClick) {
		if (Watergirl::IsTimesUp())
			this->IsWButtonClick = false;
		else
			this->moveJumpUp();
	}
	Watergirl::IsDropDown();
}

void Watergirl::IsButtonUp(UINT nChar) {
	switch (nChar)
	{
	case VK_D:
		this->IsDButtonClick = false;
		break;
	case VK_S:
		this->IsAButtonClick = false;
		break;
	case VK_W:
		if (!Watergirl::IsTimesUp()) {
			this->IsWButtonClick = false;
			Watergirl::IsDropDown();
		}
		break;
	}
}

void Watergirl::IsButtonDown(UINT nChar) {
	switch (nChar)
	{
	case VK_D:
		this->IsDButtonClick = true;
		break;
	case VK_S:
		this->IsAButtonClick = true;
		break;
	case VK_W:
		this->IsWButtonClick = true;
		this->start = clock_type::now();
		break;
	}
}

bool Watergirl::IsTimesUp() {
	if (std::chrono::duration_cast<time_type>(clock_type::now() - this->start).count() < 400)
		return false;
	else
		return true;
}

void Watergirl::IsDropDown() {
	if (this->character.GetTop() + this->character.GetHeight() < 975 && !this->IsWButtonClick)
		this->moveJumpDown();
}