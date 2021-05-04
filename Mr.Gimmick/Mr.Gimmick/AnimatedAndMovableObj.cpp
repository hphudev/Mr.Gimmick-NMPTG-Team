#include "AnimatedAndMovableObj.h"

AnimatedAndMovableObj::AnimatedAndMovableObj()
{
	this->state = NULL;
}

AnimatedAndMovableObj::AnimatedAndMovableObj(float x, float y, int numberOfAnimatedTiles, float vX, 
	float vY) : AnimatedObj(x, y, numberOfAnimatedTiles)
{
	this->velocity = Velocity(vX, vY);
	this->state = new IdleState();
}

void AnimatedAndMovableObj::Copy(const AnimatedAndMovableObj& animatedAndMovableObj)
{
	this->velocity = animatedAndMovableObj.velocity;
	this->state = animatedAndMovableObj.state->Clone();
}

AnimatedAndMovableObj::AnimatedAndMovableObj(const AnimatedAndMovableObj& animatedAndMovableObj) : 
	AnimatedObj(animatedAndMovableObj)
{
	Copy(animatedAndMovableObj);
}

void AnimatedAndMovableObj::Clean()
{
	delete this->state;
}

AnimatedAndMovableObj& AnimatedAndMovableObj::operator = (
	const AnimatedAndMovableObj& animatedAndMovableObj)
{
	AnimatedObj::operator = (animatedAndMovableObj);

	if (this != &animatedAndMovableObj)
	{
		Clean();
		Copy(animatedAndMovableObj);
	}

	return *this;
}

AnimatedAndMovableObj::~AnimatedAndMovableObj()
{
	Clean();
}

void AnimatedAndMovableObj::Move(int screenWidth, int screenHeight)
{
	float x = this->point.GetFirstValue() + this->velocity.GetFirstValue();
	float y = this->point.GetSecondValue() + this->velocity.GetSecondValue();
	this->point.SetValue(x, y);
	
	for (int i = 0; i < this->numberOfAnimatedTiles; i++)
	{
		this->animatedTiles[i]->SetPoint(x, y);
	}
}

void AnimatedAndMovableObj::SetVelocity(float vX, float vY)
{
	this->velocity.SetValue(vX, vY);
}

void AnimatedAndMovableObj::SetState(State* state)
{
	this->state = state;
}