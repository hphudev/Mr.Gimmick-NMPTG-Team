#pragma once

#include "AnimatedAndMovableObj.h"

class UnplayableObj : public AnimatedAndMovableObj
{
public:
	UnplayableObj();
	UnplayableObj(float x, float y, int numberOfAnimatedTiles, float vX, float vY, int gameObjID);
};