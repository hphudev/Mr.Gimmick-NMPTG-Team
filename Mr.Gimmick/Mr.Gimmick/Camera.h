#pragma once

#include "TwoDimensionObj.h"
#include "TransformHandler.h"
#include "Yumetaro.h"

class Camera : public TwoDimensionObj
{
public:
	void Update(Yumetaro yumetaro, TwoDimensionObj scene, int tileSize);
	Camera(float x, float y, Dimension);
	Camera();
};