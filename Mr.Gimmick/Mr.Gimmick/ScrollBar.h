#pragma once

#include "UselessObj.h"

class ScrollBar : public UselessObj
{
public:
    ScrollBar();
    ScrollBar(float x, float y, int numberOfAnimatedTiles, int gameObjID);
    string GetType();
    UselessObj* Clone();
};