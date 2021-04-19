#include "FileHandler.h"

Tilemap FileHandler::ReadTilemapFile(int row, int column, LPCWSTR filename)
{
	Tilemap result(row, column, filename);
	int** matrix = result.GetMatrix();

	ifstream input;
	string line;
	int value;
	input.open(filename);

	for (int i = 0; i < row; i++)
	{
		getline(input, line);
		istringstream tmp(line);

		for (int j = 0; j < column; j++)
		{
			tmp >> value;
			matrix[i][j] = value;
		}
	}

	result.SetMatrix(matrix);
	input.close();

	return result;
}