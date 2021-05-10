#include "Camera.h"

void Camera::Update(Yumetaro yumetaro, TwoDimensionObj scene, int tileSize)
{
	float lim[2];
	lim[0] = scene.GetPoint().GetFirstValue();
	lim[1] = lim[0] + scene.GetDimension().GetFirstValue();

	if (this->point.GetFirstValue() + this->dimension.GetFirstValue() <= lim[1] || 
		yumetaro.GetPoint().GetFirstValue() <= lim[1] - 8 * tileSize - 
		yumetaro.GetDimension().GetFirstValue() / 2)
	{
		this->point.SetFirstValue(yumetaro.GetPoint().GetFirstValue() - 
			(this->dimension.GetFirstValue() - yumetaro.GetDimension().GetFirstValue()) / 2.0f);
	}

	if (this->point.GetFirstValue() < lim[0])
	{
		this->point.SetFirstValue(lim[0]);
	}

	if (this->point.GetFirstValue() > lim[1])
	{
		this->point.SetFirstValue(lim[1]);
	}
}

Camera::Camera(float x, float y, Dimension dimension) : TwoDimensionObj(x, y)
{
	this->dimension = dimension;
}

Camera::Camera()
{
	
}