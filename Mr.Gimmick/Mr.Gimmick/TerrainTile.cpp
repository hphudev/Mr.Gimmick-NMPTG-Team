#include "TerrainTile.h"

TerrainTile::TerrainTile()
{

}

TerrainTile::TerrainTile(float x, float y, float imageWidth, float imageHeight, LPCWSTR fileImageName) 
	: InanimatedTile(x, y, imageWidth, imageHeight, fileImageName)
{

}