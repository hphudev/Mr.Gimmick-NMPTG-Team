#include "Background.h"

Background::Background()
{

}

Background::Background(int row, int column, LPCWSTR fileTilemapName, int numberOfTiles, 
	LPCWSTR nameOfLevel, D3DCOLOR backgroundColor)
{
	FileHandler tmp;
	this->tilemap = tmp.ReadTilemapFile(row, column, fileTilemapName);
	this->tileset = Tileset(numberOfTiles, nameOfLevel, backgroundColor);
}

Background::~Background()
{
	// ?
	int row = this->tilemap.GetRow();

	for (int i = 0; i < row; i++)
	{
		//delete this->tiles[i];
	}

	//delete[] this->tiles;
	// ?
}

void Background::DrawBackground(LPDIRECT3DSURFACE9 backbuffer, DirectXGraphic directXGraphic)
{
	int row = this->tilemap.GetRow(), column = this->tilemap.GetColumn();

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			this->tiles[i][j].Draw(directXGraphic.GetGraphicDevice(), 0, 0, backbuffer);
		}
	}
}

void Background::LoadBackground(DirectXGraphic directXGraphic)
{
	int** matrix = this->tilemap.GetMatrix();
	int row = this->tilemap.GetRow(), column = this->tilemap.GetColumn();
	ImmovableTile* tiles = this->tileset.GetTiles();
	int tileSize = TILE_SIZE;
	this->tiles = new ImmovableTile*[row];
	
	for (int i = 0; i < row; i++)
	{
		this->tiles[i] = new ImmovableTile[column];
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			this->tiles[i][j] = tiles[matrix[i][j]];
			this->tiles[i][j].SetPoint(j * tileSize, i * tileSize);
			this->tiles[i][j].Load(this->tileset.GetBackgroundColor(), directXGraphic);
		}
	}
}