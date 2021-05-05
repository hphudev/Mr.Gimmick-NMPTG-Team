#include "WaterfallTile.h"

WaterfallTile::WaterfallTile()
{

}

WaterfallTile::WaterfallTile(float x, float y, float spriteWidth, float spriteHeight,
	LPCWSTR fileSpriteName, int lastSpriteFrame, int animationDelay, int currentSpriteFrame,
	int animationCount) : WaterTile(x, y, spriteWidth, spriteHeight, fileSpriteName, lastSpriteFrame,
		animationDelay, currentSpriteFrame, animationCount)
{

}

Tile* WaterfallTile::Clone()
{
	return new WaterfallTile(*this);
}

string WaterfallTile::GetType()
{
	return "WaterfallTile";
}