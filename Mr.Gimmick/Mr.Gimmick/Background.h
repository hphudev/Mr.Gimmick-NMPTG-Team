#pragma once

#include "Tilemap.h"
#include "Tileset.h"
#include "FileHandler.h"

class Background
{
private:
	Tileset tileset;
	Tilemap tilemap;
	Tile*** tiles;
	int row, column;
public:
	Background();
	Background(int row, int column, LPCWSTR fileTilemapName, int numberOfTiles, LPCWSTR nameOfLevel, 
		D3DCOLOR backgroundColor);
	~Background();
	void DrawBackground(LPDIRECT3DSURFACE9 backbuffer, DirectXGraphic directXGraphic);
	void LoadBackground(DirectXGraphic directXGraphic);
};