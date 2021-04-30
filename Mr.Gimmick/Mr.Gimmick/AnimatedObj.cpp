#include "AnimatedObj.h"

AnimatedObj::AnimatedObj()
{

}

AnimatedObj::AnimatedObj(float x, float y) : GameObj(x, y)
{

}

AnimatedObj::~AnimatedObj()
{
	// ?
	/*AnimatedTile* animatedTile;

	while (!this->animatedTiles.empty())
	{
		animatedTile = this->animatedTiles.back();
		delete animatedTile;
		this->animatedTiles.pop_back();
	}*/
	// ?
}

void AnimatedObj::Draw(int indexOfRow, bool isRotate, GraphicDevice graphicDevice)
{
	int length = this->animatedTiles.size();
	AnimatedTile* animatedTile;

	for (int i = 0; i < length; i++)
	{
		animatedTile = this->animatedTiles.back();
		animatedTile->Draw(graphicDevice, indexOfRow);
		this->animatedTiles.pop_back();
		this->animatedTiles.push_front(animatedTile);
	}

	this->animatedTiles.reverse();
}