#include "Bosses.h"

Bosses::Bosses()
{

}

Bosses::Bosses(float x, float y, float vX, float vY, int numberOfAnimatedTiles, float width, float height,
	LPCWSTR fileSpriteName) : UnplayableObj(x, y, numberOfAnimatedTiles, vX, vY)
{
	this->animatedTiles[0] = new AnimatedTile(x, y, width, height, fileSpriteName, 1, 0, 1);
}

Bosses& Bosses::operator = (const Bosses& bosses)
{
	AnimatedAndMovableObj::operator = (bosses);

	return *this;
}

bool Bosses::Load(D3DXCOLOR transparentColor, DirectXGraphic directXGrphic)
{
	return this->animatedTiles[0]->Load(transparentColor, directXGrphic);
}