#include "Yumetaro.h"

Yumetaro::Yumetaro()
{

}

Yumetaro::Yumetaro(float x, float y, float vX, float vY, float size, LPCWSTR fileSpriteName) 
	: PlayableObj(x, y, vX, vY)
{
	MovableTile* movableTile = new MovableTile(x, y, size, size, fileSpriteName, 1, 1, 1);
	this->tiles.push_back(movableTile);
}

bool Yumetaro::Load(D3DXCOLOR transparentColor, DirectXGraphic directXGrphic)
{
	// Tải texture với màu xanh là màu trong suốt
	return this->tiles.back()->Load(transparentColor, directXGrphic);
}

void Yumetaro::Move(int screenWidth, int screenHeight)
{
	Dimension spriteDimension = this->tiles.back()->GetSprite()->GetDimension();
	float lim[2];
	lim[0] = screenWidth - spriteDimension.GetFirstValue();
	lim[1] = screenHeight - spriteDimension.GetSecondValue();

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
		MovableObj::Move(screenWidth, screenHeight);
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
}