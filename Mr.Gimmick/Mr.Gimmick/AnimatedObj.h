#pragma once

#include "GameObj.h"
#include "AnimatedTile.h"

class AnimatedObj : public GameObj
{
protected:
	AnimatedTile** animatedTiles;
	int numberOfAnimatedTiles;
public:
	AnimatedObj();
	AnimatedObj(float x, float y, int numberOfAnimatedTiles, int gameObjID);
	AnimatedObj(const AnimatedObj& animatedObj);
	~AnimatedObj();
	void SetDimension();
	void Copy(const AnimatedObj& animatedObj);
	void Clean();
	AnimatedObj& operator = (const AnimatedObj& animatedObj);
	void Draw(int indexOfRow, bool isRotate, GraphicDevice graphicDevice, Point cameraPoint);
	void SetElement(int index, AnimatedTile* animatedTile);
	virtual bool Load(D3DXCOLOR transparentColor, DirectXGraphic directXGrphic);
};