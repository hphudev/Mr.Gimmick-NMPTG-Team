#pragma once

#include <string>
#include "InanimatedTile.h"
#include "BackgroundComponent.h"
#include "AnimatedTile.h"
#include "TransformHandler.h"
#include "ScrollBarTile.h"
#include "WaterTile.h"

#pragma region Definition
#define FOLDER_TILESET_PATH L"../../Resource/Map/"

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
	void Copy(const Tileset& tileset);
	Tileset(const Tileset& tileset);
	void Clean();
	Tileset& operator = (const Tileset& tileset);
	~Tileset(); 
	bool CheckTile(int value, int numberOfRows, int firstTile, int numberOfTiles,
		int numberOfTilesInOneRow);
	void LoadTileset(DirectXGraphic directXGraphic);
	Tile** GetTiles();
	Tile* GetElement(int i);
};