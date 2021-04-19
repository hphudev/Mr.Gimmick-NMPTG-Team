#include "ScrollBarTile.h"

ScrollBarTile::ScrollBarTile()
{

}

ScrollBarTile::ScrollBarTile(float x, float y, float spriteWidth, float spriteHeight, 
	LPCWSTR fileSpriteName, int lastSpriteFrame, int animationDelay, int currentSpriteFrame, 
	int animationCount) : MovableTile(x, y, spriteWidth, spriteHeight, fileSpriteName, lastSpriteFrame, 
		animationDelay, currentSpriteFrame, animationCount)
{

}