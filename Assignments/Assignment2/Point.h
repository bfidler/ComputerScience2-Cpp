/************************
	Brayden Fidler
	CPSC Section 1, Sp17
	bfidler
*************************/

#ifndef POINT_H
#define POINT_H

class Point
{
    private:
      double x;
      double y;

    public:
      //Default Constructor
      Point();
      
      //Setter
      void setXY(double, double);
      
      //Getters
      double getX();
      double getY();
    
};
#endif
