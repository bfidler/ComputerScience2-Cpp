/************************
	Brayden Fidler
	CPSC Section 1, Sp17
	bfidler
*************************/

#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Shape.h"
#include "Point.h"

class Triangle : public Shape
{
  private:
    //member variables
    Point ptA;
    Point ptB;
    Point ptC;
    
  public:
    //Overloaded Constructor
    Triangle(Point, Point, Point, Color);
    //Default Constructor
    Triangle();
    
    //Setter
    void setPoints(Point, Point, Point);
    
    //Getters
    double getAx();
    double getBx();
    double getCx();
    double getAy();
    double getBy();
    double getCy();

};

#endif