#pragma once

#include "AnimatedTile.h"

class ScrollBarTile : public AnimatedTile
{
public:
    ScrollBarTile();
    ScrollBarTile(float x, float y, float spriteWidth, float spriteHeight, LPCWSTR fileSpriteName, 
        int lastSpriteFrame, int animationDelay, int currentSpriteFrame = 0, int animationCount = 0);
    Tile* Clone();
    string GetType();
};