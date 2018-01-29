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
    Color clr;
    Point pt;
   
  public:
    //Default Constuctor
    Pixel();
    
    //Setter
    void setOneColor(bool, unsigned char, unsigned char, unsigned char);
    void setColor(unsigned char, unsigned char, unsigned char);
    void setPoint(Point);
    
    //Getter
    void printRGB(ofstream&);

};
#endif
