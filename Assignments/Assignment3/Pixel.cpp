/************************
	Brayden Fidler
	CPSC Section 1, Sp17
	bfidler
*************************/

#include "Pixel.h"

//Default Constructor
Pixel::Pixel() 
{
  //no values set
}

/*Sets the color of the pixel using 3 unsigned chars and passing the values
  using a setter function from the Color class*/
void Pixel::setColor(unsigned char r, unsigned char g, unsigned char b)
{
	clr.setRGB(r, g, b);
}

//Sets the color of the pixel by copying a color object to the member variable
void Pixel::setColor(Color myClr)
{
  clr = myClr;
}

/*Sets the point of the pixel by passing the xy value to the setXY function of
  the point class*/
void Pixel::setPoint(double x, double y)
{
  pt.setXY(x, y);
}

/*Prints rgb values back to back to back to output file by using the get
  functions in the Color class for each color value*/
void Pixel::printRGB(ofstream &output)
{
	output << clr.getRed() << clr.getGreen() << clr.getBlue();
}

//Gets the Point value of the Pixel
Point Pixel::getPoint()
{
  return pt;
}
