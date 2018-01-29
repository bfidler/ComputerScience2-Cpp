/************************
	Brayden Fidler
	CPSC Section 1, Sp17
	bfidler
*************************/

#ifndef SHAPE_H
#define SHAPE_H
#include "Color.h"

class Shape
{
  protected:
    //member variables
    Color myColor;
  public:
    //Overloaded Constructor
    Shape(Color);
    //Defualt Constructor
    Shape();
    
    //Setters
    void setColor(Color);
    void setColor(unsigned char, unsigned char, unsigned char);
    
    //Getters
    Color getColor();

};

#endif