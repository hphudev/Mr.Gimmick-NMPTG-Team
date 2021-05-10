#pragma once

#include <fstream>
#include <sstream>
#include <list>
#include "Handler.h"
#include "Tilemap.h"
#include "LevelOne.h"

class FileHandler : public Handler
{
public:
	Tilemap ReadTilemapFile(int row, int column, LPCWSTR filename);
	void Write(string filename, string content);
	list<list<float>> ReadQuadtreeFile(string filename = FILE_QUADTREE_PATH_LEVEL_ONE);
};