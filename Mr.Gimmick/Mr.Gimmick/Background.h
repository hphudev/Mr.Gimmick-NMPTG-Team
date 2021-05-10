#pragma once

#include <list>
#include "Tilemap.h"
#include "Tileset.h"
#include "FileHandler.h"
#include "ScrollBar.h"
#include "LevelOne.h"
#include "Waterfall.h"
#include "Camera.h"

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
	void Copy(const Background& background);
	Background(const Background& background);
	void Clean();
	Background& operator = (const Background& background);
	~Background();
	void DrawBackground(LPDIRECT3DSURFACE9 backbuffer, DirectXGraphic directXGraphic, Camera camera);
	void LoadBackground(DirectXGraphic directXGraphic);
	void ChangeTile(int i, int j, int value, int firstTile, int lastTile, string direction);
	void UpdateBackground(DirectXGraphic directXGraphic);
	void LoadUselessObjs(UselessObj**& uselessObjs);
};