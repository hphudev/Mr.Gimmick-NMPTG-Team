#include "Background.h"

Background::Background()
{

}

Background::Background(int row, int column, LPCWSTR fileTilemapName, int numberOfTiles, 
	LPCWSTR nameOfLevel, D3DCOLOR backgroundColor)
{
	this->tilemap = FileHandler().ReadTilemapFile(row, column, fileTilemapName);
	this->tileset = Tileset(numberOfTiles, nameOfLevel, backgroundColor);
	this->row = this->tilemap.GetRow();
	this->column = this->tilemap.GetColumn();
	this->tiles = new Tile**[row];

	for (int i = 0; i < row; i++)
	{
		this->tiles[i] = new Tile*[column];
	}
}

Background::~Background()
{
	// ?
	/*for (int i = 0; i < this->row; i++)
	{
		for (int j = 0; j < this->column; j++)
		{
			delete this->tiles[i][j];
		}

		delete[] this->tiles[i];
	}

	delete[] this->tiles;*/
	// ?
}

void Background::DrawBackground(LPDIRECT3DSURFACE9 backbuffer, DirectXGraphic directXGraphic)
{
	for (int i = 0; i < this->row; i++)
	{
		for (int j = 0; j < this->column; j++)
		{
			this->tiles[i][j]->Draw(directXGraphic.GetGraphicDevice(), 1, 0, backbuffer);
		}
	}
}

void Background::LoadBackground(DirectXGraphic directXGraphic)
{
	this->tileset.LoadTileset(directXGraphic);
	int** matrix = this->tilemap.GetMatrix();
	Tile** tiles = this->tileset.GetTiles();
	int tileSize = TILE_SIZE, value;

	for (int i = 0; i < this->row; i++)
	{
		for (int j = 0; j < this->column; j++)
		{
			value = matrix[i][j];
			this->tiles[i][j] = tiles[value]->Clone();
			this->tiles[i][j]->SetPoint(j * tileSize, i * tileSize);
		}
	}
}