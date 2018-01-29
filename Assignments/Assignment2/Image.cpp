/************************
	Brayden Fidler
	CPSC Section 1, Sp17
	bfidler
*************************/

#include "Image.h"

Image::Image()
{
	Pixel p;
	Header h;
	aPixel = p;
	aHeader = h;
}

void Image::setHeader(string mag, int w, int h, int m)
{
	aHeader.setMagic(mag);
	aHeader.setWidth(w);
	aHeader.setHeight(h);
	aHeader.setMax(m);
}

void Image::setPixel(unsigned char r, unsigned char g, unsigned char b)
{
	aPixel.setColor(r, g, b);
}

void Image::setOnePixel(bool isOne, unsigned char r, unsigned char g,
	unsigned char b)
{
	aPixel.setOneColor(isOne, r, g, b);
}

void Image::printHeader(ofstream& output)
{
	aHeader.printHeader(output);
}

void Image::printPixel(ofstream& output)
{
  aPixel.printRGB(output);
}

