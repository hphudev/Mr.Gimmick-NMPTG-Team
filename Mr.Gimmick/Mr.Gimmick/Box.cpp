#include "Box.h"

Box::Box(float x, float y, float vX, float vY, float width, float height)
{
	this->point = Point(x, y);
	this->velocity = Velocity(vX, vY);
	this->dimension = Dimension(width, height);
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