#pragma once

#include "GameObj.h"
#include "Box.h"

class TreeObj
{
private:
	GameObj* gameObj;
public:
	int GetID();
	Box GetBox();
	TreeObj(GameObj* gameObj);
	TreeObj();
};