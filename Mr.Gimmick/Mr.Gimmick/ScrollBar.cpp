#include "ScrollBar.h"

ScrollBar::ScrollBar()
{

}

ScrollBar::ScrollBar(float x, float y, int numberOfAnimatedTiles) : 
	UselessObj(x, y, numberOfAnimatedTiles)
{

}

string ScrollBar::GetType()
{
	return "ScrollBar";
}