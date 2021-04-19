#pragma once

#include "MovableTile.h"

class WaterTile : public MovableTile
{
public:
    WaterTile();
    WaterTile(float x, float y, float spriteWidth, float spriteHeight, LPCWSTR fileSpriteName, 
        int lastSpriteFrame, int animationDelay, int currentSpriteFrame = 0, int animationCount = 0);
};