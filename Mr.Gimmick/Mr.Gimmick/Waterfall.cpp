#include "Waterfall.h"

Waterfall::Waterfall()
{

}

Waterfall::Waterfall(float x, float y, int numberOfAnimatedTiles) : 
	UselessObj(x, y, numberOfAnimatedTiles)
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