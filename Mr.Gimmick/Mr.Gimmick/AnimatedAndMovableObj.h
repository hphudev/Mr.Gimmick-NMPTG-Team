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
	AnimatedAndMovableObj(float x, float y, int numberOfAnimatedTiles, float vX, float vY);
	void Copy(const AnimatedAndMovableObj& animatedAndMovableObj);
	AnimatedAndMovableObj(const AnimatedAndMovableObj& animatedAndMovableObj);
	void Clean();
	AnimatedAndMovableObj& operator = (const AnimatedAndMovableObj& animatedAndMovableObj);
	~AnimatedAndMovableObj();
	virtual void Move(int screenWidth, int screenHeight);
	void SetVelocity(float vX, float vY);
	void SetState(State* state);
};