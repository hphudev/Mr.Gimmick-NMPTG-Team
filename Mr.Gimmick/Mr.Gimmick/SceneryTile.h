#pragma once

#include "ImmovableTile.h"

class SceneryTile : public ImmovableTile
{
public:
    SceneryTile();
    SceneryTile(float x, float y, float imageWidth, float imageHeight, LPCWSTR fileImageName);
};