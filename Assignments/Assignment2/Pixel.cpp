/************************
	Brayden Fidler
	CPSC Section 1, Sp17
	bfidler
*************************/

#include "Pixel.h"

Pixel::Pixel() 
{
	Color newClr;
	Point newPt;
	clr = newClr;
	pt = newPt;
}

void Pixel::setOneColor(bool isOne, unsigned char r, unsigned char g,
  unsigned char b)
{
	//Color set to purple if false, other color if true
	if(isOne == 1){
		
		clr.setRGB(r, g, b);
	}
	else{
 
		clr.setRGB(82, 45, 128);
	}
}

void Pixel::setColor(unsigned char r, unsigned char g, unsigned char b)
{
	clr.setRGB(r, g, b);
}

void Pixel::printRGB(ofstream &output)
{
	output << clr.getRed() << clr.getGreen() << clr.getBlue();
}
