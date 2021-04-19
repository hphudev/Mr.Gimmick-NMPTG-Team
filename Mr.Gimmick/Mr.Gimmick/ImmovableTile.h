#pragma once

#include <d3d9.h>
#include "Tile.h"
#include "DirectXGraphic.h"

class ImmovableTile : public Tile
{
protected:
	Image* image;
	LPDIRECT3DSURFACE9 surface;
public:
	ImmovableTile();
	ImmovableTile(float x, float y, float imageWidth, float imageHeight, LPCWSTR fileImageName);
	~ImmovableTile();
	void Draw(LPDIRECT3DSURFACE9 backbuffer, GraphicDevice graphicDevice);
	bool Load(D3DXCOLOR transparentColor, DirectXGraphic directXGraphic);
};