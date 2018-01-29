/************************
	Brayden Fidler
	CPSC Section 1, Sp17
	bfidler
*************************/

#include "Color.h"

Color::Color()
{
  red = 0;
  green = 0;
  blue = 0;
}

void Color::setRGB(unsigned char r, unsigned char g, unsigned char b) 
{
	red = r;
	green = g;
	blue = b;
}

unsigned char Color::getRed()
{
	return red;
}

unsigned char Color::getGreen()
{
	return green;
}

unsigned char Color::getBlue()
{
	return blue;
}
