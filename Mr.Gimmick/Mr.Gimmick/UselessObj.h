#pragma once

#include "AnimatedAndImmovableObj.h"

class UselessObj : public AnimatedAndImmovableObj
{
public:
    UselessObj();
    UselessObj(float x, float y, int numberOfAnimatedTiles);
    virtual string GetType() = 0;
    void Synchronize();
};