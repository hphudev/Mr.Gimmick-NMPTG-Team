#include "GameObj.h"

GameObj::GameObj()
{
    this->gameObjID = 0;
}

GameObj::GameObj(float x, float y, int gameObjID) : TwoDimensionObj(x, y)
{
    this->gameObjID = gameObjID;
}

int GameObj::GetID()
{
    return this->gameObjID;
}