#include "InanimatedTile.h"

InanimatedTile::InanimatedTile()
{

}

InanimatedTile::InanimatedTile(float x, float y, float imageWidth, float imageHeight, 
	LPCWSTR fileImageName) : Tile(x, y)
{
	this->dimension = Dimension(imageWidth, imageHeight);
	this->image = new Image(imageWidth, imageHeight, fileImageName);
}

InanimatedTile::~InanimatedTile()
{
	if (this->surface != NULL)
	{
		this->surface->Release();
	}

	delete this->image;
}

void InanimatedTile::Draw(GraphicDevice graphicDevice, Point cameraPoint, int indexOfRow, bool isRotate, 
	LPDIRECT3DSURFACE9 backbuffer)
{
	RECT destinationRectangle;
	float scale = SCALE;
	float x = (this->point.GetFirstValue() - cameraPoint.GetFirstValue()) * scale;
	float y = (this->point.GetSecondValue() - cameraPoint.GetSecondValue()) * scale;
	Dimension dimension = this->image->GetDimension();
	float width = dimension.GetFirstValue();
	float height = dimension.GetSecondValue();

	if (x != (int)x)
	{
		if (x < 0)
		{
			x = (int)x - 1;
		}
		else
		{
			x = (int)x;
		}
	}

	// Set the surface's rectangle for drawing
	destinationRectangle.left = x;
	destinationRectangle.top = y;
	destinationRectangle.right = x + width;
	destinationRectangle.bottom = y + height;

	// Draw the surface
	graphicDevice.DrawSurface(this->surface, backbuffer, NULL, &destinationRectangle);
}

bool InanimatedTile::Load(D3DXCOLOR transparentColor, DirectXGraphic directXGraphic)
{
	this->surface = directXGraphic.LoadSurface(this->image->GetFilename(), transparentColor);

	if (this->surface == NULL)
	{
		return 0;
	}

	return 1;
}

Tile* InanimatedTile::Clone()
{
	return new InanimatedTile(*this);
}

string InanimatedTile::GetType()
{
	return "InanimatedTile";
}