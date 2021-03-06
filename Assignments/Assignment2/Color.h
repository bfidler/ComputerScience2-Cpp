/************************
	Brayden Fidler
	CPSC Section 1, Sp17
	bfidler
*************************/

#ifndef COLOR_H
#define COLOR_H

class Color
{
  private:
    unsigned char red;
    unsigned char green;
    unsigned char blue;
    
  public:
    //Default constructor
    Color();
    
    //Setter
    void setRGB(unsigned char, unsigned char, unsigned char);
    
    //Getters
    unsigned char getRed();
    unsigned char getGreen();
    unsigned char getBlue();
    
};

#endif
