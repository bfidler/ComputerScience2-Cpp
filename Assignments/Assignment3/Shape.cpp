/************************
	Brayden Fidler
	CPSC Section 1, Sp17
	bfidler
*************************/

#include "Shape.h"

//Overloaded Constructor
Shape::Shape(Color clr)
{
  myColor = clr;
}

//Default Constructor
Shape::Shape()
{
  //no values set
}

//Sets the color of the shape by copying a color object to the member variable
void Shape::setColor(Color clr)
{
  myColor = clr;
}

/*Sets the color of the shaper by passing three unisgned chars to the setRGB 
  function of the Color class*/
void Shape::setColor(unsigned char r, unsigned char g, unsigned char b)
{
  myColor.setRGB(r, g, b);
}

//returns the color of the shape
Color Shape::getColor()
{
  return myColor;
}

