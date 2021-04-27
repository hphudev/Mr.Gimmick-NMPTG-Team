#include "ImmovableTile.h"

ImmovableTile::ImmovableTile()
{

}

ImmovableTile::ImmovableTile(float x, float y, float imageWidth, float imageHeight, 
	LPCWSTR fileImageName) : Tile(x, y)
{
	this->image = new Image(imageWidth, imageHeight, fileImageName);
}

ImmovableTile::~ImmovableTile()
{
	if (this->surface != NULL)
	{
		// ?
		//this->surface->Release();
		// ?
	}

	// ?
	//delete this->image;
	// ?
}

void ImmovableTile::Draw(GraphicDevice graphicDevice, int indexOfRow, bool isRotate, 
	LPDIRECT3DSURFACE9 backbuffer)
{
	RECT destinationRectangle;
	float scale = SCALE;
	float x = this->point.GetFirstValue() * scale;
	float y = this->point.GetSecondValue() * scale;
	Dimension dimension = this->image->GetDimension();
	float width = dimension.GetFirstValue();
	float height = dimension.GetSecondValue();

	// Set the surface's rectangle for drawing
	destinationRectangle.left = x;
	destinationRectangle.top = y;
	destinationRectangle.right = x + width;
	destinationRectangle.bottom = y + height;

	// Draw the surface
	graphicDevice.DrawSurface(this->surface, backbuffer, NULL, &destinationRectangle);
}

bool ImmovableTile::Load(D3DXCOLOR transparentColor, DirectXGraphic directXGraphic)
{
	this->surface = directXGraphic.LoadSurface(this->image->GetFilename(), transparentColor);

	if (this->surface == NULL)
	{
		return 0;
	}

	return 1;
}