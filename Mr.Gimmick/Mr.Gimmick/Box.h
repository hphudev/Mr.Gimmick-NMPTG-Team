#pragma once

#include "Point.h"
#include "Dimension.h"
#include "Velocity.h"

// Describes an axis-aligned rectangle with a velocity
class Box
{
private:
	// Position of top-left corner, dimensions and velocity
	Point point;
	Velocity velocity;
	Dimension dimension;
public:
	Box();
	Box(Point point, Dimension dimension, Velocity velocity = Velocity());
	bool AABBCheck(Box box);
	//float SweptAABB(Box obstacle, Vector<float>& normal);
};