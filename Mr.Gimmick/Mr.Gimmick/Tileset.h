#pragma once

#include <string>
#include "ImmovableTile.h"
#include "BackgroundComponent.h"
#include "MovableTile.h"
#include "TransformHandler.h"
#include "ScrollBarTile.h"

#pragma region Definition
#define FILE_TILESET_PATH L"E:/Clone/Mr.Gimmick-NMPTG-Team/Resource/Map/"

#define TILE_SIZE 16
#pragma endregion

using namespace std;

class Tileset : BackgroundComponent
{
private:
	int numberOfTiles;
	Tile** tiles;
	D3DCOLOR backgroundColor;
public:
	Tileset();
	Tileset(int numberOfTiles, LPCWSTR nameOfLevel, D3DCOLOR backgroundColor);
	~Tileset(); 
	bool CheckTile(int value, int numberOfRows, int firstTile, int numberOfTiles,
		int numberOfTilesInOneRow);
	void LoadTileset(DirectXGraphic directXGraphic);
	Tile** GetTiles();
	Tile* GetElement(int i);
};