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

void Background::DrawBackground(LPDIRECT3DSURFACE9 backbuffer, DirectXGraphic directXGraphic)
{
	int** matrix = this->tilemap.GetMatrix();
	int row = this->tilemap.GetRow(), column = this->tilemap.GetColumn();
	ImmovableTile* tiles = this->tileset.GetTiles();
	int tileSize = TILE_SIZE;
	ImmovableTile tile;

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			tile = tiles[matrix[i][j]];
			tile.SetPoint(j * tileSize, i * tileSize);
			tile.Load(this->tileset.GetBackgroundColor(), directXGraphic);
			tile.Draw(backbuffer, directXGraphic.GetGraphicDevice());
		}
	}
}