/************************
	Brayden Fidler
	CPSC Section 1, Sp17
	bfidler
*************************/

#include "Circle.h"

//Overloaded Constructor
Circle::Circle(Point c, int r, Color clr)
{
  //Memberwise assigment
  center = c;
  radius = r;
  /*inherited membervariable from shape class - is protected so it can
    be assigned in a list*/
  myColor = clr;
}

//Default Constructor
Circle::Circle()
{
  //no values set
}

//Sets the center of the circle using a point
void Circle::setCenter(Point c)
{
  center = c;
}

//Sets the radius of the circle using an integer
void Circle::setRadius(int r)
{
  radius = r;
}

/*returns the x value of the center by calling the getX function from the
  point class*/
double Circle::getCx()
{
  return center.getX();
}

/*returns the x value of the center by calling the getX function from the
  point class*/
double Circle::getCy()
{
  return center.getY();
}

//returns the radius of the circle as an int
int Circle::getRadius()
{
  return radius;
}