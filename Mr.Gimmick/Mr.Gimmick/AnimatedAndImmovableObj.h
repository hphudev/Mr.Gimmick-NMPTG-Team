#pragma once

#include "AnimatedObj.h"

class AnimatedAndImmovableObj : public AnimatedObj
{
public:
    AnimatedAndImmovableObj();
    AnimatedAndImmovableObj(float x, float y, int numberOfAnimatedTiles, int gameObjID);
};