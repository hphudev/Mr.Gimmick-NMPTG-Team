#include "HazardsAndInteractables.h"

HazardsAndInteractables::HazardsAndInteractables()
{

}

HazardsAndInteractables::HazardsAndInteractables(float x, float y, int currentFrame, float width, 
	float height, int numberOfAnimatedTiles, LPCWSTR fileSpriteName) : AnimatedObj(x, y, 
	numberOfAnimatedTiles)
{
	this->animatedTiles[0] = new AnimatedTile(x, y, width, height, fileSpriteName, 1, 0, currentFrame);
	SetDimension();
}

HazardsAndInteractables& HazardsAndInteractables::operator = (
	const HazardsAndInteractables& hazardsAndInteractables)
{
	AnimatedObj::operator = (hazardsAndInteractables);

	return *this;
}

bool HazardsAndInteractables::Load(D3DXCOLOR transparentColor, DirectXGraphic directXGrphic)
{
	return this->animatedTiles[0]->Load(transparentColor, directXGrphic);
}