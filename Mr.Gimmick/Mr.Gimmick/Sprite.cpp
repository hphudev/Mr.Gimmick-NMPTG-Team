#include "Sprite.h"

Sprite::Sprite()
{

}

Sprite::Sprite(float width, float height, LPCWSTR filename, int lastFrame, int animationDelay, 
	int currentFrame, int animationCount) : Image(width, height, filename)
{
	this->spriteHandler = SpriteHandler(lastFrame, animationDelay, currentFrame, animationCount);
}

SpriteHandler Sprite::GetSpriteHandler()
{
	return this->spriteHandler;
}

void Sprite::Animate()
{
	this->spriteHandler.Animate();
}