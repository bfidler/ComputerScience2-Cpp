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
    //member variables
    string magic;
    int width;
    int height;
    int max;

  public:
    //Overloaded Constructor
    Header(string, int, int, int);
    //Default Constructor
    Header();
    
    //Getters
    void printHeader(ofstream&);
    int getWidth();
    int getHeight();
    
};

#endif
