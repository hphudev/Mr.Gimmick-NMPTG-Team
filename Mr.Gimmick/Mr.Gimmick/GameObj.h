#pragma once

#include "TwoDimensionObj.h"
#include "Tile.h"

using namespace std;

class GameObj : public TwoDimensionObj
{
public:
    GameObj();
    GameObj(float x, float y);
};