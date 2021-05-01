#include "TwoDimensionObj.h"

TwoDimensionObj::TwoDimensionObj()
{

}

TwoDimensionObj::TwoDimensionObj(float x, float y)
{
	this->point = Point(x, y);
}

Point TwoDimensionObj::GetPoint()
{
	return this->point;
}

void TwoDimensionObj::SetPoint(float x, float y)
{
	this->point.SetValue(x, y);
}