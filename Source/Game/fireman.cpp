#include "stdafx.h"
#include "../Game/fireman.h"

void Fireman::IsMoving(Map map){
	if (this->IsRightButtonClick && this->isBumpRightWall(map))
		this->moveRight();
	if (this->IsLeftButtonClick && this->isBumpLeftWall(map))
		this->moveLeft();
	if (this->IsUpButtonClick && this->isBumpHead(map)) {
		if (this->IsTimesUp())
			this->IsUpButtonClick = false;
		else
			this->moveJumpUp();
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
		if (!this->IsTimesUp()) {
			this->IsUpButtonClick = false;
		}
		break;
	}
}

bool Fireman::IsTimesUp() {
	if (std::chrono::duration_cast<time_type>(clock_type::now() - start).count() < 1000)
		return false;
	else
		return true;
}

bool Fireman::isBumpHead(Map map) {
	int current_X = this->character.GetLeft();
	int current_Y = this->character.GetTop();
	if (map.getPlaceName(current_X / 35, current_Y / 35) == "Resources/block/block_1.bmp"){
		this->IsUpButtonClick = false;
		return false;
	}
	return true;
}

bool Fireman::isBumpRightWall(Map map) {
	int current_X = this->character.GetLeft() + this->character.GetWidth();
	int current_Y = this->character.GetTop();
	if (map.getPlaceName(current_X / 35, (current_Y + 35) / 35) == "Resources/block/block_1.bmp")
		return false;
	else if (map.getPlaceName(current_X / 35, (current_Y + 70) / 35) == "Resources/block/block_1.bmp")
		return false;
	return true;
}

bool Fireman::isBumpLeftWall(Map map) {
	int current_X = this->character.GetLeft();
	int current_Y = this->character.GetTop();
	if (map.getPlaceName(current_X / 35, (current_Y + 35) / 35) == "Resources/block/block_1.bmp")
		return false;
	else if (map.getPlaceName(current_X / 35, (current_Y + 70) / 35) == "Resources/block/block_1.bmp")
		return false;
	return true;
}