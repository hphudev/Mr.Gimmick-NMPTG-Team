#pragma once

#include "TwoDimensionObj.h"
#include "GraphicDevice.h"

class Tile : public TwoDimensionObj
{
public:
	Tile();
	Tile(float x, float y);
	virtual bool Load(D3DXCOLOR transparentColor, GraphicDevice graphicDevice);
};