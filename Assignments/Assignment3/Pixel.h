/************************
	Brayden Fidler
	CPSC Section 1, Sp17
	bfidler
*************************/

#ifndef PIXEL_H
#define PIXEL_H
#include "Color.h"
#include "Point.h"
#include <fstream>
using namespace std;


class Pixel
{
  private:
    //member variables
    Color clr;
    Point pt;
   
  public:
    //Default Constructor
    Pixel();
    
    //Setter
    void setColor(unsigned char, unsigned char, unsigned char);
    void setColor(Color);
    void setPoint(double, double);
    
    //Getter
    void printRGB(ofstream&);
    Point getPoint();

};
#endif
