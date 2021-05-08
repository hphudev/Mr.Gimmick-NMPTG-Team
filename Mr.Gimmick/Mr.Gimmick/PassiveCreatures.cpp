#include "PassiveCreatures.h"

PassiveCreatures::PassiveCreatures()
{

}

PassiveCreatures::PassiveCreatures(float x, float y, float vX, float vY, int numberOfAnimatedTiles,
	float width, float height, LPCWSTR fileSpriteName) : UnplayableObj(x, y, numberOfAnimatedTiles, vX,
		vY)
{
	this->animatedTiles[0] = new AnimatedTile(x, y, width, height, fileSpriteName, 1, 0, 1);
	SetDimension();
}

PassiveCreatures& PassiveCreatures::operator = (const PassiveCreatures& enemies)
{
	AnimatedAndMovableObj::operator = (enemies);

	return *this;
}

bool PassiveCreatures::Load(D3DXCOLOR transparentColor, DirectXGraphic directXGrphic)
{
	return this->animatedTiles[0]->Load(transparentColor, directXGrphic);
}