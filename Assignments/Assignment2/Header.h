/************************
	Brayden Fidler
	CPSC Section 1, Sp17
	bfidler
*************************/

#ifndef HEADER_H
#define HEADER_H
#include <string>
#include <fstream>
using namespace std;


class Header
{
  private:
    string magic;
    int width;
    int height;
    int max;

  public:
    //Default Constructor
    Header();
    
    //Setters
    void setMagic(string);
    void setWidth(int);
    void setHeight(int);
    void setMax(int);
    
    //Getter
    void printHeader(ofstream&);
    
};

#endif
