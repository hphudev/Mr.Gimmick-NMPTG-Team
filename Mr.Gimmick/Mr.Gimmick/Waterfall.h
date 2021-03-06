#pragma once

#include "UselessObj.h"

class Waterfall : public UselessObj
{
public:
    Waterfall();
    Waterfall(float x, float y, int numberOfAnimatedTiles, int gameObjID);
    string GetType();
    UselessObj* Clone();
};