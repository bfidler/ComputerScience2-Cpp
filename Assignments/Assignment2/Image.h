/************************
	Brayden Fidler
	CPSC Section 1, Sp17
	bfidler
*************************/

#ifndef IMAGE_H
#define IMAGE_H
#include <fstream>
#include <iostream>
#include <string>
#include "Pixel.h"
#include "Header.h"

class Image
{
  private:
    Pixel aPixel;
    Header aHeader;

  public:
    //Default Constructor
    Image();
    
    //Setters
    void setHeader(string, int, int, int);
    void setPixel(unsigned char, unsigned char, unsigned char);
    void setOnePixel(bool, unsigned char, unsigned char, unsigned char);
    
    //Getters
    void printHeader(ofstream&);
    void printPixel(ofstream&);
   

};
#endif
