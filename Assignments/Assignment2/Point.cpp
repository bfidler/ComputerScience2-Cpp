/************************
	Brayden Fidler
	CPSC Section 1, Sp17
	bfidler
*************************/

#include "Point.h"

Point::Point()
{
	x = 0;
	y = 0;
}

void Point::setXY(double x, double y)
{
	this->x = x;
	this->y = y;
}

double Point::getX()
{
	return x;
}

double Point::getY()
{
	return y;
}

