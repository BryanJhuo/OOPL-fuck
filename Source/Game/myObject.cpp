#include "stdafx.h"
#include "../Game/myObject.h"

void Object::Object::generateObject(){ }

void Object::Object::showObject(int map_stage){ }

void Object::Object::resetMap(int map_stage){ }

bool Object::Object::is_Overlap(CMovingBitmap character, CMovingBitmap object) {
    return CMovingBitmap::IsOverlap(character, object);
}

void Object::MapBox::generateObject() {
    mapBox.LoadBitmapByString({ "Resources/object/box.bmp" }, RGB(0, 255, 0));
    mapBox.SetTopLeft(810, 293);
}

void Object::MapBox::showObject(int map_stage) {
    if (map_stage == 1) {
        mapBox.ShowBitmap();
    }
}

void Object::MapBox::dropDown(Map &map) {
    int current_X = this->mapBox.GetLeft();
    int current_Y = this->mapBox.GetTop() + this->mapBox.GetHeight();
    int distance = this->mapBox.GetTop() + this->mapBox.GetHeight() + 3;

    std::string placeName = map.getPlaceName(current_X / 35, current_Y / 35);
    if (placeName == "Resources/block/block_1.bmp")
        distance = map.getPlace_Y(current_X / 35, current_Y / 35);

    if (current_Y < distance)
        this->mapBox.SetTopLeft(this->mapBox.GetLeft(), this->mapBox.GetTop() + 7);
}

void Object::MapBox::movingBox(int mode) {
    if (mode == 1 && this->mapBox.GetLeft() > 210) // moving left side
        this->mapBox.SetTopLeft(this->mapBox.GetLeft() - 7, this->mapBox.GetTop());
    if (mode == 2 && this->mapBox.GetLeft() < 735) // moving right side
        this->mapBox.SetTopLeft(this->mapBox.GetLeft() + 7, this->mapBox.GetTop());
}

void Object::MapBox::resetMap(int map_stage) {
    if (map_stage == 1) {
        this->mapBox.SetTopLeft(810, 293);
    }
}

void Object::MapButton::generateObject() {
    for (int i = 0; i < 2; i++) {
        mapButton[i].LoadBitmapByString({ "Resources/object/button_purple_1.bmp", "Resources/object/button_purple_3.bmp" }, RGB(0, 255, 0));
    }
    mapButton[2].LoadBitmapByString({ "Resources/object/button_blue_1.bmp", "Resources/object/button_blue_3.bmp" }, RGB(0, 255, 0));
    mapButton[3].LoadBitmapByString({ "Resources/object/button_red_1.bmp", "Resources/object/button_red_3.bmp" }, RGB(0, 255, 0));

    for (int i = 0; i < 4; i++) {
        mapButton[i].SetTopLeft(0, 0);
        buttonState[i] = false;
    }
}

void Object::MapButton::showObject(int map_stage) {
    switch (map_stage) {
    case 1: {
        mapButton[0].SetTopLeft(350, 490);
        mapButton[1].SetTopLeft(1090, 350);
        mapButton[0].ShowBitmap();
        mapButton[1].ShowBitmap();
        break;
    }

    case 3: {
        mapButton[2].SetTopLeft(70, 665);
        mapButton[0].SetTopLeft(915, 103);
        mapButton[3].SetTopLeft(560, 665);

        mapButton[2].ShowBitmap();
        mapButton[0].ShowBitmap();
        mapButton[3].ShowBitmap();
        break;
    }

    }
}

void Object::MapButton::resetMap(int map_stage) {
    for (int i = 0; i < 4; i++) {
        this->buttonState[i] = false;
        this->mapButton[i].SetFrameIndexOfBitmap(0);
    }
}

