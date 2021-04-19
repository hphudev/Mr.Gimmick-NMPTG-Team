#pragma once

#include <string>
#include <d3d9.h>
#include "BackgroundComponent.h"

using namespace std;

class Tilemap : public BackgroundComponent
{
private:
	int row, column;
	int** matrix;
	LPCWSTR filename;
public:
	Tilemap();
	Tilemap(int row, int column, LPCWSTR filename);
	~Tilemap();
	int** GetMatrix();
	void SetMatrix(int** matrix);
	int GetRow();
	int GetColumn();
};