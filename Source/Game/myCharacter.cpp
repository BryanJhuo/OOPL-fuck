#include "StdAfx.h"
#include "../Game/myCharacter.h"


void Character::moveRight() {
	character.SetTopLeft(character.GetLeft() + 5, character.GetTop());
}
void Character::moveLeft(){
	character.SetTopLeft(character.GetLeft() - 5, character.GetTop());
}

void Character::moveRightJumpUp() {
	character.SetTopLeft(character.GetLeft() + 5, character.GetTop() - 14);
}

void Character::moveRightJumpDown() {
	character.SetTopLeft(character.GetLeft() + 5, character.GetTop() + 14);
}

void Character::moveLeftJumpUp() {
	character.SetTopLeft(character.GetLeft() - 5, character.GetTop() - 14);
}

void Character::moveLeftJumpDown() {
	character.SetTopLeft(character.GetLeft() - 5, character.GetTop() + 14);
}

void Character::IsMoving() {
	/*
	if (this->IsRightButtonClick)
		this->moveRight();
	if (this->IsLeftButtonClick)
		this->moveLeft();
	if (this->IsUpButtonClick && this->IsRightButtonClick) {
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
	if (this->IsUpButtonClick && this->IsLeftButtonClick) {
		if (this->jumpHeight <= 3) {
			this->moveLeftJumpUp();
			this->jumpHeight++;
		}
		else if (this->jumpHeight >= 4 && this->jumpHeight <= 7) {
			this->moveLeftJumpDown();
			this->jumpHeight++;
		}
		Sleep(25);
	}*/
}

void Character::IsButtonUp(UINT nChar) {}

void Character::IsButtonDown(UINT nChar) {}