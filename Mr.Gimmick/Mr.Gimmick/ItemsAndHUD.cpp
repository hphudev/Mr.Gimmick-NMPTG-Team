#include "ItemsAndHUD.h"

ItemsAndHUD::ItemsAndHUD()
{

}

ItemsAndHUD::ItemsAndHUD(float x, float y, int currentFrame, float width, float height, 
	int numberOfAnimatedTiles, LPCWSTR fileSpriteName) : UsefulObj(x, y, numberOfAnimatedTiles)
{
	this->animatedTiles[0] = new AnimatedTile(x, y, width, height, fileSpriteName, 1, 0, currentFrame);
	SetDimension();
}

ItemsAndHUD& ItemsAndHUD::operator = (const ItemsAndHUD& itemsAndHUD)
{
	AnimatedObj::operator = (itemsAndHUD);

	return *this;
}

bool ItemsAndHUD::Load(D3DXCOLOR transparentColor, DirectXGraphic directXGrphic)
{
	return this->animatedTiles[0]->Load(transparentColor, directXGrphic);
}