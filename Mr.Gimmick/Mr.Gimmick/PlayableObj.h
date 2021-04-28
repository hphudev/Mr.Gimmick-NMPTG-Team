#pragma once

#include "MovableObj.h"

class PlayableObj : public MovableObj
{
public:
    PlayableObj();
    PlayableObj(float x, float y, float vX, float vY);
};