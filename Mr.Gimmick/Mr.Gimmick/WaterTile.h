#pragma once

#include "AnimatedTile.h"

class WaterTile : public AnimatedTile
{
public:
    WaterTile();
    WaterTile(float x, float y, float spriteWidth, float spriteHeight, LPCWSTR fileSpriteName, 
        int lastSpriteFrame, int animationDelay, int currentSpriteFrame = 0, int animationCount = 0);
};