void Object::MapController::generateObject() {
    mapController[0].LoadBitmapByString({ "Resources/object/controller_yellow_1.bmp", "Resources/object/controller_yellow_2.bmp" }, RGB(0, 255, 0));
    mapController[1].LoadBitmapByString({ "Resources/object/controller_white_1.bmp", "Resources/object/controller_white_2.bmp" }, RGB(0, 255, 0));
    mapController[2].LoadBitmapByString({ "Resources/object/controller_green_1.bmp", "Resources/object/controller_green_2.bmp" }, RGB(255, 0, 0));
    mapController[3].LoadBitmapByString({ "Resources/object/controller_purple_1.bmp", "Resources/object/controller_purple_2.bmp" }, RGB(0, 255, 0));
    mapController[4].LoadBitmapByString({ "Resources/object/controller_red_1.bmp", "Resources/object/controller_red_2.bmp" }, RGB(0, 255, 0));
    mapController[5].LoadBitmapByString({ "Resources/object/controller_blue_1.bmp", "Resources/object/controller_blue_2.bmp" }, RGB(0, 255, 0));


    for (int i = 0; i < 6; i++) {
        mapController[i].SetTopLeft(0, 0);
        controllerState[i] = false;
    }
}

void Object::MapController::showObject(int map_stage) {
    switch (map_stage) {
    case 1: {
        mapController[0].SetTopLeft(280, 650);
        mapController[0].ShowBitmap();
        break;
    }
    case 3: {
        mapController[0].SetTopLeft(380, 350);
        mapController[1].SetTopLeft(70, 775);
        mapController[2].SetTopLeft(70, 910);
        mapController[3].SetTopLeft(1230, 910);

        for (int i = 0; i < 4; i++) {
            mapController[i].ShowBitmap();
        }

        break;
    }
    case 5: {
        mapController[5].SetTopLeft(315, 210);
        mapController[3].SetTopLeft(700, 133);
        mapController[2].SetTopLeft(835, 98);
        mapController[1].SetTopLeft(995, 133);
        mapController[4].SetTopLeft(1260, 640);

        for (int i = 1; i < 6; i++) {
            mapController[i].ShowBitmap();
        }

        break;
    }
    }
}

void Object::MapController::resetMap(int map_stage){
    for (int i = 0; i < 6; i++) {
        this->controllerState[i] = false;
        this->mapController[i].SetFrameIndexOfBitmap(0);
    }
}

void Object::MapDiamond::generateObject() {
    for (int i = 0; i < 11; i++) {
        redDiamond[i].LoadBitmapByString({ "Resources/object/diamond_red.bmp", "Resources/object/diamond_0.bmp" }, RGB(0, 255, 0));
        blueDiamond[i].LoadBitmapByString({ "Resources/object/diamond_blue.bmp", "Resources/object/diamond_0.bmp" }, RGB(0, 255, 0));
        redDiamond[i].SetTopLeft(0, 0);
        blueDiamond[i].SetTopLeft(0, 0);
        redState[i] = true;
        blueState[i] = true;
    }
    whiteDiamond.LoadBitmapByString({ "Resources/object/diamond_white.bmp", "Resources/object/diamond_white0.bmp" }, RGB(0, 255, 0));
    whiteDiamond.SetTopLeft(0, 0);
}

