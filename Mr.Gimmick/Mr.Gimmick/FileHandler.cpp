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

void FileHandler::Write(string filename, string content)
{
	ofstream file(filename, ios_base::app);
	file << content;
	file.close();
}

list<list<float>> FileHandler::ReadQuadtreeFile(string filename)
{
	list<list<float>> result;
	ifstream input;
	string line;
	float value;
	list<float> dataInOneLine;
	input.open(filename);

	while (getline(input, line))
	{
		istringstream tmp(line);

		while (tmp >> value)
		{
			dataInOneLine.push_back(value);
		}

		result.push_back(list<float>(dataInOneLine));
		dataInOneLine.clear();
	}

	input.close();

	return result;
}