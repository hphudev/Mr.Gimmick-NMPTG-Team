#pragma once

#include "AnimatedAndMovableObj.h"

class PlayableObj : public AnimatedAndMovableObj
{
public:
    PlayableObj();
    PlayableObj(float x, float y, float vX, float vY);
};