void Object::MapDiamond::showObject(int map_stage) {
    switch (map_stage) {
    case 1: {
        redDiamond[0].SetTopLeft(665, 890);
        redDiamond[1].SetTopLeft(215, 440);
        redDiamond[2].SetTopLeft(335, 55);
        blueDiamond[0].SetTopLeft(940, 890);
        blueDiamond[1].SetTopLeft(770, 445);
        blueDiamond[2].SetTopLeft(55, 165);
        blueDiamond[3].SetTopLeft(680, 115);

        for (int i = 0; i < 3; i++) {
            if (redState[i])
                redDiamond[i].ShowBitmap();
        }
        for (int i = 0; i < 4; i++) {
            if (blueState[i])
                blueDiamond[i].ShowBitmap();
        }
        break;
    }

    case 2: {
        redDiamond[0].SetTopLeft(870, 150);
        redDiamond[1].SetTopLeft(700, 150);
        redDiamond[2].SetTopLeft(530, 150);
        redDiamond[3].SetTopLeft(330, 85);
        redDiamond[4].SetTopLeft(190, 170);
        redDiamond[5].SetTopLeft(115, 325);
        redDiamond[6].SetTopLeft(570, 325);
        redDiamond[7].SetTopLeft(910, 325);

        blueDiamond[0].SetTopLeft(470, 550);
        blueDiamond[1].SetTopLeft(665, 550);
        blueDiamond[2].SetTopLeft(860, 550);
        blueDiamond[3].SetTopLeft(990, 485);
        blueDiamond[4].SetTopLeft(1165, 585);
        blueDiamond[5].SetTopLeft(1200, 755);
        blueDiamond[6].SetTopLeft(750, 720);
        blueDiamond[7].SetTopLeft(470, 720);;

        for (int i = 0; i < 8; i++) {
            redDiamond[i].ShowBitmap();
            blueDiamond[i].ShowBitmap();
        }
        break;
    }

    case 3: {
        redDiamond[0].SetTopLeft(350, 60);
        redDiamond[1].SetTopLeft(290, 195);
        redDiamond[2].SetTopLeft(245, 335);
        redDiamond[3].SetTopLeft(310, 475);
        redDiamond[4].SetTopLeft(1090, 55);
        redDiamond[5].SetTopLeft(1070, 475);
        redDiamond[6].SetTopLeft(850, 620);
        redDiamond[7].SetTopLeft(905, 895);


        blueDiamond[0].SetTopLeft(460, 60);
        blueDiamond[1].SetTopLeft(190, 755);
        blueDiamond[2].SetTopLeft(190, 895);
        blueDiamond[3].SetTopLeft(1195, 55);
        blueDiamond[4].SetTopLeft(915, 195);
        blueDiamond[5].SetTopLeft(870, 335);
        blueDiamond[6].SetTopLeft(870, 475);
        blueDiamond[7].SetTopLeft(960, 620);;

        for (int i = 0; i < 8; i++) {
            redDiamond[i].ShowBitmap();
            blueDiamond[i].ShowBitmap();
        }
        break;
    }

    case 4: {
        redDiamond[0].SetTopLeft(270, 890);
        redDiamond[1].SetTopLeft(390, 890);
        redDiamond[2].SetTopLeft(465, 850);
        redDiamond[3].SetTopLeft(1040, 715);
        redDiamond[4].SetTopLeft(1140, 715);
        redDiamond[5].SetTopLeft(1260, 380);
        redDiamond[6].SetTopLeft(1260, 260);
        redDiamond[7].SetTopLeft(1260, 150);
        redDiamond[8].SetTopLeft(800, 55);
        redDiamond[9].SetTopLeft(770, 265);
        redDiamond[10].SetTopLeft(375, 360);


        blueDiamond[0].SetTopLeft(1080, 890);
        blueDiamond[1].SetTopLeft(970, 890);
        blueDiamond[2].SetTopLeft(890, 850);
        blueDiamond[3].SetTopLeft(300, 715);
        blueDiamond[4].SetTopLeft(195, 715);
        blueDiamond[5].SetTopLeft(80, 380);
        blueDiamond[6].SetTopLeft(80, 260);
        blueDiamond[7].SetTopLeft(80, 150);
        blueDiamond[8].SetTopLeft(480, 55);
        blueDiamond[9].SetTopLeft(548, 265);
        blueDiamond[10].SetTopLeft(978, 360);

        for (int i = 0; i < 11; i++) {
            redDiamond[i].ShowBitmap();
            blueDiamond[i].ShowBitmap();
        }
        break;
    }

    case 5: {
        whiteDiamond.SetTopLeft(50, 190);
        whiteDiamond.ShowBitmap();
    }

    }
}

void Object::MapDiamond::resetMap(int map_stage) {
    for (int i = 0; i < 11; i++) {
        this->redState[i] = true;
        this->blueState[i] = true;
    }
}

void Object::MapDoor::generateObject() {
    mapDoor[0].LoadBitmapByString({ "Resources/object/door_fire_1.bmp", "Resources/object/door_fire_2.bmp" }, RGB(0, 255, 0));
    mapDoor[1].LoadBitmapByString({ "Resources/object/door_water_1.bmp", "Resources/object/door_water_2.bmp" }, RGB(0, 255, 0));
    mapDoor[0].SetTopLeft(1120, 110);
    mapDoor[1].SetTopLeft(1230, 110);
    doorState[0] = false;
    doorState[1] = false;
}

