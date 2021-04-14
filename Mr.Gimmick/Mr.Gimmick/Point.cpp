#include "Point.h"

template <typename T>
Point<T>::Point()
{
	this->x = this->y = 0;
}

template <typename T>
Point<T>::Point(T x, T y)
{
	this->x = x;
	this->y = y;
}