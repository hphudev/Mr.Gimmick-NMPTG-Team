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
	Box GetBox();
	Dimension GetDimension();
	TwoDimensionObj();
	TwoDimensionObj(float x, float y);
	Point GetPoint();
	void SetPoint(float x, float y);
};