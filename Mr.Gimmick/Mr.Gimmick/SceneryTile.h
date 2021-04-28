#pragma once

#include "InanimatedTile.h"

class SceneryTile : public InanimatedTile
{
public:
    SceneryTile();
    SceneryTile(float x, float y, float imageWidth, float imageHeight, LPCWSTR fileImageName);
};