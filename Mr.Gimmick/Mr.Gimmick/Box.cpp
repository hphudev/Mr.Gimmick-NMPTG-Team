#include "Box.h"

Box::Box()
{

}

Box::Box(Point point, Dimension dimension, Velocity velocity)
{
	this->point = point;
	this->velocity = velocity;
	this->dimension = dimension;
}

bool Box::AABBCheck(Box box)
{
	float x1 = this->point.GetFirstValue(), x2 = box.point.GetFirstValue();
	float width1 = this->dimension.GetFirstValue(), width2 = box.dimension.GetFirstValue();
	float y1 = this->point.GetSecondValue(), y2 = box.point.GetSecondValue();
	float height1 = this->dimension.GetSecondValue(), height2 = box.dimension.GetSecondValue();

	return !(x1 + width1 < x2 || x2 + width2 < x1 || y1 + height1 < y2 || y2 + height2 < y1);
}

//
//void FindDistance(float coordinate1, float coordinate2, float dimension1, float dimension2, 
//    float& distance1, float& distance2)
//{
//    distance1 = coordinate2 - (coordinate1 + dimension1);
//    distance2 = (coordinate2 + dimension2) - coordinate1;
//}
//
//float Box::SweptAABB(Box obstacle, float& normalX, float& normalY)
//{
//    // Tìm khoảng cách để xảy ra va chạm và khoảng cách để đi qua vật cản
//    float distanceToAppearCollisionX, distanceToAppearCollisionY;
//    float distanceToPassObstacleX, distanceToPassObstacleY;
//    float distance1, distance2;
//
//    FindDistance(this->x, obstacle.x, this->width, obstacle.width, distance1, distance2);
//    distanceToAppearCollisionX = this->moveX > 0.0f ? distance1 : distance2;
//    distanceToPassObstacleX = this->moveX > 0.0f ? distance2 : distance1;
//
//    FindDistance(this->y, obstacle.y, this->height, obstacle.height, distance1, distance2);
//    distanceToAppearCollisionY = this->moveY > 0.0f ? distance1 : distance2;
//    distanceToPassObstacleY = this->moveY > 0.0f ? distance2 : distance1;
//
//    // Tìm thời gian va chạm và thời gian rời khỏi mỗi trục (mệnh đề if để xử lý trường hợp chia cho 0)
//    return 0.0f;
//}