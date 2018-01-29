/************************
	Brayden Fidler
	CPSC Section 1, Sp17
	bfidler
*************************/

#include "Triangle.h"

//Overloaded Constructor
Triangle::Triangle(Point a, Point b, Point c, Color clr)
{
  //Memberwise assigment
  ptA = a;
  ptB = b;
  ptC = c;
  /*inherited member variable from shape class - is protected so it can
    be assigned in a list*/
  myColor = clr;
}

//Default Constructor
Triangle::Triangle()
{  
  //No values set
}

//Sets the 3 points of triangle by assigment
void Triangle::setPoints(Point a, Point b, Point c)
{
  ptA = a;
  ptB = b;
  ptC = c;
}

//Returns x coordinate of 1st point of the triangle
double Triangle::getAx()
{
  return ptA.getX();
}

//Returns x coordinate of 2nd point of the triangle
double Triangle::getBx()
{
  return ptB.getX();
}

//Returns x coordinate of 3rd point of the triangle
double Triangle::getCx()
{
  return ptC.getX();
}

//Returns y coordinate of 1st point of the triangle
double Triangle::getAy()
{
  return ptA.getY();
}

//Returns y coordinate of 2nd point of the triangle
double Triangle::getBy()
{
  return ptB.getY();
}

//Returns y coordinate of 3rd point of the triangle
double Triangle::getCy()
{
  return ptC.getY();
}
