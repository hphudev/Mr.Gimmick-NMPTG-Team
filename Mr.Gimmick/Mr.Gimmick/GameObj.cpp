#include "GameObj.h"

int GameObj::GetID()
{
    return this->gameObjID;
}

GameObj::GameObj(float x, float y, int gameObjID) : TwoDimensionObj(x, y)
{
    this->gameObjID = gameObjID;
}

GameObj::GameObj()
{
    this->gameObjID = 0;
}