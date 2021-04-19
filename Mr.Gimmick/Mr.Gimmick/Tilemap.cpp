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
	this->matrix = new int* [row];

	for (int i = 0; i < row; i++)
	{
		this->matrix[i] = new int[column];
	}
}

Tilemap::~Tilemap()
{
	for (int i = 0; i < row; i++)
	{
		if (this->matrix[i] != NULL)
		{
			// ?
			//delete[] this->matrix[i];
			// ?
		}
	}

	if (this->matrix != NULL)
	{
		// ?
		//delete[] this->matrix;
		// ?
	}
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