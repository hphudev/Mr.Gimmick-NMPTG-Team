#pragma once

#include "TwoDimensionObj.h"
#include "DirectXGraphic.h"
#include <iostream>

using namespace std;

class Tile : public TwoDimensionObj
{
public:
	Tile();
	Tile(float x, float y);
	virtual bool Load(D3DXCOLOR transparentColor, DirectXGraphic directXGraphic);
	virtual void Draw(GraphicDevice graphicDevice, int indexOfRow = 0, bool isRotate = 0,
		LPDIRECT3DSURFACE9 backbuffer = NULL) = 0;
	virtual Tile* Clone() = 0;
	virtual string GetType() = 0;
};