#include "Waterfall.h"

Waterfall::Waterfall()
{

}

Waterfall::Waterfall(float x, float y, int numberOfAnimatedTiles, int gameObjID) : UselessObj(x, y, 
	numberOfAnimatedTiles, gameObjID)
{

}

string Waterfall::GetType()
{
	return "Waterfall";
}

UselessObj* Waterfall::Clone()
{
	return new Waterfall(*this);
}