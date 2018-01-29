/************************
	Brayden Fidler
	CPSC Section 1, Sp17
	bfidler
*************************/

#include "Point.h"

//default constructor
Point::Point()
{
	x = 0;
	y = 0;
}

//sets X and Y coordinate of point using 2 doubles
void Point::setXY(double x, double y)
{
	this->x = x;
	this->y = y;
}

//returns x coordinate value
double Point::getX()
{
	return x;
}

//returns y coordinate value
double Point::getY()
{
	return y;
}

