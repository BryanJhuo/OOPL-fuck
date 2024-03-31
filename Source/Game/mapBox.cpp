#include "stdafx.h"
#include "../Game/mapBox.h"

void MapBox::generateObject() {
	mapBox.LoadBitmap({ "Resources/object/box.bmp"}, RGB(0, 255, 0));
	mapBox.SetTopLeft(810, 260);
}

void MapBox::showObject(int map_stage) {
	switch (map_stage) {
	case 1: {
		mapBox.ShowBitmap();

	}

	}
}