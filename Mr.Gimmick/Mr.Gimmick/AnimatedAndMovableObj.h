#pragma once

#include "AnimatedObj.h"
#include "Velocity.h"
#include "IdleState.h"

class AnimatedAndMovableObj : public AnimatedObj
{
protected:
	Velocity velocity;
	State* state;
public:
	AnimatedAndMovableObj();
	AnimatedAndMovableObj(float x, float y, float vX, float vY);
	~AnimatedAndMovableObj();
	virtual void Move(int screenWidth, int screenHeight);
	void SetVelocity(float vX, float vY);
	void SetState(State* state);
};