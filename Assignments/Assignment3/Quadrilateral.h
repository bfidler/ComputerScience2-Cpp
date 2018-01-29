/************************
	Brayden Fidler
	CPSC Section 1, Sp17
	bfidler
*************************/

#ifndef QUADRILATERAL_H
#define QUADRILATERAL_H
#include "Shape.h"
#include "Point.h"

class Quadrilateral : public Shape
{
  private:
    //member variables
    Point ptA;
    Point ptB;
    Point ptC;
    Point ptD;
    
  public:
    //Overloaded Constructor
    Quadrilateral(Point, Point, Point, Point, Color);
    //Default Constructor
    Quadrilateral();
    
    //Setter
    void setPoints(Point, Point, Point, Point);
    
    //Getters
    double getAx();
    double getBx();
    double getCx();
    double getAy();
    double getBy();
    double getCy();
    double getDx();
    double getDy();

};

#endif