void Object::MapDoor::showObject(int map_stage) {
    switch (map_stage) {
    case 1: {
        mapDoor[0].SetTopLeft(1120, 110);
        mapDoor[1].SetTopLeft(1230, 110);
        for (int i = 0; i < 2; i++) {
            mapDoor[i].ShowBitmap();
        }
        break;
    }
    case 2: {
        mapDoor[0].SetTopLeft(1195, 427);
        mapDoor[1].SetTopLeft(150, 884);
        for (int i = 0; i < 2; i++) {
            mapDoor[i].ShowBitmap();
        }
        break;
    }
    case 3: {
        mapDoor[0].SetTopLeft(50, 40);
        mapDoor[1].SetTopLeft(150, 40);
        for (int i = 0; i < 2; i++) {
            mapDoor[i].ShowBitmap();
        }
        break;
    }
    case 4: {
        mapDoor[0].SetTopLeft(390, 528);
        mapDoor[1].SetTopLeft(930, 529);
        for (int i = 0; i < 2; i++) {
            mapDoor[i].ShowBitmap();
        }
        break;
    }
    case 5: {
        mapDoor[0].SetTopLeft(50, 40);
        mapDoor[1].SetTopLeft(150, 40);
        for (int i = 0; i < 2; i++) {
            mapDoor[i].ShowBitmap();
        }
        break;
    }
    }
}

void Object::MapDoor::resetMap(int map_stage) {
    this->doorState[0] = false;
    this->doorState[1] = false;
    this->mapDoor[0].SetFrameIndexOfBitmap(0);
    this->mapDoor[1].SetFrameIndexOfBitmap(0);
}

void Object::MapFan::generateObject() {
    mapFan[0].LoadBitmapByString({ "Resources/object/fan.bmp" }, RGB(0, 255, 0));
    mapFan[1].LoadBitmapByString({ "Resources/object/fan.bmp" }, RGB(0, 255, 0));
    mapFan[0].SetTopLeft(0, 0);
    mapFan[1].SetTopLeft(0, 0);
}

void Object::MapFan::showObject(int map_stage) {
    if (map_stage == 4) {
        mapFan[0].SetTopLeft(45, 490);
        mapFan[1].SetTopLeft(1240, 490);
        for (int i = 0; i < 2; i++) {
            mapFan[i].ShowBitmap();
        }
    }
}

void Object::MapPole::generateObject() {
    mapPole[0].LoadBitmapByString({ "Resources/object/pole4_yellow_1.bmp", "Resources/object/pole4_yellow_2.bmp" }, RGB(0, 255, 0));
    mapPole[1].LoadBitmapByString({ "Resources/object/pole4_red_1.bmp", "Resources/object/pole4_red_2.bmp" }, RGB(0, 255, 0));
    mapPole[2].LoadBitmapByString({ "Resources/object/pole4_purple_1.bmp", "Resources/object/pole4_purple_2.bmp" }, RGB(0, 255, 0));
    mapPole[3].LoadBitmapByString({ "Resources/object/pole4_white_1.bmp", "Resources/object/pole4_white_2.bmp" }, RGB(0, 255, 0));

    mapPole[4].LoadBitmapByString({ "Resources/object/pole3_blue_1.bmp", "Resources/object/pole3_blue_2.bmp" }, RGB(0, 255, 0));
    mapPole[5].LoadBitmapByString({ "Resources/object/pole3_green_1.bmp", "Resources/object/pole3_green_2.bmp" });
    mapPole[6].LoadBitmapByString({ "Resources/object/pole3_green2_1.bmp", "Resources/object/pole3_green2_2.bmp" });
    mapPole[7].LoadBitmapByString({ "Resources/object/pole3_purple2_1.bmp", "Resources/object/pole3_purple2_2.bmp" }, RGB(0, 255, 0));
    mapPole[8].LoadBitmapByString({ "Resources/object/pole3_red_1.bmp", "Resources/object/pole3_red_2.bmp" }, RGB(0, 255, 0));
    mapPole[9].LoadBitmapByString({ "Resources/object/pole3_white_1.bmp", "Resources/object/pole3_white_2.bmp" }, RGB(0, 255, 0));
    mapPole[10].LoadBitmapByString({ "Resources/object/pole3_yellow_1.bmp", "Resources/object/pole3_yellow_2.bmp" }, RGB(0, 255, 0));
    mapPole[11].LoadBitmapByString({ "Resources/object/pole3_purple2_1.bmp", "Resources/object/pole3_purple2_2.bmp" }, RGB(0, 255, 0));
    mapPole[12].LoadBitmapByString({ "Resources/object/pole3_white_1.bmp", "Resources/object/pole3_white_2.bmp" }, RGB(0, 255, 0));
    mapPole[13].LoadBitmapByString({ "Resources/object/pole3_purple_1.bmp", "Resources/object/pole3_purple_2.bmp" }, RGB(0, 255, 0));
    mapPole[14].LoadBitmapByString({ "Resources/object/pole3_white_1.bmp", "Resources/object/pole3_white_2.bmp" }, RGB(0, 255, 0));
    mapPole[15].LoadBitmapByString({ "Resources/object/pole3_white_1.bmp", "Resources/object/pole3_white_2.bmp" }, RGB(0, 255, 0));
    mapPole[16].LoadBitmapByString({ "Resources/object/pole3_green_1.bmp", "Resources/object/pole3_green_2.bmp" });

    for (int i = 0; i < 17; i++) {
        mapPole[i].SetTopLeft(0, 0);
    }
    mapPole[0].SetTopLeft(35, 525);
    mapPole[1].SetTopLeft(1225, 425);
}

