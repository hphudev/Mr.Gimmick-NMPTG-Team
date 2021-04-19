#include "MovableObj.h"

MovableObj::MovableObj()
{

}

MovableObj::MovableObj(float x, float y, float vX, float vY) : GameObj(x, y)
{
	this->velocity = Velocity(vX, vY);
}

MovableObj::~MovableObj()
{
	// ?
	/*MovableTile* tile;

	while (!this->tiles.empty())
	{
		tile = this->tiles.back();
		delete tile;
		this->tiles.pop_back();
	}*/
	// ?
}

void MovableObj::Move(int screenWidth, int screenHeight)
{
	float x = this->point.GetFirstValue() + this->velocity.GetFirstValue();
	float y = this->point.GetSecondValue() + this->velocity.GetSecondValue();
	this->point.SetValue(x, y);
	MovableTile* tile;
	int length = this->tiles.size();

	for (int i = 0; i < length; i++)
	{
		tile = this->tiles.back();
		tile->SetPoint(x, y);
		this->tiles.pop_back();
		this->tiles.push_front(tile);
	}

	this->tiles.reverse();
}

void MovableObj::Draw(int indexOfRow, bool isRotate, GraphicDevice graphicDevice)
{
	int length = this->tiles.size();
	MovableTile* movableTile;

	for (int i = 0; i < length; i++)
	{
		movableTile = this->tiles.back();
		movableTile->Draw(indexOfRow, 0, graphicDevice);
		this->tiles.pop_back();
		this->tiles.push_front(movableTile);
	}

	this->tiles.reverse();
}

void MovableObj::SetVelocity(float vX, float vY)
{
	this->velocity.SetValue(vX, vY);
}