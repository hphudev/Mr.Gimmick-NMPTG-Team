#include "GameObj.h"

int GameObj::GetID()
{
    return this->gameObjID;
}

GameObj::GameObj()
{

}

GameObj::GameObj(float x, float y) : TwoDimensionObj(x, y)
{

}