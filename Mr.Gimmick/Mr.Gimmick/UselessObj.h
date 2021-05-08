#pragma once

#include "AnimatedAndImmovableObj.h"

class UselessObj : public AnimatedAndImmovableObj
{
public:
    UselessObj();
    UselessObj(float x, float y, int numberOfAnimatedTiles, int gameObjID);
    virtual string GetType() = 0;
    void Synchronize();
    virtual UselessObj* Clone() = 0;
};