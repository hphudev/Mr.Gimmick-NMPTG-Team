#pragma once

#include <d3dx9.h>
#include "Point.h"
#include "Image.h"

class TwoDimensionObj
{
protected:
	Point point;
public:
	TwoDimensionObj();
	TwoDimensionObj(float x, float y);
	Point GetPoint();
	void SetPoint(float x, float y);
};