#pragma once

#include <list>
#include <fstream>
#include <sstream>
#include "LevelOne.h"
#include "Handler.h"
#include "Tilemap.h"

class FileHandler : public Handler
{
public:
	void Write(string filename, string content);
	list<list<float>> ReadQuadtreeFile(string filename = FILE_QUADTREE_PATH_LEVEL_ONE);
	Tilemap ReadTilemapFile(int row, int column, LPCWSTR filename);
};