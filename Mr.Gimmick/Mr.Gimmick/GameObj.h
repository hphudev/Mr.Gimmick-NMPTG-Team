#pragma once

#include "TwoDimensionObj.h"
#include "Tile.h"

using namespace std;

class GameObj : public TwoDimensionObj
{
protected:
    int gameObjID;
public:
    int GetID();
    GameObj();
    GameObj(float x, float y);
};