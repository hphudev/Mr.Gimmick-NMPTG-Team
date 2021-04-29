#pragma once

#include "GameObj.h"
#include "AnimatedTile.h"

class AnimatedObj : public GameObj
{
protected:
	list<AnimatedTile*> animatedTiles;
public:
	AnimatedObj();
	AnimatedObj(float x, float y);
	~AnimatedObj();
	void Draw(int indexOfRow, bool isRotate, GraphicDevice graphicDevice);
};