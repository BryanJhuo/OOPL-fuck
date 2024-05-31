#include "stdafx.h"
#include "../Game/watergirl.h"

const int VK_S = 0x53; // left (key S)
const int VK_D = 0x46; // right (key F)
const int VK_W = 0x45; // up (key E)

void Watergirl::IsMoving(Map &map, Object::MapPole& pole, int page) {
	if (this->IsDButtonClick && this->isBumpRightWall(map, pole, page))
		this->moveRight();
	if (this->IsAButtonClick && this->isBumpLeftWall(map, pole, page))
		this->moveLeft();
	if (this->IsWButtonClick && this->isBumpHead(map, pole, page)) {
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

bool Watergirl::isBumpHead(Map& map, Object::MapPole& pole, int page) {
	int current_X = this->character.GetLeft();
	int current_Y = this->character.GetTop();
	// 向上
	bool check_1 = map.getPlaceName((current_X + 27) / 35, current_Y / 35, page) == "Resources/block/block_1.bmp";
	// 向左
	bool check_3 = map.getPlaceName(current_X / 35, current_Y / 35 + 1, page) == "Resources/block/block_1.bmp";
	// 向右
	bool check_4 = map.getPlaceName((current_X + this->character.GetWidth()) / 35, current_Y / 35 + 1, page) == "Resources/block/block_1.bmp";
	bool check_2 = false;
	if (page == 1) {
		for (int i = 0; i < 2; i++) {
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

	if (check_1 || check_2 || check_3 || check_4){
		this->IsWButtonClick = false;
		return false;
	}
	return true;
}

bool Watergirl::isBumpRightWall(Map& map, Object::MapPole& pole, int page) {
	int current_X = this->character.GetLeft() + this->character.GetWidth();
	int current_Y = this->character.GetTop();
	/*if (map.getPlaceName(current_X / 35, (current_Y + 35) / 35) == "Resources/block/block_1.bmp")
		return false;
	else */
	if (map.getPlaceName(current_X / 35, (current_Y + 70) / 35, page) == "Resources/block/block_1.bmp")
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
				&& this->character.GetLeft() < pole.mapPole[i].GetLeft())
				return false;
		}
	}
	if (page == 5) {
		for (int i = 4; i < 17; i++) {
			if (i == 10 || i == 11) continue;
			if (CMovingBitmap::IsOverlap(this->character, pole.mapPole[i])
				&& this->character.GetLeft() < pole.mapPole[i].GetLeft())
				return false;
		}
	}
	return true;
}

bool Watergirl::isBumpLeftWall(Map& map, Object::MapPole& pole, int page) {
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
				&& (this->character.GetTop() + this->character.GetHeight()) > (pole.mapPole[i].GetTop() + (pole.mapPole[i].GetHeight() / 2)))
				return false;
		}
	}
	if (page == 3) {
		for (int i = 1; i < 12; i++) {
			if (i == 5 || i == 9) continue;
			if (CMovingBitmap::IsOverlap(this->character, pole.mapPole[i])
				&& this->character.GetLeft() > pole.mapPole[i].GetLeft())
				return false;
		}
	}
	if (page == 5) {
		for (int i = 4; i < 17; i++) {
			if (i == 10 || i == 11) continue;
			if (CMovingBitmap::IsOverlap(this->character, pole.mapPole[i])
				&& this->character.GetLeft() > pole.mapPole[i].GetLeft())
				return false;
		}
	}
	return true;
}

void Watergirl::resetMap(int map_stage) {
	if (map_stage == 1) // level 1
		this->character.SetTopLeft(38, 737);
	if (map_stage == 2) // level 2
		this->character.SetTopLeft(35, 455);
	if (map_stage == 3) // level 3
		this->character.SetTopLeft(1050, 735);
	if (map_stage == 4) // level 4
		this->character.SetTopLeft(1295, 875);
	if (map_stage == 5) // level 5
		this->character.SetTopLeft(1155, 35);
}

void Watergirl::SetFrame() {
	if (this->IsAButtonClick) {
		this->character.SetFrameIndexOfBitmap(this->frame % 5 + 5);
	}
	else if (this->IsDButtonClick) {
		this->character.SetFrameIndexOfBitmap(this->frame % 5 + 10);
	}
	else {
		this->character.SetFrameIndexOfBitmap(this->frame % 5);
	}
	this->frame += 1;
}