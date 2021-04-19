#include "SceneryTile.h"

SceneryTile::SceneryTile()
{

}

SceneryTile::SceneryTile(float x, float y, float imageWidth, float imageHeight, LPCWSTR fileImageName) 
	: ImmovableTile(x, y, imageWidth, imageHeight, fileImageName)
{

}