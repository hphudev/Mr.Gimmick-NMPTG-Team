#include "WaterTile.h"

WaterTile::WaterTile()
{

}

WaterTile::WaterTile(float x, float y, float spriteWidth, float spriteHeight,
	LPCWSTR fileSpriteName, int lastSpriteFrame, int animationDelay, int currentSpriteFrame,
	int animationCount) : AnimatedTile(x, y, spriteWidth, spriteHeight, fileSpriteName, lastSpriteFrame,
		animationDelay, currentSpriteFrame, animationCount)
{

}

Tile* WaterTile::Clone()
{
	return new WaterTile(*this);
}

string WaterTile::GetType()
{
	return "WaterTile";
}