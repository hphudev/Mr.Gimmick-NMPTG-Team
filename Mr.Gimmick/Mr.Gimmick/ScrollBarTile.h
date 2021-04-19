#pragma once

#include "MovableTile.h"

class ScrollBarTile : public MovableTile
{
public:
    ScrollBarTile();
    ScrollBarTile(float x, float y, float spriteWidth, float spriteHeight, LPCWSTR fileSpriteName, 
        int lastSpriteFrame, int animationDelay, int currentSpriteFrame = 0, int animationCount = 0);
};