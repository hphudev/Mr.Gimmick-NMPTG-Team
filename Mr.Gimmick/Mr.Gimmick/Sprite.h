#pragma once

#include "Image.h"
#include "SpriteHandler.h"

class Sprite : public Image
{
private:
	SpriteHandler spriteHandler;
public:
	Sprite();
	Sprite(float width, float height, LPCWSTR filename, int lastFrame, int animationDelay,
		int currentFrame, int animationCount);
	SpriteHandler GetSpriteHandler();
	void Animate();
	Sprite* Clone();
};