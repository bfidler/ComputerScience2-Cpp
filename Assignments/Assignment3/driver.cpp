/***************************
	Brayden Fidler
	CPSC 1020 Section 1, sp17
	bfidler
****************************/

#include "Image.h"
#include <stdlib.h>
using namespace std;

//Function Prototypes
void readHW(int&, int&, ifstream&);
void readShapes(vector<Triangle>&, vector<Circle>&, vector<Quadrilateral>&,
  ifstream&);
void readTriangle(vector<Triangle>&, ifstream&);
void readCircle(vector<Circle>&, ifstream&);
void readQuadrilateral(vector<Quadrilateral>&, ifstream&);
void checkPoints(vector<Triangle>&, vector<Circle>&, vector<Quadrilateral>&,
  Image&);
void checkTriangle(Triangle&, double, double);
void checkCircle(Circle&, double, double);
void checkQuadrilateral(Quadrilateral &, double, double);

int main(int argc, char *argv[]) {
	/*Checks to ensure that the correct number of command line arguments 
    were entered; exits the program otherwise*/
  if(argc != 3)
  {
    cout << "Error Opening Files";
    exit(EXIT_FAILURE);
  }

  /*Creates output and input file streams opening to the two names of
    the files on the command line*/
  ofstream output(argv[2]);
  ifstream input(argv[1]);
  
  /*Exits the program if either the input file or the output file fails to 
    open properly*/
  if(input.fail())
  {
    cout << argv[1] << " did not open successfully\n";
  }

  if(output.fail())
  {
    cout << argv[2] << " did not open successfully\n";
  }
  
  /*Width and height are created. 
    Vectors for each type of shape are created.
    Colors for image background created.*/ 
  int width, height;
  vector<Triangle> myTris;
  vector<Circle> myCirs;
  vector<Quadrilateral> myQuads;
  Color orange(234, 106, 32);
  Color black(0, 0, 0);
  
  /*Values of width and height are gotten from the input file
    using the readHeader function and used to create a ppm. Background
    of ppm is then set to horizontal stripes.*/
  readHW(width, height, input);
  Image myPPM("P6", width, height, 255);
  myPPM.setStripes(black, orange);
  
  //Reads the input file and puts the shapes read into the vectors
  readShapes(myTris, myCirs, myQuads, input);
  //Checks to make sure the shapes fall within the image
  checkPoints(myTris, myCirs, myQuads, myPPM);
  
  /*these next 3 function calls pass the image vectors to member functions
    which put the shapes in the image*/
  myPPM.setTriangles(myTris);
  myPPM.setQuadrilaterals(myQuads);
  myPPM.setCircles(myCirs);
  
  
  //printing image to the output file by calling member functions of image
  myPPM.printHeader(output);
  myPPM.printPixels(output);
  
  //Closing input and output files
  output.close();
  input.close();
    
	return 0;
}

/*Function takes references of height and width as well as an input file.
  It assumes both variables are at the top of the file and reads them in 
  directly.*/
void readHW(int &w, int &h, ifstream &input)
{
  input >> w;
  input >> h;
}

/*Takes the input file and reads it line by line filling the shape vectors 
  with each shape read*/
void readShapes(vector<Triangle> &tris, vector<Circle>& circs, vector<Quadrilateral>& quads, ifstream &input)
{
  //string created to identify which shape is being read each time
  string theShape;
  /*The loop will run until EOF is reached then stop. Getline reads from the
    input and a string(theShape) will be given the name of the shape(ideally). 
    Using the shape's name a function will be called to continue reading the 
    information. If whitespace is read, the next line will be read. There 
    is no "default" else so the loop will just continue*/
  while(getline(input, theShape))
  {
    if(theShape == "Triangle")
    {
      readTriangle(tris, input);
    }
    else if(theShape == "Quadrilateral")
    {
      readQuadrilateral(quads, input);
    }
    else if(theShape == "Circle")
    {
      readCircle(circs, input);
    }
  } 
}

//Reads a single Triangle from the input file into the Triangle vector
void readTriangle(vector<Triangle> &tris, ifstream& input)
{
  //Color and points created to be passed to Triangle
  Point pts[3];
  Color white(255, 255, 255);
  //doubles to be passed to each point
  double x, y;
  
  //each of the 3 points is read 
  for(int i = 0; i < 3; i++)
  {
    input >> x;
    input >> y;
    pts[i].setXY(x, y);
  }
  
  //points and color are given to a Triangle, which is then added to the vector
  Triangle newTri(pts[0], pts[1], pts[2], white);
  tris.push_back(newTri);
}

//Reads one circle from the input file into the circle vector
void readCircle(vector<Circle> &cir, ifstream& input)
{
  //Color, radius, and point created for circle
  Point center;
  Color red(255, 0, 0);
  int radius;
  //doubles for the coordinates of the point
  double x, y;
  
  //reading point and reading radius from input
  input >> x;
  input >> y;
  input >> radius; 
  center.setXY(x, y);
 
  //A circle is created with the info from the file and added to the vector 
  Circle newCircle(center, radius, red);
  cir.push_back(newCircle);
}

