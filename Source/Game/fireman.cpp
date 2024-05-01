#include "stdafx.h"
#include "../Game/fireman.h"

void Fireman::IsMoving(Map &map, Object::MapPole& pole){
	if (this->IsRightButtonClick && this->isBumpRightWall(map))
		this->moveRight();
	if (this->IsLeftButtonClick && this->isBumpLeftWall(map))
		this->moveLeft();
	if (this->IsUpButtonClick && this->isBumpHead(map, pole)) {
		if (this->IsTimesUp())
			this->IsUpButtonClick = false;
		else{
			if (this->IsRightButtonClick)
				this->moveJumpUp(1);
			else if (this->IsLeftButtonClick)
				this->moveJumpUp(2);
			else
				this->moveJumpUp(0);
		}
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
	if (std::chrono::duration_cast<time_type>(clock_type::now() - start).count() < 700)
		return false;
	else
		return true;
}

bool Fireman::isBumpHead(Map &map, Object::MapPole &pole) {
	int current_X = this->character.GetLeft();
	int current_Y = this->character.GetTop();
	bool check_1 = map.getPlaceName(current_X / 35, current_Y / 35) == "Resources/block/block_1.bmp";
	bool check_2 = false;
	for (int i = 0; i < 2; i++){
		if (CMovingBitmap::IsOverlap(this->character, pole.mapPole[i]) 
			&& this->character.GetTop() > pole.mapPole[i].GetTop()) 
			check_2 = true; 
	}
		
	if (check_1 || check_2){
		this->IsUpButtonClick = false;
		return false;
	}
	return true;
}

bool Fireman::isBumpRightWall(Map &map) {
	int current_X = this->character.GetLeft() + this->character.GetWidth();
	int current_Y = this->character.GetTop();
	/*if (map.getPlaceName(current_X / 35, (current_Y + 35) / 35) == "Resources/block/block_1.bmp")
		return false;
	else */if (map.getPlaceName(current_X  / 35, (current_Y + 70) / 35) == "Resources/block/block_1.bmp")
		return false;
	return true;
}

bool Fireman::isBumpLeftWall(Map &map) {
	int current_X = this->character.GetLeft();
	int current_Y = this->character.GetTop();
	/*if (map.getPlaceName(current_X / 35, (current_Y + 35) / 35) == "Resources/block/block_1.bmp")
		return false;
	else */if (map.getPlaceName(current_X / 35, (current_Y + 70) / 35) == "Resources/block/block_1.bmp")
		return false;
	return true;
}

void Fireman::resetMap(int map_stage) {
	if (map_stage == 1)
		this->character.SetTopLeft(38, 877);
}