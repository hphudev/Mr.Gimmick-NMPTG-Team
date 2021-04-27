#pragma once

#include <d3d9.h>
#include "Tile.h"
#include "DirectXGraphic.h"
#include "TransformHandler.h"

class ImmovableTile : public Tile
{
protected:
	Image* image;
	LPDIRECT3DSURFACE9 surface;
public:
	ImmovableTile();
	ImmovableTile(float x, float y, float imageWidth, float imageHeight, LPCWSTR fileImageName);
	~ImmovableTile();
	void Draw(GraphicDevice graphicDevice, int indexOfRow = 0, bool isRotate = 0,
		LPDIRECT3DSURFACE9 backbuffer = NULL);
	bool Load(D3DXCOLOR transparentColor, DirectXGraphic directXGraphic);
	Tile* Clone();
	string GetType();
};