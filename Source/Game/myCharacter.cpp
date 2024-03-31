#include "StdAfx.h"
#include "../Game/myCharacter.h"


void Character::moveRight() {
	this->character.SetTopLeft(this->character.GetLeft() + 5, this->character.GetTop());
}
void Character::moveLeft(){
	this->character.SetTopLeft(this->character.GetLeft() - 5, this->character.GetTop());
}
void Character::moveJumpUp() {
	this->character.SetTopLeft(this->character.GetLeft() , this->character.GetTop() - 5);
}
void Character::moveJumpDown() {
	this->character.SetTopLeft(this->character.GetLeft(), this->character.GetTop() + 9);
}


void Character::IsMoving() {}

void Character::IsButtonUp(UINT nChar) {}

void Character::IsButtonDown(UINT nChar) {}