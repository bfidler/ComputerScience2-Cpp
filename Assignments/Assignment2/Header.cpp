/************************
	Brayden Fidler
	CPSC Section 1, Sp17
	bfidler
*************************/

#include "Header.h"

Header::Header()
{
	magic = "";
	width = 0;
	height = 0;
	max = 0;
}

void Header::setMagic(string m)
{
	magic = m;
}

void Header::setWidth(int w)
{
	width = w;
}

void Header::setHeight(int h)
{
	height = h;
}

void Header::setMax(int m)
{
	max = m;
}

void Header::printHeader(ofstream &output)
{
  output << magic << endl << width << " " << height << " " << max << endl;
}

