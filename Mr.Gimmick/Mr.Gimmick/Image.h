#pragma once

#include <d3d9.h>
#include "Dimension.h"

class Image
{
protected:
	Dimension dimension;
	LPCWSTR filename;
public:
	Image();
	Image(float width, float height, LPCWSTR filename);
	Dimension GetDimension();
	LPCWSTR GetFilename();
};