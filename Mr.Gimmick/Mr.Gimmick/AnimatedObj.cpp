#include "AnimatedObj.h"

AnimatedObj::AnimatedObj()
{
	this->numberOfAnimatedTiles = 0;
	this->animatedTiles = NULL;
}

AnimatedObj::AnimatedObj(float x, float y, int numberOfAnimatedTiles) : GameObj(x, y)
{
	this->numberOfAnimatedTiles = numberOfAnimatedTiles;
	this->animatedTiles = new AnimatedTile*[numberOfAnimatedTiles];
}

void AnimatedObj::Copy(const AnimatedObj& animatedObj)
{
	this->point = animatedObj.point;
	this->numberOfAnimatedTiles = animatedObj.numberOfAnimatedTiles;
	this->animatedTiles = new AnimatedTile*[animatedObj.numberOfAnimatedTiles];

	for (int i = 0; i < animatedObj.numberOfAnimatedTiles; i++)
	{
		this->animatedTiles[i] = (AnimatedTile*)animatedObj.animatedTiles[i]->Clone();
	}
}

AnimatedObj::AnimatedObj(const AnimatedObj& animatedObj)
{
	Copy(animatedObj);
}

void AnimatedObj::Clean()
{
	for (int i = 0; i < this->numberOfAnimatedTiles; i++)
	{
		delete this->animatedTiles[i];
	}

	delete[] this->animatedTiles;
}

AnimatedObj& AnimatedObj::operator = (const AnimatedObj& animatedObj)
{
	if (this != &animatedObj)
	{
		Clean();
		Copy(animatedObj);
	}

	return *this;
}

AnimatedObj::~AnimatedObj()
{
	Clean();
}

void AnimatedObj::Draw(int indexOfRow, bool isRotate, GraphicDevice graphicDevice)
{
	for (int i = 0; i < this->numberOfAnimatedTiles; i++)
	{
		this->animatedTiles[i]->Draw(graphicDevice, indexOfRow);
	}
}

void AnimatedObj::SetElement(int index, AnimatedTile* animatedTile)
{
	this->animatedTiles[index] = animatedTile;
}