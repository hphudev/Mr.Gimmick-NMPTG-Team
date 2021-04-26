#pragma once

#include "GameObj.h"
#include "Velocity.h"
#include "MovableTile.h"
#include "IdleState.h"

class MovableObj : public GameObj
{
protected:
	Velocity velocity;
	list<MovableTile*> tiles;
	State* state;
public:
    MovableObj();
    MovableObj(float x, float y, float vX, float vY);
	~MovableObj();
	virtual void Move(int screenWidth, int screenHeight);
	void Draw(int indexOfRow, bool isRotate, GraphicDevice graphicDevice);
	void SetVelocity(float vX, float vY);
	void SetState(State* state);
};