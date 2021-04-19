#pragma once

#include "Tilemap.h"
#include "Tileset.h"
#include "FileHandler.h"

class Background
{
private:
	Tileset tileset;
	Tilemap tilemap;
public:
	Background();
	Background(int row, int column, LPCWSTR fileTilemapName, int numberOfTiles, LPCWSTR nameOfLevel, 
		D3DCOLOR backgroundColor);
	void DrawBackground(LPDIRECT3DSURFACE9 backbuffer, DirectXGraphic directXGraphic);
};