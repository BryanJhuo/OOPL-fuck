#include "stdafx.h"
#include "../Game/mapBox.h"

void MapBox::generateObject() {
	mapBox[0].LoadBitmap({ "Resources/object/box.bmp"}, RGB(0, 255, 0));
	mapBox[0].SetTopLeft(810, 260);
}

void MapBox::showObject(int map_stage) {
	switch (map_stage) {
	case 1: {
		mapBox[0].ShowBitmap();

	}

	}
}