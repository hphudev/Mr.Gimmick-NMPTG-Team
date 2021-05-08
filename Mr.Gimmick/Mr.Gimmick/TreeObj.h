#pragma once

#include "GameObj.h"
#include "Box.h"

class TreeObj
{
private:
	GameObj* gameObj;
public:
	Box GetBox();
	TreeObj(GameObj* gameObj);
	TreeObj();
};