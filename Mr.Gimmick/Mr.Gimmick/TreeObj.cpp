#include "TreeObj.h"

Box TreeObj::GetBox()
{
	return this->gameObj->GetBox();
}

TreeObj::TreeObj(GameObj* gameObj)
{
	this->gameObj = gameObj;
}

TreeObj::TreeObj()
{
	this->gameObj = NULL;
}