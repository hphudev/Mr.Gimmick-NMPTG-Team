#pragma once

#include "TwoDimensionObj.h"
#include "DirectXGraphic.h"

class Tile : public TwoDimensionObj
{
public:
	Tile();
	Tile(float x, float y);
	virtual bool Load(D3DXCOLOR transparentColor, DirectXGraphic directXGraphic);
	virtual void Draw(GraphicDevice graphicDevice, int indexOfRow = 0, bool isRotate = 0, 
		LPDIRECT3DSURFACE9 backbuffer = NULL) = 0;
};