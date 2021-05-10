#pragma once

#include "TwoDimensionObj.h"
#include "Tile.h"

using namespace std;

class GameObj : public TwoDimensionObj
{
protected:
    int gameObjID;
public:
    GameObj();
    GameObj(float x, float y, int gameObjectID);
    int GetID();
};