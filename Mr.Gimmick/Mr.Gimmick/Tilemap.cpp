#include "Tilemap.h"

Tilemap::Tilemap()
{
	this->row = this->column = 0;
	this->filename = L"";
	this->matrix = NULL;
}

Tilemap::Tilemap(int row, int column, LPCWSTR filename)
{
	this->row = row;
	this->column = column;
	this->filename = filename;
	this->matrix = new int*[row];

	for (int i = 0; i < row; i++)
	{
		this->matrix[i] = new int[column];
	}
}

void Tilemap::Copy(const Tilemap& tilemap)
{
	this->row = tilemap.row;
	this->column = tilemap.column;
	this->filename = tilemap.filename;
	this->matrix = new int*[tilemap.row];

	for (int i = 0; i < tilemap.row; i++)
	{
		this->matrix[i] = new int[tilemap.column];

		for (int j = 0; j < tilemap.column; j++)
		{
			this->matrix[i][j] = tilemap.matrix[i][j];
		}
	}
}

Tilemap::Tilemap(const Tilemap& tilemap)
{
	Copy(tilemap);
}

void Tilemap::Clean()
{
	for (int i = 0; i < this->row; i++)
	{
		delete[] this->matrix[i];
	}

	delete[] this->matrix;
}

Tilemap& Tilemap::operator = (const Tilemap& tilemap)
{
	if (this != &tilemap)
	{
		Clean();
		Copy(tilemap);
	}

	return *this;
}

Tilemap::~Tilemap()
{
	Clean();
}

int** Tilemap::GetMatrix()
{
	return this->matrix;
}

void Tilemap::SetMatrix(int** matrix)
{
	for (int i = 0; i < this->row; i++)
	{
		for (int j = 0; j < this->column; j++)
		{
			this->matrix[i][j] = matrix[i][j];
		}
	}
}

int Tilemap::GetRow()
{
	return this->row;
}

int Tilemap::GetColumn()
{
	return this->column;
}

int Tilemap::GetElement(int i, int j)
{
	return this->matrix[i][j];
}

void Tilemap::SetElement(int i, int j, int value)
{
	this->matrix[i][j] = value;
}