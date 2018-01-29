/************************
	Brayden Fidler
	CPSC Section 1, Sp17
	bfidler
*************************/

#include "Header.h"

//overloaded constructor
Header::Header(string mag, int w, int h, int m)
{
	magic = mag;
	width = w;
	height = h;
	max = m;
}

//Default Constructor
Header::Header()
{
  magic = "";
  width = 0;
  height = 0;
  max = 0;
}

/*prints header to output file in an order that fits the format of ppm images.
  Uses reference to this file for printing.*/
void Header::printHeader(ofstream &output)
{
  output << magic << endl << width << " " << height << " " << max << endl;
}

//returns the width of the header as an integer
int Header::getWidth()
{
  return width;
}

//returns the height of the header as an integer
int Header::getHeight()
{
  return height;
}
