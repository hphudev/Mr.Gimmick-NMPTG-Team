#include "Tileset.h"

Tileset::Tileset()
{
	this->numberOfTiles = 0;
	this->tiles = NULL;
}

Tileset::Tileset(int numberOfTiles, LPCWSTR nameOfLevel, D3DCOLOR backgroundColor)
{
	this->backgroundColor = backgroundColor;
	this->numberOfTiles = numberOfTiles;
	this->tiles = new ImmovableTile[numberOfTiles];

	LPCWSTR filePath = FILE_TILESET_PATH, filePath1 = L"/Tileset/Tileset_", filename;
	wstring ws = wstring(filePath) + nameOfLevel + filePath1;
	wstring* wss = new wstring[numberOfTiles];
	string index;
	int tileSize = TILE_SIZE;

	for (int i = 0; i < numberOfTiles; i++)
	{
		index = to_string(i);
		wss[i] = ws + wstring(index.begin(), index.end()) + L".jpg";
		filename = wss[i].c_str();
		this->tiles[i] = ImmovableTile(i * tileSize, 0, tileSize, tileSize, filename);
	}

	// ?
	//delete[] wss;
	// ?
}

Tileset::~Tileset()
{
	// ?
	//delete[] this->tiles;
	// ?
}

ImmovableTile* Tileset::GetTiles()
{
	return this->tiles;
}

D3DCOLOR Tileset::GetBackgroundColor()
{
	return this->backgroundColor;
}