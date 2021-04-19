#pragma once

#include "MovableTile.h"

class FlagTile : public MovableTile
{
public:
    FlagTile();
    FlagTile(float x, float y, float spriteWidth, float spriteHeight, LPCWSTR fileSpriteName, 
        int lastSpriteFrame, int animationDelay, int currentSpriteFrame = 0, int animationCount = 0);
};