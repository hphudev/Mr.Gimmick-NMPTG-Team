#include "SpriteHandler.h"

SpriteHandler::SpriteHandler()
{
	this->currentFrame = this->lastFrame = this->animationCount = this->animationDelay = 0;
}

SpriteHandler::SpriteHandler(int lastFrame, int animationDelay, int currentFrame, int animationCount)
{
	this->currentFrame = currentFrame;
	this->lastFrame = lastFrame;
	this->animationCount = animationCount;
	this->animationDelay = animationDelay;
}

void SpriteHandler::Animate()
{
	// Có một animation delay
	if (++this->animationCount > this->animationDelay)
	{
		// Tái lập bộ đếm
		this->animationCount = 0;

		// Animation sprite
		if (++this->currentFrame > this->lastFrame)
		{
			this->currentFrame = 1;
		}
	}
}

RECT SpriteHandler::GetTile(int indexOfRow, Dimension dimension)
{
	float width = dimension.GetFirstValue(), height = dimension.GetSecondValue();

	// Thiết đặt kích thước cho từng tile nguồn
	RECT sourceRectangle;
	sourceRectangle.right = this->currentFrame * width;
	sourceRectangle.bottom = indexOfRow * height;
	sourceRectangle.left = sourceRectangle.right - width;
	sourceRectangle.top = sourceRectangle.bottom - height;

	return sourceRectangle;
}