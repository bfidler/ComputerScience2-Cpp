/************************
	Brayden Fidler
	CPSC Section 1, Sp17
	bfidler
*************************/

#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"
#include "Point.h"

class Circle : public Shape
{
  private:
    //member variable
    Point center;
    int radius;
    
  public:
    //Overloaded Constructor
    Circle(Point, int, Color);
    //Default Constructor
    Circle();
    
    //Setter
    void setCenter(Point);
    void setRadius(int);
    
    //Getters
    double getCx();
    double getCy();
    int getRadius();

};

#endif