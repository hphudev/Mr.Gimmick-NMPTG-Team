#pragma once

#include "Handler.h"
#include "Tilemap.h"
#include <fstream>
#include <sstream>

class FileHandler : public Handler
{
public:
	Tilemap ReadTilemapFile(int row, int column, LPCWSTR filename);
};