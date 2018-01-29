/************************
	Brayden Fidler
	CPSC Section 1, Sp17
	bfidler
*************************/

#include "Color.h"

//overloaded constructor
Color::Color(unsigned char r, unsigned char g, unsigned char b)
{
	red = r;
	green = g;
	blue = b;
}

//default constructor
Color::Color()
{
  red = 0;
  green = 0;
  blue = 0;
}

//sets red, green, and blue values of color using 3 unsigned chars
void Color::setRGB(unsigned char r, unsigned char g, unsigned char b) 
{
	red = r;
	green = g;
	blue = b;
}

//returns red value of color
unsigned char Color::getRed()
{
	return red;
}

//returns green value of color
unsigned char Color::getGreen()
{
	return green;
}

//returns blue value of color
unsigned char Color::getBlue()
{
	return blue;
}
