#pragma once

#ifndef MYCOMBOBOX_H
#define MYCOMBOBOX_H
#include <memory>

class ComboBox {
private:
	// coordinate of TopLeft and BottomRight
	int x_min, y_min, x_max, y_max;
	// the combo box of height and width
	int height, width;

public:
	ComboBox(int x, int y, int h, int w);
	bool IsOverlap(ComboBox b);
	bool IsOverlap(ComboBox a, ComboBox b);
	void moveShape(std::shared_ptr<int> pic_x, std::shared_ptr<int> pic_y);
};

#endif // !MYCOMBOBOX_H
