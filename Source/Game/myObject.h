#pragma once

#ifndef MYOBJECT_H

#define MYOBJECT_H
#include "../Library/gameutil.h"

using namespace game_framework;

namespace Object {
    class Object {
    public:
        virtual void generateObject() = 0;
        virtual void showObject(int map_stage) = 0;

        bool is_Overlap(CMovingBitmap character, CMovingBitmap object);
    };

    class MapBox : public Object {
    public:
        CMovingBitmap mapBox;
        void generateObject();
        void showObject(int map_stage);
    };

    class MapButton : public Object {
    public:
        CMovingBitmap mapButton[4];
        bool buttonState[4];
        void generateObject();
        void showObject(int map_stage);
    };

    class MapController : public Object {
    public:
        CMovingBitmap mapController[6];
        bool controllerState[6];
        void generateObject();
        void showObject(int map_stage);
    };

    class MapDiamond : public Object {
    public:
        CMovingBitmap redDiamond[11];
        CMovingBitmap blueDiamond[11];
        CMovingBitmap whiteDiamond;
        void generateObject();
        void showObject(int map_stage);
    };

    class MapDoor : public Object {
    public:
        CMovingBitmap mapDoor[2];
        void generateObject();
        void showObject(int map_stage);
    };

    class MapFan : public Object {
    public:
        CMovingBitmap mapFan[2];
        void generateObject();
        void showObject(int map_stage);
    };

    class MapPole : public Object {
    public:
        CMovingBitmap mapPole[17];
        void generateObject();
        void showObject(int map_stage);
    };

    class MapPool : public Object {
    public:
        CMovingBitmap redPool[8];
        CMovingBitmap bluePool[8];
        CMovingBitmap greenPool;
        void generateObject();
        void showObject(int map_stage);
    };
};
#endif // !MYOBJECT_H