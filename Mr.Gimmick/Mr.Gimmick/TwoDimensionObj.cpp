#include "TwoDimensionObj.h"

void TwoDimensionObj::SetFirstValueOfPoint(int firstValueOfPoint)
{
	this->point.SetFirstValue(firstValueOfPoint);
}

void TwoDimensionObj::SetFirstValueOfDimension(int firstValueOfDimension)
{
	this->dimension.SetFirstValue(firstValueOfDimension);
}

void TwoDimensionObj::IncreaseValueOfPoint(int additionalFirstValue, int additionalSecondValue)
{
	this->point.IncreaseValue(additionalFirstValue, additionalSecondValue);
}

void TwoDimensionObj::IncreaseSecondValueOfPoint(int additionalSecondValue)
{
	this->point.IncreaseSecondValue(additionalSecondValue);
}

void TwoDimensionObj::IncreaseFirstValueOfPoint(int additionalFirstValue)
{
	this->point.IncreaseFirstValue(additionalFirstValue);
}

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

Dimension TwoDimensionObj::GetDimension()
{
	return this->dimension;
}

Box TwoDimensionObj::GetBox()
{
	return Box(this->point, this->dimension);
}

void TwoDimensionObj::SetDimension(Dimension dimension)
{
	this->dimension = dimension;
}