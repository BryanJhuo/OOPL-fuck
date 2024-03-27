#include "stdafx.h"
#include "../Game/myComboBox.h"

ComboBox::ComboBox(int x, int y, int h, int w) {
	this->x_min = x;
	this->y_min = y;
	this->x_max = w + x;
	this->y_max = h + y;
	this->height = h;
	this->width = w;
}

bool ComboBox::IsOverlap(ComboBox box2) {
	bool overlapX = this->x_min <= box2.x_max && this->x_max >= box2.x_min;
	bool overlapY = this->y_min <= box2.y_max && this->y_max >= box2.y_min;
	return overlapX && overlapY;
}

bool ComboBox::IsOverlap(ComboBox box1, ComboBox box2) {
	bool overlapX = box1.x_min <= box2.x_max && box1.x_max >= box2.x_min;
	bool overlapY = box1.y_min <= box2.y_max && box1.y_max >= box2.y_min;
	return overlapX && overlapY;
}

void ComboBox::moveShape(std::shared_ptr<int> pic_x, std::shared_ptr<int> pic_y) {
	this->x_min = *pic_x;
	this->y_min = *pic_y;
	this->x_max = *pic_x + this->width;
	this->y_max = *pic_y + this->height;
}