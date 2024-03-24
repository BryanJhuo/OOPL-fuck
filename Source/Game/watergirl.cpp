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
	if (this->IsWButtonClick && this->IsDButtonClick) {
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
	if (this->IsWButtonClick && this->IsAButtonClick) {
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
		this->IsWButtonClick = false;
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
		this->jumpHeight = 0;
		break;
	}
}