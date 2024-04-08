#include "StdAfx.h"
#include "../Game/myCharacter.h"


void Character::moveRight() {
	this->character.SetTopLeft(this->character.GetLeft() + 7, this->character.GetTop());
}
void Character::moveLeft(){
	this->character.SetTopLeft(this->character.GetLeft() - 7, this->character.GetTop());
}
void Character::moveJumpUp() {
	this->character.SetTopLeft(this->character.GetLeft() , this->character.GetTop() - 6);
}
void Character::moveJumpDown() {
	this->character.SetTopLeft(this->character.GetLeft(), this->character.GetTop() + 9);
}

void Character::isDropDown(Map map) {
	int current_X = this->character.GetLeft();
	int current_Y = this->character.GetTop() + this->character.GetHeight();
	int distance = this->findClosePlace(map, current_X / 35, current_Y / 35, current_Y);
	if (current_Y < distance)
		this->moveJumpDown();
}

int Character::findClosePlace(Map map, int x, int y, int height) {
	int ret = height + 3;
	std::string placeName = map.getPlaceName(x, y);
	if (placeName == "Resources/block/block_1.bmp")
		ret = map.getPlace_Y(x, y);
	
	return ret;
}



void Character::IsMoving(Map map) {}

void Character::IsButtonUp(UINT nChar) {}

void Character::IsButtonDown(UINT nChar) {}