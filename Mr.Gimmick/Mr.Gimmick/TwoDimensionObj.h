#pragma once

#include <d3dx9.h>
#include "Point.h"
#include "Image.h"
#include "Box.h"

class TwoDimensionObj
{
protected:
	Point point;
	Dimension dimension;
public:
	void SetFirstValueOfPoint(int firstValueOfPoint);
	void SetFirstValueOfDimension(int firstValueOfDimension);
	void IncreaseValueOfPoint(int additionalFirstValue, int additionalSecondValue);
	void IncreaseSecondValueOfPoint(int additionalSecondValue);
	void IncreaseFirstValueOfPoint(int additionalFirstValue);
	TwoDimensionObj();
	TwoDimensionObj(float x, float y);
	Point GetPoint();
	void SetPoint(float x, float y);
	Dimension GetDimension();
	Box GetBox();
	void SetDimension(Dimension dimension);
};