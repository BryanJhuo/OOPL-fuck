#include "stdafx.h"
#include "../Game/fireman.h"

void Fireman::IsMoving(Map &map, Object::MapPole& pole, int page){
	if (this->IsRightButtonClick && this->isBumpRightWall(map, pole, page))
		this->moveRight();
	if (this->IsLeftButtonClick && this->isBumpLeftWall(map, pole, page))
		this->moveLeft();
	if (this->IsUpButtonClick && this->isBumpHead(map, pole, page)) {
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

bool Fireman::isBumpHead(Map &map, Object::MapPole &pole, int page) {
	int current_X = this->character.GetLeft();
	int current_Y = this->character.GetTop();
	bool check_1 = map.getPlaceName((current_X + 27) / 35, current_Y / 35, page) == "Resources/block/block_1.bmp";
	bool check_2 = false;
	if (page == 1){
		for (int i = 0; i < 2; i++){
			if (CMovingBitmap::IsOverlap(this->character, pole.mapPole[i]) 
				&& this->character.GetTop() > pole.mapPole[i].GetTop()) 
				check_2 = true; 
		}
	}
	if (page == 3) {
		for (int i = 1; i < 12; i++) {
			if (i == 5 || i == 9) continue;
			if (CMovingBitmap::IsOverlap(this->character, pole.mapPole[i])
				&& this->character.GetTop() > pole.mapPole[i].GetTop())
				check_2 = true;
		}
	}
	if (page == 5) {
		for (int i = 4; i < 17; i++) {
			if (i == 10 || i == 11) continue;
			if (CMovingBitmap::IsOverlap(this->character, pole.mapPole[i])
				&& this->character.GetTop() > pole.mapPole[i].GetTop())
				check_2 = true;
		}
	}
		
	if (check_1 || check_2){
		this->IsUpButtonClick = false;
		return false;
	}
	return true;
}

bool Fireman::isBumpRightWall(Map &map, Object::MapPole& pole, int page) {
	int current_X = this->character.GetLeft() + this->character.GetWidth();
	int current_Y = this->character.GetTop();
	/*if (map.getPlaceName(current_X / 35, (current_Y + 35) / 35) == "Resources/block/block_1.bmp")
		return false;
	else */
	if (map.getPlaceName(current_X  / 35, (current_Y + 70) / 35, page) == "Resources/block/block_1.bmp")
		return false;
	if (page == 1) {
		for (int i = 0; i < 2; i++) {
			if (CMovingBitmap::IsOverlap(this->character, pole.mapPole[i])
				&& this->character.GetLeft() < pole.mapPole[i].GetLeft()
				&& (this->character.GetTop() + this->character.GetHeight()) > (pole.mapPole[i].GetTop() + (pole.mapPole[i].GetHeight() / 2)))
				return false;
		}
	}
	if (page == 3) {
		for (int i = 1; i < 12; i++) {
			if (i == 5 || i == 9) continue;
			if (CMovingBitmap::IsOverlap(this->character, pole.mapPole[i])
				&& this->character.GetLeft() < pole.mapPole[i].GetLeft()
				&& (this->character.GetTop() + this->character.GetHeight()) > (pole.mapPole[i].GetTop() + (pole.mapPole[i].GetHeight() / 2)))
				return false;
		}
	}
	if (page == 5) {
		for (int i = 4; i < 17; i++) {
			if (i == 10 || i == 11) continue;
			if (CMovingBitmap::IsOverlap(this->character, pole.mapPole[i])
				&& this->character.GetLeft() < pole.mapPole[i].GetLeft()
				&& (this->character.GetTop() + this->character.GetHeight()) > (pole.mapPole[i].GetTop() + (pole.mapPole[i].GetHeight() / 2)))
				return false;
		}
	}
	return true;
}

bool Fireman::isBumpLeftWall(Map &map, Object::MapPole& pole, int page) {
	int current_X = this->character.GetLeft();
	int current_Y = this->character.GetTop();
	/*if (map.getPlaceName(current_X / 35, (current_Y + 35) / 35) == "Resources/block/block_1.bmp")
		return false;
	else */
	if (map.getPlaceName(current_X / 35, (current_Y + 70) / 35, page) == "Resources/block/block_1.bmp")
		return false;
	if (page == 1) {
		for (int i = 0; i < 2; i++) {
			if (CMovingBitmap::IsOverlap(this->character, pole.mapPole[i]) 
				&& this->character.GetLeft() > pole.mapPole[i].GetLeft() 
				&& (this->character.GetTop() + this->character.GetHeight()) > (pole.mapPole[i].GetTop() + (pole.mapPole[i].GetHeight()/ 2)))
				return false;
		}
	}
	if (page == 3) {
		for (int i = 1; i < 12; i++) {
			if (i == 5 || i == 9) continue;
			if (CMovingBitmap::IsOverlap(this->character, pole.mapPole[i])
				&& this->character.GetLeft() > pole.mapPole[i].GetLeft()
				&& (this->character.GetTop() + this->character.GetHeight()) > (pole.mapPole[i].GetTop() + (pole.mapPole[i].GetHeight() / 2)))
				return false;
		}
	}
	if (page == 5) {
		for (int i = 4; i < 17; i++) {
			if (i == 10 || i == 11) continue;
			if (CMovingBitmap::IsOverlap(this->character, pole.mapPole[i])
				&& this->character.GetLeft() > pole.mapPole[i].GetLeft()
				&& (this->character.GetTop() + this->character.GetHeight()) > (pole.mapPole[i].GetTop() + (pole.mapPole[i].GetHeight() / 2)))
				return false;
		}
	}
	return true;
}

void Fireman::resetMap(int map_stage) {
	if (map_stage == 1) // level 1
		this->character.SetTopLeft(38, 877);
	if (map_stage == 2) // level 2
		this->character.SetTopLeft(1260, 70);
	if (map_stage == 3) // level 3
		this->character.SetTopLeft(910, 735);
	if (map_stage == 4) // level 4
		this->character.SetTopLeft(38, 877);
	if (map_stage == 5) // levle 5
		this->character.SetTopLeft(38, 877);
}