void Object::MapPole::showObject(int map_stage) {
    switch (map_stage) {
    case 1: {
        for (int i = 0; i < 2; i++) {
            mapPole[i].ShowBitmap();
        }
        break;
    }

    case 3: {
        mapPole[1].SetTopLeft(107, 560);
        mapPole[8].SetTopLeft(560, 420);
        mapPole[4].SetTopLeft(670, 455);
        mapPole[6].SetTopLeft(670, 595);
        mapPole[7].SetTopLeft(530, 877);
        mapPole[11].SetTopLeft(665, 877);
        mapPole[10].SetTopLeft(700, 140);
        mapPole[2].SetTopLeft(1157, 280);
        mapPole[3].SetTopLeft(1155, 700);

        mapPole[1].ShowBitmap();
        mapPole[8].ShowBitmap();
        mapPole[4].ShowBitmap();
        mapPole[6].ShowBitmap();
        mapPole[7].ShowBitmap();
        mapPole[11].ShowBitmap();
        mapPole[10].ShowBitmap();
        mapPole[2].ShowBitmap();
        mapPole[3].ShowBitmap();

        break;
    }

    case 5: {
        mapPole[4].SetTopLeft(590, 35);
        mapPole[5].SetTopLeft(145, 270);
        mapPole[9].SetTopLeft(420, 420);
        mapPole[12].SetTopLeft(455, 560);
        mapPole[6].SetTopLeft(560, 595);
        mapPole[13].SetTopLeft(175, 840);
        mapPole[8].SetTopLeft(1260, 280);
        mapPole[14].SetTopLeft(950, 420);
        mapPole[7].SetTopLeft(1050, 455);
        mapPole[15].SetTopLeft(805, 700);
        mapPole[16].SetTopLeft(1120, 700);

        mapPole[4].ShowBitmap();
        mapPole[5].ShowBitmap();
        mapPole[9].ShowBitmap();
        mapPole[12].ShowBitmap();
        mapPole[6].ShowBitmap();
        mapPole[13].ShowBitmap();
        mapPole[8].ShowBitmap();
        mapPole[14].ShowBitmap();
        mapPole[7].ShowBitmap();
        mapPole[15].ShowBitmap();
        mapPole[16].ShowBitmap();

        break;
    }
    }
}

void Object::MapPole::resetMap(int map_stage) {
    if (map_stage == 1) {
        mapPole[0].SetTopLeft(35, 525);
        mapPole[1].SetTopLeft(1225, 425);
    }
}

