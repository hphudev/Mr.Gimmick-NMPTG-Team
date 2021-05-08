#include "PlayableObj.h"

PlayableObj::PlayableObj()
{

}

PlayableObj::PlayableObj(float x, float y, int numberOfAnimatedTiles, float vX, float vY, int gameObjID) 
	: AnimatedAndMovableObj(x, y, numberOfAnimatedTiles, vX, vY, gameObjID)
{

}