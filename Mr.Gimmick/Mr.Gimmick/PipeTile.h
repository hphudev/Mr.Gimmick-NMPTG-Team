#pragma once

#include "ImmovableTile.h"

class PipeTile : public ImmovableTile
{
public:
    PipeTile();
    PipeTile(float x, float y, float imageWidth, float imageHeight, LPCWSTR fileImageName);
};