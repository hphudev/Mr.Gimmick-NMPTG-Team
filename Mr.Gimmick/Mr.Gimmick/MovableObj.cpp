#include "MovableObj.h"

MovableObj::MovableObj()
{

}

MovableObj::MovableObj(float x, float y, float vX, float vY) : GameObj(x, y)
{
	this->velocity = Velocity(vX, vY);
	this->state = new IdleState();
}

MovableObj::~MovableObj()
{
	// ?
	/*AnimatedTile* animatedTile;

	while (!this->tiles.empty())
	{
		animatedTile = this->tiles.back();
		delete animatedTile;
		this->tiles.pop_back();
	}*/
	// ?
}

void MovableObj::Move(int screenWidth, int screenHeight)
{
	float x = this->point.GetFirstValue() + this->velocity.GetFirstValue();
	float y = this->point.GetSecondValue() + this->velocity.GetSecondValue();
	this->point.SetValue(x, y);
	AnimatedTile* animatedTile;
	int length = this->tiles.size();

	for (int i = 0; i < length; i++)
	{
		animatedTile = this->tiles.back();
		animatedTile->SetPoint(x, y);
		this->tiles.pop_back();
		this->tiles.push_front(animatedTile);
	}

	this->tiles.reverse();
}

void MovableObj::Draw(int indexOfRow, bool isRotate, GraphicDevice graphicDevice)
{
	int length = this->tiles.size();
	AnimatedTile* animatedTile;

	for (int i = 0; i < length; i++)
	{
		animatedTile = this->tiles.back();
		animatedTile->Draw(graphicDevice, indexOfRow);
		this->tiles.pop_back();
		this->tiles.push_front(animatedTile);
	}

	this->tiles.reverse();
}

void MovableObj::SetVelocity(float vX, float vY)
{
	this->velocity.SetValue(vX, vY);
}

void MovableObj::SetState(State* state)
{
	this->state = state;
}