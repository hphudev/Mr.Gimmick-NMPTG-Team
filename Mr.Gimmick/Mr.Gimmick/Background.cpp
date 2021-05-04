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

Background& Background::operator = (const Background& background)
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
			this->tiles[i][j]->SetPoint((float)j * tileSize, (float)i * tileSize);
		}
	}
}

void Background::ChangeTile(int i, int j, int value, int firstTile, int lastTile, string direction)
{
	if (value >= firstTile && value <= lastTile)
	{
		int numberOfDrawings = ((AnimatedTile*)this->tiles[i][j])->GetNumberOfDrawings();
		int tileSize = TILE_SIZE;
		int indexOfNewImageOfTile = ((AnimatedTile*)this->tiles[i][j])->GetIndexOfNewImageOfTile(value,
			firstTile, lastTile, direction, i, j, tileSize);
		this->tiles[i][j] = this->tileset.GetElement(indexOfNewImageOfTile)->Clone();
		((AnimatedTile*)this->tiles[i][j])->SetNumberOfDrawings(numberOfDrawings);
		this->tiles[i][j]->SetPoint((float)j * tileSize, (float)i * tileSize);
	}
}

void Background::UpdateBackground(DirectXGraphic directXGraphic)
{
	int** matrix = tilemap.GetMatrix();
	int value;
	string type;

	for (int i = 0; i < this->row; i++)
	{
		for (int j = 0; j < this->column; j++)
		{
			type = this->tiles[i][j]->GetType();
			value = matrix[i][j];

			if (type == "ScrollBarTile")
			{
				ChangeTile(i, j, value, 140, 143, "Right");
				ChangeTile(i, j, value, 154, 157, "Left");
			}

			if (type == "WaterTile")
			{
				for (int k = 0; k < 8; k++)
				{
					ChangeTile(i, j, value, 94 + k * 14, 97 + k * 14, "Right");
					
					if (k < 4)
					{
						ChangeTile(i, j, value, 205 + k * 14, 208 + k * 14, "Right");
					}
				}
			}
		}
	}
}

void SetPointAndPushBack(list<AnimatedTile*>& animatedTiles, Tile* tile, Point& point)
{
	animatedTiles.push_back((AnimatedTile*)tile);

	if (point.GetFirstValue() == 0 && point.GetSecondValue() == 0)
	{
		point = tile->GetPoint();
	}

	if (tile->GetPoint().GetFirstValue() < point.GetFirstValue() && (point.GetFirstValue() != 0 || 
		point.GetSecondValue() != 0))
	{
		point.SetFirstValue(tile->GetPoint().GetFirstValue());
	}
}

void Load(list<AnimatedTile*>& animatedTiles, UselessObj*& uselessObj, int key, Point& point)
{
	int size = animatedTiles.size(), x = point.GetFirstValue(), y = point.GetSecondValue();

	switch (key)
	{
		case 0:
		{
			uselessObj = new ScrollBar(x, y, size);
			break;
		}
		case 1:
		{
			uselessObj = new Waterfall(x, y, size);
			break;
		}
	}

	for (int i = 0; i < size; i++)
	{
		uselessObj->SetElement(i, animatedTiles.front());
		animatedTiles.pop_front();
	}

	point.SetValue(0, 0);
}

void Background::LoadUselessObjs(UselessObj**& uselessObjs)
{
	const int numberOfTypeOfUselessObjs = NUMBER_OF_TYPE_OF_USELESS_OBJS;
	int indexes[numberOfTypeOfUselessObjs], size;
	indexes[0] = 0;
	indexes[1] = indexes[0] + NUMBER_OF_SCROLLBARS;
	string s = "ScrollBarTile";
	list<AnimatedTile*> animatedTileLists[numberOfTypeOfUselessObjs];
	Point points[numberOfTypeOfUselessObjs];

	for (int i = 0; i < this->row; i++)
	{
		for (int j = 0; j < this->column; j++)
		{
			if (this->tiles[i][j]->GetType() == s && (this->tiles[i][j + 1]->GetType() == s ||
				this->tiles[i][j - 1]->GetType() == s))
			{
				SetPointAndPushBack(animatedTileLists[0], this->tiles[i][j], points[0]);
			}

			if (this->tiles[i][j]->GetType() != s && j != 0 && this->tiles[i][j - 1]->GetType() == s)
			{
				Load(animatedTileLists[0], uselessObjs[indexes[0]], 0, points[0]);
				indexes[0]++;
			}
			
			if (this->tiles[i][j]->GetType() == "WaterTile")
			{
				SetPointAndPushBack(animatedTileLists[1], this->tiles[i][j], points[1]);
			}

			if (i == this->row - 1 && j == this->column - 1)
			{
				Load(animatedTileLists[1], uselessObjs[indexes[1]], 1, points[1]);
			}
		}
	}
}