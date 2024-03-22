#include "StdAfx.h"
#include "../Game/myCharacter.h"


void Character::moveRight() {
	character.SetTopLeft(character.GetLeft() + 5, character.GetTop());
}
void Character::moveLeft(){
	character.SetTopLeft(character.GetLeft() - 5, character.GetTop());
}

void Character::moveJumpUp() {
	character.SetTopLeft(character.GetLeft(), character.GetTop() - 5);
}

void Character::moveJumpDown() {
	character.SetTopLeft(character.GetLeft() , character.GetTop() + 7);
}

void Character::IsMoving() {}

void Character::IsButtonUp(UINT nChar) {}

void Character::IsButtonDown(UINT nChar) {}