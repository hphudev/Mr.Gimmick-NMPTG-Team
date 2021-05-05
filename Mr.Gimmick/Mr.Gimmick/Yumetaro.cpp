#include "Yumetaro.h"

Yumetaro::Yumetaro()
{

}

Yumetaro::Yumetaro(float x, float y, float vX, float vY, int numberOfAnimatedTiles, float width, 
	float height, LPCWSTR fileSpriteName) : PlayableObj(x, y, numberOfAnimatedTiles, vX, vY)
{
	this->animatedTiles[0] = new AnimatedTile(x, y, width, height, fileSpriteName, 6, 0, 1);
}

Yumetaro& Yumetaro::operator = (const Yumetaro& yumetaro)
{
	AnimatedAndMovableObj::operator = (yumetaro);

	return *this;
}

bool Yumetaro::Load(D3DXCOLOR transparentColor, DirectXGraphic directXGrphic)
{
	// Tải texture với màu xanh là màu trong suốt
	return this->animatedTiles[0]->Load(transparentColor, directXGrphic);
}

void Yumetaro::Move(int screenWidth, int screenHeight)
{
	Dimension spriteDimension = this->animatedTiles[0]->GetSprite()->GetDimension();
	float lim[2];
	float scale = SCALE;
	lim[0] = screenWidth / scale - spriteDimension.GetFirstValue();
	lim[1] = screenHeight / scale - spriteDimension.GetSecondValue();

	float x = this->point.GetFirstValue();
	float y = this->point.GetSecondValue();
	bool flags[4];
	flags[0] = x <= lim[0];
	flags[1] = x >= 0;
	flags[2] = y <= lim[1];
	flags[3] = y >= 0;

	float vX = this->velocity.GetFirstValue();
	float vY = this->velocity.GetSecondValue();

	if ((flags[0] && flags[1] && flags[2] && flags[3]) || (!flags[0] && vX <= 0) || 
		(!flags[1] && vY >= 0) || (!flags[2] && vY <= 0) || (!flags[3] && vY >= 0))
	{
		AnimatedAndMovableObj::Move(screenWidth, screenHeight);
	}

	if (!flags[0])
	{
		this->point.SetFirstValue(lim[0]);
	}

	if (!flags[1])
	{
		this->point.SetFirstValue(0);
	}

	if (!flags[2])
	{
		this->point.SetSecondValue(lim[1]);
	}

	if (!flags[3])
	{
		this->point.SetSecondValue(0);
	}

	this->animatedTiles[0]->Animate();
}