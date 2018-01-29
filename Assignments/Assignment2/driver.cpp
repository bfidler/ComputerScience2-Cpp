/************************
	Brayden Fidler
	CPSC Section 1, Sp17
	bfidler
*************************/

#include <iostream>
#include <stdlib.h>
#include "Image.h"
using namespace std;
bool checkPoint(Point*, Point&); 

/*The prototype for the client function that determines if the given
 *point is within the parameter of the trianle*/
int main(int argc, char *argv[])
{
  ofstream outPut(argv[2]);
  ifstream inPut(argv[1]);
    
  /*Create an instance of the Image class and Point to represent 
   *the three points that defines the triangle.  Also put other 
   *variables needed here.*/
  Image myPPM;
  Point orTri[3];
  Point wtTri[3];
  Point myPt;
  int width, height;
  double tempX, tempY;
  bool isOrange, isWhite;

  if(argc != 3)
  {
    cout << "USAGE ERROR:  ./executable outPutFileName";
    exit(EXIT_FAILURE);
  }
  if(inPut.fail())
  {
    cout << argv[1] << " did not open successfully\n";
  }

  if(outPut.fail())
  {
    cout << argv[2] << " did not open successfully\n";
  }
    
  /*read the data from the input file here*/
  inPut >> width;
  inPut >> height;
  
  //gets points for original triangle
  for(int i = 0; i < 3; i++){
  
    inPut >> tempX;
    inPut >> tempY;
    orTri[i].setXY(tempX, tempY);
  }
  
  //gets points for triangle overlay
  for(int i = 0; i < 3; i++){
  
    inPut >> tempX;
    inPut >> tempY;
    wtTri[i].setXY(tempX, tempY);
  }
  
      
  /*Using the instance of image created above call the function
   *to set the width and height for the header.  Using the 
   *instance of image call the funtion used to print the header*/
  myPPM.setHeader("P6", width, height, 255);
  myPPM.printHeader(outPut);
    
  /*using nested for loops call the client function to test if
   *the given point is within the parameters of the triangle.  
   *Using the instance of image set the color of the pixels RGB
   *channels and then call the function to print the Pixel to 
   *the output file.*/
  for(int i = 0; i < height; i++) {
  
    for(int j = 0; j < width; j++) {
    
      myPt.setXY(j, i);
      isWhite = checkPoint(wtTri, myPt);
      isOrange = checkPoint(orTri, myPt);
      
      //makes sure white triangle is on top of orange
      if(isWhite == 1) {
      
        myPPM.setOnePixel(isWhite, 255, 255, 255);
      }
      else {
        
        myPPM.setOnePixel(isOrange, 234, 106, 32);
      }
      
      myPPM.printPixel(outPut);
    }
  }
    
    
 
    
    
    
  inPut.close();
  outPut.close();

  return 0;
}

/*Implement the function that determines if a given point is 
 *within the parameter of the triangle*/
 
bool checkPoint(Point *p, Point &test) {
  //Barycentric scalars
	double a,b,c;
	bool check = 0;

	//calculates scalar values
	a = ((p[1].getY() - p[2].getY()) * (test.getX() - p[2].getX()) + (p[2].getX()
    - p[1].getX()) * (test.getY() - p[2].getY())) / ((p[1].getY() - 
    p[2].getY()) * (p[0].getX() - p[2].getX()) + (p[2].getX() - p[1].getX()) *
    (p[0].getY() - p[2].getY()));

	b = ((p[2].getY() - p[0].getY()) * (test.getX() - p[2].getX()) + (p[0].getX()
    - p[2].getX()) * (test.getY() - p[2].getY())) / ((p[1].getY() - 
    p[2].getY()) * (p[0].getX() - p[2].getX()) + (p[2].getX() - p[1].getX()) *
		(p[0].getY() - p[2].getY()));
	
	c = 1 - a - b;
	
	//checks scalar values to confirm if point is in traingle
	if ((a <= 1 && a >= 0) && (b <= 1 && b >= 0) && (c <= 1 && c >= 0))
		check = 1;

	return check;
}