//Reads a single Quadrilateral from the input file into the Quadrilateral vector
void readQuadrilateral(vector<Quadrilateral> &quads, ifstream& input)
{
  //Color and points created to be passed to Quadrilateral
  Point pts[4];
  Color blue(0, 0, 255);
  //doubles to be passed to each point
  double x, y;
  
  //each of the 4 points is read 
  for(int i = 0; i < 4; i++)
  {
    input >> x;
    input >> y;
    pts[i].setXY(x, y);
  }
  
  //points and color are given to a Quadrilateral, which is then added to the vector
  Quadrilateral newQuad(pts[0], pts[1], pts[2], pts[3], blue);
  quads.push_back(newQuad);
}

/*Works through the shapes in each vector to ensure that the shapes fall
  within the image*/
void checkPoints(vector<Triangle>& tris, vector<Circle>& circs, 
  vector<Quadrilateral>& quads, Image& image)
{
  //height and width of image set to be used in calculations 
  double height, width;
  
  height = (double) image.getHeader().getHeight();
  width = (double) image.getHeader().getWidth();
  
  //First loop checks each triangle
  for(int i = 0; i < tris.size(); i++)
  {
    checkTriangle(tris.at(i), height, width);
  }
  
  //Second loop checks each circle
  for(int i = 0; i < circs.size(); i++)
  {
    checkCircle(circs.at(i), height, width);
  }
  
  //Third loop checks each quadrilateral
  for(int i = 0; i < quads.size(); i++)
  {
    checkQuadrilateral(quads.at(i), height, width); 
  }
}

/*Checks to see if the points of a single triangle are within the height and 
  width*/
void checkTriangle(Triangle &myTri, double h, double w)
{
  /*Checks each point to make sure that point are not negative, if any are
    then the program is exited*/
  if((myTri.getAx() < 0 || myTri.getAy() < 0) || 
    (myTri.getBx() < 0 || myTri.getBy() < 0) ||
    (myTri.getCx() < 0 || myTri.getCy() < 0))
  {
    cout << "ERROR: One of the coordinates of the triangles is less than 0";
    cout << endl << "Exiting program." << endl;
    exit(0);
  }
  
  /*Checks to make sure none of the points are too large for the image, if any
    are then the program is exited*/
  if((myTri.getAx() > w || myTri.getAy() > h) || 
    (myTri.getBx() > w || myTri.getBy() > h) ||
    (myTri.getCx() > w || myTri.getCy() > h))
  {
    cout << "ERROR: One of the coordinates of the triangles exceeds the size"
      " of the image";
    cout << endl << "Exiting program." << endl;
    exit(0);
  }
}

/*Checks to see if the circle is within the height and with, particularly by
  checking the maximums and minimums of the circle's height and width*/
void checkCircle(Circle &myCirc, double h, double w)
{
  /*Maximum and minimum x and y values of the circle are calculated by
    adding and substracting the radius to the center point. Each one is then
    compared to 0, the height, or the width to check to see if it's within*/
  if((myCirc.getCx() - (double)myCirc.getRadius() < 0) ||
    (myCirc.getCy() - (double)myCirc.getRadius() < 0) ||
    (myCirc.getCx() + (double)myCirc.getRadius() > w) ||
    (myCirc.getCy() + (double)myCirc.getRadius() > h))
  {
    cout << "ERROR: One of circles does not fit within the Image" << endl;
    cout << "Exiting program." << endl;
    exit(0);   
  }
}

void checkQuadrilateral(Quadrilateral &myQuad, double h, double w)
{
  /*Checks each point to make sure that points are not negative, if any are
    then the program is exited*/
  if((myQuad.getAx() < 0 || myQuad.getAy() < 0) || 
    (myQuad.getBx() < 0 || myQuad.getBy() < 0) ||
    (myQuad.getCx() < 0 || myQuad.getCy() < 0) ||
    (myQuad.getDx() < 0 || myQuad.getDy() < 0))
  {
    cout << "ERROR: One of the coordinates of the quadrilaterals is"
      " less than 0";
    cout << endl << "Exiting program." << endl;
    exit(0);
  }
  
  /*Checks to make sure none of the points are too large for the image, if any
    are then the program is exited*/
  if((myQuad.getAx() > w || myQuad.getAy() > h) || 
    (myQuad.getBx() > w || myQuad.getBy() > h) ||
    (myQuad.getCx() > w || myQuad.getCy() > h) ||
    (myQuad.getDx() > w || myQuad.getDy() > h))
  {
    cout << "ERROR: One of the coordinates of the quadrilaterals exceeds the"
      " size of the image";
    cout << endl << "Exiting program." << endl;
    exit(0);
  }
}
