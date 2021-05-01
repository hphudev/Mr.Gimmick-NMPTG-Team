#include "UselessObj.h"

UselessObj::UselessObj()
{

}

UselessObj::UselessObj(float x, float y, int numberOfAnimatedTiles) : 
	AnimatedAndImmovableObj(x, y, numberOfAnimatedTiles)
{

}

void UselessObj::Synchronize()
{
	int max = 0, numberOfDrawings;

	for (int i = 0; i < this->numberOfAnimatedTiles; i++)
	{
		numberOfDrawings = this->animatedTiles[i]->GetNumberOfDrawings();

		if (numberOfDrawings > max)
		{
			max = numberOfDrawings;
		}
	}

	for (int i = 0; i < this->numberOfAnimatedTiles; i++)
	{
		this->animatedTiles[i]->SetNumberOfDrawings(max);
	}
}