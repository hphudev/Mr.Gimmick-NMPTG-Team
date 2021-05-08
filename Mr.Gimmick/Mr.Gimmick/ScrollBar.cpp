#include "ScrollBar.h"

ScrollBar::ScrollBar()
{

}

ScrollBar::ScrollBar(float x, float y, int numberOfAnimatedTiles, int gameObjID) : UselessObj(x, y,
	numberOfAnimatedTiles, gameObjID)
{

}

string ScrollBar::GetType()
{
	return "ScrollBar";
}

UselessObj* ScrollBar::Clone()
{
	return new ScrollBar(*this);
}