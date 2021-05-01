#include "Background.h"

Background::Background()
{
	this->row = this->column = 0;
	this->tiles = NULL;
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
		this->tiles[i] = new Tile*[column]{NULL};
	}
}

void Background::Copy(const Background& background)
{
	this->row = background.row;
	this->column = background.column;
	this->tilemap = background.tilemap;
	this->tileset = background.tileset;
	this->tiles = new Tile**[background.row];

	for (int i = 0; i < background.row; i++)
	{
		this->tiles[i] = new Tile*[background.column];

		for (int j = 0; j < background.column; j++)
		{
			if (background.tiles[i][j] != NULL)
			{
				this->tiles[i][j] = background.tiles[i][j]->Clone();
			}
		}
	}
}

Background::Background(const Background& background)
{
	Copy(background);
}

void Background::Clean()
{
	for (int i = 0; i < this->row; i++)
	{
		for (int j = 0; j < this->column; j++)
		{
			delete this->tiles[i][j];
		}

		delete[] this->tiles[i];
	}

	delete[] this->tiles;
}

Background& Background::operator=(const Background& background)
{
	if (this != &background)
	{
		Clean();
		Copy(background);
	}

	return *this;
}

Background::~Background()
{
	Clean();
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

void Background::ChangeTile(int i, int j, int value, int firstTile, int lastTile, string direction)
{
	if (value >= firstTile && value <= lastTile)
	{
		int numberOfTiles = lastTile - firstTile + 1;
		int numberOfDrawings = ((AnimatedTile*)this->tiles[i][j])->GetNumberOfDrawings();
		int tileSize = TILE_SIZE;

		if (direction == "Right")
		{
			value += numberOfDrawings % numberOfTiles;

			if (value <= lastTile)
			{
				this->tiles[i][j] = this->tileset.GetElement(value)->Clone();
			}
			else
			{
				this->tiles[i][j] = this->tileset.GetElement(firstTile)->Clone();
				value = firstTile;
			}
		}
		else
		{
			value -= numberOfDrawings % numberOfTiles;

			if (value >= firstTile)
			{
				this->tiles[i][j] = this->tileset.GetElement(value)->Clone();
			}
			else
			{
				this->tiles[i][j] = this->tileset.GetElement(lastTile)->Clone();
				value = lastTile;
			}
		}

		((AnimatedTile*)this->tiles[i][j])->SetNumberOfDrawings(numberOfDrawings);
		this->tiles[i][j]->SetPoint(j * tileSize, i * tileSize);
		this->tilemap.SetElement(i, j, value);
	}
}

void Background::UpdateBackground(DirectXGraphic directXGraphic)
{
	int** matrix = tilemap.GetMatrix();
	int value;

	for (int i = 0; i < this->row; i++)
	{
		for (int j = 0; j < this->column; j++)
		{
			if (this->tiles[i][j]->GetType() == "ScrollBarTile")
			{
				value = matrix[i][j];
				ChangeTile(i, j, value, 140, 143, "Right");
				ChangeTile(i, j, value, 154, 157, "Left");
			}
		}
	}
}

void Background::LoadUselessObjs(UselessObj**& uselessObjs)
{
	int index = 0, size;
	string s = "ScrollBarTile";
	list<AnimatedTile*> animatedTiles;
	Point point, scrollBarPoint;
	bool flag = 0;

	for (int i = 0; i < this->row; i++)
	{
		for (int j = 0; j < this->column; j++)
		{
			if (this->tiles[i][j]->GetType() == s && (this->tiles[i][j + 1]->GetType() == s ||
				this->tiles[i][j - 1]->GetType() == s) &&
				uselessObjs[index]->GetType() == "ScrollBar")
			{
				animatedTiles.push_back((AnimatedTile*)this->tiles[i][j]);

				if (!flag)
				{
					point = this->tiles[i][j]->GetPoint();
					scrollBarPoint.SetValue(point.GetFirstValue(), point.GetSecondValue());
					flag = 1;
				}
			}

			if (this->tiles[i][j]->GetType() != s && j != 0 && this->tiles[i][j - 1]->GetType() == s)
			{
				size = animatedTiles.size();
				uselessObjs[index] = new ScrollBar(scrollBarPoint.GetFirstValue(),
					scrollBarPoint.GetSecondValue(), size);

				for (int i = 0; i < size; i++)
				{
					uselessObjs[index]->SetElement(i, animatedTiles.front());
					animatedTiles.pop_front();
				}

				index++;
				flag = 0;
			}
		}
	}
}