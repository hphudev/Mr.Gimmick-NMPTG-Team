#pragma once

#include "GameObj.h"
#include "Box.h"

class TreeObj
{
private:
	GameObj* gameObj;
public:
	TreeObj();
	TreeObj(GameObj* gameObj);
	Box GetBox();
	int GetID();
	GameObj* GetGameObj();
};