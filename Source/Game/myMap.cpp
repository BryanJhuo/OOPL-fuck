#include "stdafx.h"
#include "../Game/myMap.h"
#include <fstream>

void Map::generateMap() {
	std::ifstream map1("Resources/mapContent/map1Basic.txt");
	for (int i = 0; i < 29; i++) {
		for (int j = 0; j < 40; j++) {
			map1 >> this->map[i][j];
			if (this->map[i][j] == 0)
				this->mapResource1[i][j].LoadBitmapByString({ "Resources/block/block_0.bmp" });
			else
				this->mapResource1[i][j].LoadBitmapByString({ "Resources/block/block_1.bmp" });
			this->mapResource1[i][j].SetTopLeft(j * 35, i * 35);
		}
	}
	map1.close();

	std::ifstream map2("Resources/mapContent/map2Basic.txt");
	for (int i = 0; i < 29; i++) {
		for (int j = 0; j < 40; j++) {
			map2 >> this->map[i][j];
			if (this->map[i][j] == 0)
				this->mapResource2[i][j].LoadBitmapByString({ "Resources/block/block_0.bmp" });
			else
				this->mapResource2[i][j].LoadBitmapByString({ "Resources/block/block_1.bmp" });
			this->mapResource2[i][j].SetTopLeft(j * 35, i * 35);
		}
	}
	map2.close();

	std::ifstream map3("Resources/mapContent/map3Basic.txt");
	for (int i = 0; i < 29; i++) {
		for (int j = 0; j < 40; j++) {
			map3 >> this->map[i][j];
			if (this->map[i][j] == 0)
				this->mapResource3[i][j].LoadBitmapByString({ "Resources/block/block_0.bmp" });
			else
				this->mapResource3[i][j].LoadBitmapByString({ "Resources/block/block_1.bmp" });
			this->mapResource3[i][j].SetTopLeft(j * 35, i * 35);
		}
	}
	map3.close();

	std::ifstream map4("Resources/mapContent/map4Basic.txt");
	for (int i = 0; i < 29; i++) {
		for (int j = 0; j < 40; j++) {
			map4 >> this->map[i][j];
			if (this->map[i][j] == 0)
				this->mapResource4[i][j].LoadBitmapByString({ "Resources/block/block_0.bmp" });
			else
				this->mapResource4[i][j].LoadBitmapByString({ "Resources/block/block_1.bmp" });
			this->mapResource4[i][j].SetTopLeft(j * 35, i * 35);
		}
	}
	map4.close();

	std::ifstream map5("Resources/mapContent/map5Basic.txt");
	for (int i = 0; i < 29; i++) {
		for (int j = 0; j < 40; j++) {
			map5 >> this->map[i][j];
			if (this->map[i][j] == 0)
				this->mapResource5[i][j].LoadBitmapByString({ "Resources/block/block_0.bmp" });
			else
				this->mapResource5[i][j].LoadBitmapByString({ "Resources/block/block_1.bmp" });
			this->mapResource5[i][j].SetTopLeft(j * 35, i * 35);
		}
	}
	map5.close();

}

void Map::showMap(int map_stage) {
	

	switch (map_stage) {
		case 1: {
			for (int i = 0; i < 29; i++) {
				for (int j = 0; j < 40; j++) {
					this->mapResource1[i][j].ShowBitmap();
				}
			}
			break;
		}

		case 2: {
			for (int i = 0; i < 29; i++) {
				for (int j = 0; j < 40; j++) {
					this->mapResource2[i][j].ShowBitmap();
				}
			}
			break;
		}

		case 3: {
			for (int i = 0; i < 29; i++) {
				for (int j = 0; j < 40; j++) {
					this->mapResource3[i][j].ShowBitmap();
				}
			}
			break;
		}

		case 4: {
			for (int i = 0; i < 29; i++) {
				for (int j = 0; j < 40; j++) {
					this->mapResource4[i][j].ShowBitmap();
				}
			}
			break;
		}

		case 5: {
			for (int i = 0; i < 29; i++) {
				for (int j = 0; j < 40; j++) {
					this->mapResource5[i][j].ShowBitmap();
				}
			}
			break;
		}

	}
}

std::string Map::getPlaceName(int x, int y) {
	return this->mapResource1[y][x].GetImageFileName();
}

int Map::getPlace_X(int x, int y) {
	return this->mapResource1[y][x].GetLeft();
}

int Map::getPlace_Y(int x, int y) {
	return this->mapResource1[y][x].GetTop();
}

/*

Sol1:
//OnShow//
generateMap(int map_stage) {switch case複寫map[29][40]}
showMap()
Good/Bad:只需產生一組mapResource再隨map_stage覆蓋即可	/	一直重複讀取地圖

Sol2:
//OnInit//
generateMap1()
generateMap2()
generateMap3()
generateMap4()
generateMap5()

//OnShow//
showMap(map_stage)
Good/Bad:不用一直重複讀取地圖,依據map_stage選擇要生成的地圖/	一開始需先Init5個map[29][40]

*/