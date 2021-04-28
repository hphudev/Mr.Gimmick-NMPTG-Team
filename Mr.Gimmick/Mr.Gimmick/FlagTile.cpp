#include "FlagTile.h"

FlagTile::FlagTile()
{

}

FlagTile::FlagTile(float x, float y, float spriteWidth, float spriteHeight, LPCWSTR fileSpriteName, 
	int lastSpriteFrame, int animationDelay, int currentSpriteFrame, int animationCount) 
	: AnimatedTile(x, y, spriteWidth, spriteHeight, fileSpriteName, lastSpriteFrame, animationDelay,
		currentSpriteFrame, animationCount)
{

}