/************************
	Brayden Fidler
	CPSC Section 1, Sp17
	bfidler
*************************/

#include "Quadrilateral.h"

//Overloaded Constructor
Quadrilateral::Quadrilateral(Point a, Point b, Point c, Point d, Color clr)
{
  //Memberwise assigment
  ptA = a;
  ptB = b;
  ptC = c;
  ptD = d;
  /*inherited member variable from shape class - is protected so it can
    be assigned in a list*/
  myColor = clr;
}

//Default Constructor
Quadrilateral::Quadrilateral()
{  
  //No values set
}

//Sets the 3 points of Quadrilateral by assigment
void Quadrilateral::setPoints(Point a, Point b, Point c, Point d)
{
  ptA = a;
  ptB = b;
  ptC = c;
  ptD = d;
}

//Returns x coordinate of 1st point of the Quadrilateral
double Quadrilateral::getAx()
{
  return ptA.getX();
}

//Returns x coordinate of 2nd point of the Quadrilateral
double Quadrilateral::getBx()
{
  return ptB.getX();
}

//Returns x coordinate of 3rd point of the Quadrilateral
double Quadrilateral::getCx()
{
  return ptC.getX();
}

//Returns x coordinate of 4th point of the Quadrilateral
double Quadrilateral::getDx()
{
  return ptD.getX();
}

//Returns y coordinate of 1st point of the Quadrilateral
double Quadrilateral::getAy()
{
  return ptA.getY();
}

//Returns y coordinate of 2nd point of the Quadrilateral
double Quadrilateral::getBy()
{
  return ptB.getY();
}

//Returns y coordinate of 3rd point of the Quadrilateral
double Quadrilateral::getCy()
{
  return ptC.getY();
}

//Returns y coordinate of 4th point of the Quadrilateral
double Quadrilateral::getDy()
{
  return ptD.getY();
}
