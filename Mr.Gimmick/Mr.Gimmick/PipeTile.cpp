#include "PipeTile.h"

PipeTile::PipeTile()
{

}

PipeTile::PipeTile(float x, float y, float imageWidth, float imageHeight, LPCWSTR fileImageName) 
	: ImmovableTile(x, y, imageWidth, imageHeight, fileImageName)
{

}