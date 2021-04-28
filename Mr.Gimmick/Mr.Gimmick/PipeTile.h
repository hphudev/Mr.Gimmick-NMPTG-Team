#pragma once

#include "InanimatedTile.h"

class PipeTile : public InanimatedTile
{
public:
    PipeTile();
    PipeTile(float x, float y, float imageWidth, float imageHeight, LPCWSTR fileImageName);
};