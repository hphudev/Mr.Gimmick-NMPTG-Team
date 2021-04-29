#include "AnimatedAndMovableObj.h"

AnimatedAndMovableObj::AnimatedAndMovableObj()
{

}

AnimatedAndMovableObj::AnimatedAndMovableObj(float x, float y, float vX, float vY) : AnimatedObj(x, y)
{
	this->velocity = Velocity(vX, vY);
	this->state = new IdleState();
}

AnimatedAndMovableObj::~AnimatedAndMovableObj()
{
	// ?
	//delete state;
	// ?
}

void AnimatedAndMovableObj::Move(int screenWidth, int screenHeight)
{
	float x = this->point.GetFirstValue() + this->velocity.GetFirstValue();
	float y = this->point.GetSecondValue() + this->velocity.GetSecondValue();
	this->point.SetValue(x, y);
	AnimatedTile* animatedTile;
	int length = this->animatedTiles.size();

	for (int i = 0; i < length; i++)
	{
		animatedTile = this->animatedTiles.back();
		animatedTile->SetPoint(x, y);
		this->animatedTiles.pop_back();
		this->animatedTiles.push_front(animatedTile);
	}

	this->animatedTiles.reverse();
}

void AnimatedAndMovableObj::SetVelocity(float vX, float vY)
{
	this->velocity.SetValue(vX, vY);
}

void AnimatedAndMovableObj::SetState(State* state)
{
	this->state = state;
}