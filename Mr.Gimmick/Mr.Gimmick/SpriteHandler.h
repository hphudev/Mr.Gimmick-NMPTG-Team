#pragma once

#include <d3d9.h>
#include "Handler.h"
#include "Dimension.h"

class SpriteHandler : public Handler
{
private:
	int currentFrame, lastFrame, animationDelay, animationCount;
public:
	SpriteHandler();
	SpriteHandler(int lastFrame, int animationDelay, int currentFrame, int animationCount);
	void Animate();
	RECT GetTile(int indexOfRow, Dimension dimension);
};