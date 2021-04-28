#pragma once

#include "InanimatedTile.h"

class TerrainTile : public InanimatedTile
{
public:
    TerrainTile();
    TerrainTile(float x, float y, float imageWidth, float imageHeight, LPCWSTR fileImageName);
};