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
	this->tiles = new Tile*[numberOfTiles];

	LPCWSTR filePath = FILE_TILESET_PATH, filePath1 = L"/Tileset/Tileset_", filename;
	wstring ws = wstring(filePath) + nameOfLevel + filePath1;
	wstring* wss = new wstring[numberOfTiles];
	string index;
	int tileSize = TILE_SIZE;
	int scale = SCALE;

	for (int i = 0; i < numberOfTiles; i++)
	{
		index = to_string(i);
		wss[i] = ws + wstring(index.begin(), index.end()) + L".jpg";
		filename = wss[i].c_str();

		if (CheckTile(i, 2, 140, 4, 14))
		{
			this->tiles[i] = new ScrollBarTile(i * tileSize, 0, tileSize, tileSize, filename, 1,
				0, 1);
		}
		else
		{
			this->tiles[i] = new ImmovableTile(i * tileSize * scale, 0, tileSize * scale,
				tileSize * scale, filename);
		}
	}

	// ?
	//delete[] wss;
	// ?
}

Tileset::~Tileset()
{
	// ?
	/*for (int i = 0; i < this->numberOfTiles; i++)
	{
		delete this->tiles[i];
	}

	delete[] this->tiles;*/
	// ?
}

bool Tileset::CheckTile(int value, int numberOfRows, int firstTile, int numberOfTiles,
	int numberOfTilesInOneRow)
{
	int lastTile = firstTile + numberOfTiles - 1;
	int step;

	for (int i = 0; i < numberOfRows; i++)
	{
		step = numberOfTilesInOneRow * i;

		if (value >= firstTile + step && value <= lastTile + step)
		{
			return 1;
		}
	}

	return 0;
}

void Tileset::LoadTileset(DirectXGraphic directXGraphic)
{
	for (int i = 0; i < this->numberOfTiles; i++)
	{
		this->tiles[i]->Load(this->backgroundColor, directXGraphic);
	}
}

Tile** Tileset::GetTiles()
{
	return this->tiles;
}

Tile* Tileset::GetElement(int i)
{
	return this->tiles[i];
}