#include "TreeObj.h"

TreeObj::TreeObj()
{
	this->gameObj = NULL;
}

TreeObj::TreeObj(GameObj* gameObj)
{
	this->gameObj = gameObj;
}

Box TreeObj::GetBox()
{
	return this->gameObj->GetBox();
}

int TreeObj::GetID()
{
	return this->gameObj->GetID();
}

GameObj* TreeObj::GetGameObj()
{
	return this->gameObj;
}