void Object::MapPool::generateObject() {
    redPool[0].LoadBitmapByString({ "Resources/object/pool_fire4_1.bmp" }, RGB(0, 255, 0));
    redPool[1].LoadBitmapByString({ "Resources/object/pool_fire3_1.bmp" }, RGB(0, 255, 0));
    redPool[2].LoadBitmapByString({ "Resources/object/pool_fire3_1.bmp" }, RGB(0, 255, 0));
    redPool[3].LoadBitmapByString({ "Resources/object/pool_fire3_1.bmp" }, RGB(0, 255, 0));
    redPool[4].LoadBitmapByString({ "Resources/object/pool_fire3_1.bmp" }, RGB(0, 255, 0));
    redPool[5].LoadBitmapByString({ "Resources/object/pool_fire2_1.bmp" }, RGB(0, 255, 0));
    redPool[6].LoadBitmapByString({ "Resources/object/pool_fire6_1.bmp" }, RGB(0, 255, 0));
    redPool[7].LoadBitmapByString({ "Resources/object/pool_fire6_1.bmp" }, RGB(0, 255, 0));

    bluePool[0].LoadBitmapByString({ "Resources/object/pool_water4_1.bmp" }, RGB(0, 255, 0));
    bluePool[1].LoadBitmapByString({ "Resources/object/pool_water3_1.bmp" }, RGB(0, 255, 0));
    bluePool[2].LoadBitmapByString({ "Resources/object/pool_water3_1.bmp" }, RGB(0, 255, 0));
    bluePool[3].LoadBitmapByString({ "Resources/object/pool_water3_1.bmp" }, RGB(0, 255, 0));
    bluePool[4].LoadBitmapByString({ "Resources/object/pool_water3_1.bmp" }, RGB(0, 255, 0));
    bluePool[5].LoadBitmapByString({ "Resources/object/pool_water2_1.bmp" }, RGB(0, 255, 0));
    bluePool[6].LoadBitmapByString({ "Resources/object/pool_water6_1.bmp" }, RGB(0, 255, 0));
    bluePool[7].LoadBitmapByString({ "Resources/object/pool_water6_1.bmp" }, RGB(0, 255, 0));

    for (int i = 0; i < 8; i++) {
        redPool[i].SetTopLeft(0, 0);
        bluePool[i].SetTopLeft(0, 0);
    }
    greenPool.LoadBitmapByString({ "Resources/object/pool_green4_1.bmp" }, RGB(255, 0, 0));
    greenPool.SetTopLeft(0, 0);
}

void Object::MapPool::showObject(int map_stage) {
    switch (map_stage) {
    case 1: {
        redPool[0].SetTopLeft(620, 975);
        bluePool[0].SetTopLeft(900, 975);
        greenPool.SetTopLeft(870, 765);
        for (int i = 0; i < 1; i++) {
            redPool[i].ShowBitmap();
            bluePool[i].ShowBitmap();
        }
        greenPool.ShowBitmap();
        break;
    }

    case 2: {
        redPool[1].SetTopLeft(750, 840 - 3);
        redPool[2].SetTopLeft(750, 630 - 3);
        redPool[3].SetTopLeft(550, 630 - 3);
        redPool[4].SetTopLeft(350, 630 - 3);
        bluePool[1].SetTopLeft(945, 245 - 3);
        bluePool[2].SetTopLeft(745, 245 - 3);
        bluePool[3].SetTopLeft(545, 245 - 3);
        bluePool[4].SetTopLeft(570, 4203 - 3);

        for (int i = 1; i < 5; i++) {
            redPool[i].ShowBitmap();
            bluePool[i].ShowBitmap();
        }
        break;
    }
    case 4: {
        redPool[5].SetTopLeft(360, 455 - 3);
        redPool[6].SetTopLeft(1020, 802 - 3);
        redPool[7].SetTopLeft(280, 980 - 3);
        bluePool[5].SetTopLeft(965, 455 - 3);
        bluePool[6].SetTopLeft(180, 802 - 3);
        bluePool[7].SetTopLeft(915, 980 - 3);

        for (int i = 5; i < 8; i++) {
            redPool[i].ShowBitmap();
            bluePool[i].ShowBitmap();
        }
        break;
    }
    }
}