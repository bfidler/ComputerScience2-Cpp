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
#include "Triangle.h"
#include "Circle.h"
#include "Quadrilateral.h"
#include <vector>
#include <cmath>

class Image
{
  private:
    //member variables
    Pixel **Pixels;
    Header aHeader;

  public:
    //Overloaded Constructor
    Image(string, int, int, int);
    //Copy Constructor
    Image(const Image&);
    //Overloaded Operator
    Image operator=(const Image&);
    //Destructor
    ~Image();
    
    //Setters
    void setBackground(Color);
    void setStripes(Color, Color);
    void setTriangles(vector<Triangle>&);
    void setCircles(vector<Circle>&);
    void setQuadrilaterals(vector<Quadrilateral>&);
    
    //Getters
    Header getHeader();
    void printHeader(ofstream&);
    void printPixels(ofstream&);

};
#endif
