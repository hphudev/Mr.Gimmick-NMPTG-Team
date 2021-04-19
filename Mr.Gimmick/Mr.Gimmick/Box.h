#pragma once

#include "Point.h"
#include "Dimension.h"
#include "Velocity.h"
#include "Vector.h"

// Describes an axis-aligned rectangle with a velocity
class Box
{
private:
	// Position of top-left corner, dimensions and velocity
	Point point;
	Velocity velocity;
	Dimension dimension;
public:
	Box(float x, float y, float vX, float vY, float width, float height);
	//float SweptAABB(Box obstacle, Vector<float>& normal);
};