#include "TwoDimensionObj.h"

TwoDimensionObj::TwoDimensionObj()
{

}

TwoDimensionObj::TwoDimensionObj(float x, float y)
{
	this->point = Point(x, y);
}

void TwoDimensionObj::SetPoint(float x, float y)
{
	this->point.SetValue(x, y);
}