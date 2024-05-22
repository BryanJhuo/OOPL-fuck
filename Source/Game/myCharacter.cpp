#include "StdAfx.h"
#include "../Game/myCharacter.h"


void Character::moveRight() {
	this->character.SetTopLeft(this->character.GetLeft() + 7, this->character.GetTop());
}
void Character::moveLeft(){
	this->character.SetTopLeft(this->character.GetLeft() - 7, this->character.GetTop());
}
void Character::moveJumpUp(int buttonState) {
	if (buttonState == 0) // up
		this->character.SetTopLeft(this->character.GetLeft(), this->character.GetTop() - 4);
	if (buttonState == 1) // right 
		this->character.SetTopLeft(this->character.GetLeft() + 3, this->character.GetTop() - 4);
	if (buttonState == 2) // left
		this->character.SetTopLeft(this->character.GetLeft() - 3, this->character.GetTop() - 4);
}
void Character::moveJumpDown() {
	this->character.SetTopLeft(this->character.GetLeft(), this->character.GetTop() + 9);
}

void Character::isDropDown(Map &map, Object::MapPole &pole, Object::MapBox& box, int page) {
	int current_X = this->character.GetLeft();
	int current_Y = this->character.GetTop() + this->character.GetHeight();

	int distance = this->findClosePlace(map, (current_X + 27) / 35, current_Y / 35, current_Y, page);
	// the pole collision
	if (page == 1) {
		for (int i = 0; i < 2; i++) {
			if (game_framework::CMovingBitmap::IsOverlap(this->character, pole.mapPole[i])
				&& this->character.GetTop() < pole.mapPole[i].GetTop())
				distance = pole.mapPole[i].GetTop();
		}
		if (game_framework::CMovingBitmap::IsOverlap(this->character, box.mapBox)
			&& this->character.GetTop() < box.mapBox.GetTop())
			distance = box.mapBox.GetTop();
	}
	if (page == 3) {
		for (int i = 1; i < 12; i++) {
			if (i == 5 || i == 9) continue;
			if (game_framework::CMovingBitmap::IsOverlap(this->character, pole.mapPole[i])
				&& this->character.GetTop() < pole.mapPole[i].GetTop())
				distance = pole.mapPole[i].GetTop();
		}
	}
	if (page == 5) {
		for (int i = 4; i < 17; i++) {
			if (i == 10 || i == 11) continue;
			if (game_framework::CMovingBitmap::IsOverlap(this->character, pole.mapPole[i])
				&& this->character.GetTop() < pole.mapPole[i].GetTop())
				distance = pole.mapPole[i].GetTop();
		}
	}

	// drop down to the distance
	if (current_Y < distance)
		this->moveJumpDown();
}

int Character::findClosePlace(Map &map, int x, int y, int height, int page) {
	int ret = height + 3;
	std::string placeName = map.getPlaceName(x, y, page);
	if (placeName == "Resources/block/block_1.bmp")
		ret = map.getPlace_Y(x, y, page);

	return ret;
}


void Character::IsMoving(Map &map, Object::MapPole& pole, int page) {}

void Character::IsButtonUp(UINT nChar) {}

void Character::IsButtonDown(UINT nChar) {}

void Character::resetMap(int map_stage) {}