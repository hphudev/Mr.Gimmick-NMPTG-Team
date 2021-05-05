#pragma once

#include "WaterTile.h"

class WaterfallTile : public WaterTile
{
public:
    WaterfallTile();
    WaterfallTile(float x, float y, float spriteWidth, float spriteHeight, LPCWSTR fileSpriteName,
        int lastSpriteFrame, int animationDelay, int currentSpriteFrame = 0, int animationCount = 0);
    Tile* Clone();
    string GetType();
};