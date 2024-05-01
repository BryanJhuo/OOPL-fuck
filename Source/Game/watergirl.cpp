#include "stdafx.h"
#include "../Game/watergirl.h"

const int VK_S = 0x53; // left (key S)
const int VK_D = 0x46; // right (key F)
const int VK_W = 0x45; // up (key E)

void Watergirl::IsMoving(Map &map, Object::MapPole& pole) {
	if (this->IsDButtonClick && this->isBumpRightWall(map))
		this->moveRight();
	if (this->IsAButtonClick && this->isBumpLeftWall(map))
		this->moveLeft();
	if (this->IsWButtonClick && this->isBumpHead(map, pole)) {
		if (this->IsTimesUp())
			this->IsWButtonClick = false;
		else{
			if (this->IsDButtonClick) // right
				this->moveJumpUp(1);
			else if (this->IsAButtonClick) // left
				this->moveJumpUp(2);
			else
				this->moveJumpUp(0);
		}
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
		if (!this->IsTimesUp()) {
			this->IsWButtonClick = false;
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
	if (std::chrono::duration_cast<time_type>(clock_type::now() - start).count() < 700)
		return false;
	else
		return true;
}

bool Watergirl::isBumpHead(Map& map, Object::MapPole& pole) {
	int current_X = this->character.GetLeft();
	int current_Y = this->character.GetTop();
	if (map.getPlaceName(current_X / 35, current_Y / 35) == "Resources/block/block_1.bmp") {
		this->IsWButtonClick = false;
		return false;
	}
	return true;
}

bool Watergirl::isBumpRightWall(Map& map) {
	int current_X = this->character.GetLeft() + this->character.GetWidth();
	int current_Y = this->character.GetTop();
	/*if (map.getPlaceName(current_X / 35, (current_Y + 35) / 35) == "Resources/block/block_1.bmp")
		return false;
	else */if (map.getPlaceName(current_X / 35, (current_Y + 70) / 35) == "Resources/block/block_1.bmp")
	return false;
	return true;
}

bool Watergirl::isBumpLeftWall(Map& map) {
	int current_X = this->character.GetLeft();
	int current_Y = this->character.GetTop();
	/*if (map.getPlaceName(current_X / 35, (current_Y + 35) / 35) == "Resources/block/block_1.bmp")
		return false;
	else */if (map.getPlaceName(current_X / 35, (current_Y + 70) / 35) == "Resources/block/block_1.bmp")
		return false;
	return true;
}

void Watergirl::resetMap(int map_stage) {
	if (map_stage == 1)
		this->character.SetTopLeft(38, 737);
}