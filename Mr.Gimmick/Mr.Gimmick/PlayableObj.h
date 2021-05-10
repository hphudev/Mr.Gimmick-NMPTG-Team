#pragma once

#include "AnimatedAndMovableObj.h"

class PlayableObj : public AnimatedAndMovableObj
{
public:
    PlayableObj(const PlayableObj& playableObj);
    PlayableObj();
    PlayableObj(float x, float y, int numberOfAnimatedTiles, float vX, float vY, int gameObjID);
};