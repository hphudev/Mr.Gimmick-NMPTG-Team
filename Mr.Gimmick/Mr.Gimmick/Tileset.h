#pragma once

#include <string>
#include "ImmovableTile.h"
#include "BackgroundComponent.h"#include "MovableTile.h"
#include "TransformHandler.h"

#pragma region Definition
#define FILE_TILESET_PATH L"C:/Users/DELL/Documents/TvT/UIT/SE102.L21/Project/Github/New folder/Mr.Gimmick-NMPTG-Team/Resource/Map/"

#define TILE_SIZE 16
#pragma endregion

using namespace std;

class Tileset : BackgroundComponent
{
private:
	int numberOfTiles;
	ImmovableTile* tiles;
	D3DCOLOR backgroundColor;
public:
	Tileset();
	Tileset(int numberOfTiles, LPCWSTR nameOfLevel, D3DCOLOR backgroundColor);
	~Tileset();
	ImmovableTile* GetTiles();
	D3DCOLOR GetBackgroundColor();
};