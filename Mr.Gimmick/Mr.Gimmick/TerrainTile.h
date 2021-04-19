#pragma once

#include "ImmovableTile.h"

class TerrainTile : public ImmovableTile
{
public:
    TerrainTile();
    TerrainTile(float x, float y, float imageWidth, float imageHeight, LPCWSTR fileImageName);
};