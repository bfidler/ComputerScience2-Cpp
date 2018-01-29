/************************
	Brayden Fidler
	CPSC Section 1, Sp17
	bfidler
*************************/

#include "Image.h"

/*overloaded constructor - uses overloaded constructor for header and 
  allocates memory for a 2d pixel array*/
Image::Image(string mag, int w, int h, int m)
{ 
  //Header created using overloaded constructor
  Header newHead(mag, w, h, m);
  aHeader = newHead;
  //Allocating memory for 2d array based on new height/width of image
  Pixels = new Pixel*[aHeader.getHeight()];
  
  for(int i = 0; i < aHeader.getHeight(); i++)
  {
    //Each index of 2d array assigned memory
    Pixels[i] = new Pixel[aHeader.getWidth()];
    for(int j = 0; j < aHeader.getWidth(); j++)
    {
      //Each pixel is given the correct coordinates
      Pixels[i][j].setPoint((double)j,(double)i);
    }
  }
}

//copy constructor
Image::Image(const Image &obj)
{
  //copying header with member wise assignment
  aHeader = obj.aHeader;
  //dynamically allocating a double pointer array
  Pixels = new Pixel*[aHeader.getHeight()];
  for(int i = 0; i < aHeader.getHeight(); i++)
  {
    //dynamically allocating each index for the double pointer array
    Pixels[i] = new Pixel[aHeader.getWidth()];
    //assigning each pixel from the object to the Image
    for(int j = 0; j < aHeader.getWidth(); i++)
    {
      Pixels[i][j] = obj.Pixels[i][j];
    }
  }          
}

//Overloaded = operator - code is very similar to copy constructor
Image Image::operator=(const Image &right)
{
  /*checks height to see if image has already been created and deletes
    the allocated memory for the 2d pixel array if so*/
  if(aHeader.getHeight() > 0)
  {
    for(int i = 0; i < aHeader.getHeight(); i++)
    {
      delete [] Pixels[i];
    }
    //deletes memory for double pointer itself
    delete [] Pixels;
  }
  //copying header with member wise assignment
  aHeader = right.aHeader;
  //dynamically allocating a double pointer array
  Pixels = new Pixel*[aHeader.getHeight()];
  for(int i = 0; i < aHeader.getHeight(); i++)
    {
      //dynamically allocating each index for the double pointer array
      Pixels[i] = new Pixel[aHeader.getWidth()];
      //assigning each pixel from the object to the Image
      for(int j = 0; j < aHeader.getWidth(); i++)
      {
        Pixels[i][j] = right.Pixels[i][j];
      }
    }
  //returning the Image
  return *this;
}

//Destructor
Image::~Image()
{ 
  //deletes memory for each index of the double pointer
  for(int i = 0; i < aHeader.getHeight(); i++)
  {
    delete [] Pixels[i];
  }
  //deletes memory for double pointer itself
  delete [] Pixels;
}

/*Background color of image set with a color value using a double for loop
  to set each pixel in the 2d array to the color*/
void Image::setBackground(Color myC)
{
  for(int i = 0; i < aHeader.getHeight(); i++)
  {
    for(int j = 0; j < aHeader.getWidth(); j++)
    {
      //passing color using overloaded Pixel function
      Pixels[i][j].setColor(myC);
    }
  }
}

//Horizontal Stripes set to background of the images using two colors
void Image::setStripes(Color c1, Color c2)
{
  //Double for loop to go through each pixel in the array
  for(int i = 0; i < aHeader.getHeight(); i++)
  {
    for(int j = 0; j < aHeader.getWidth(); j++)
    {
      //creates bands 100 pixels wide
      if((i % 200) > 100)
      {
        //sets pixel to first color
        Pixels[i][j].setColor(c1);
      }
      else
      {
        //sets pixel to second color
        Pixels[i][j].setColor(c2);
      }
    }
  }
}

//Populates the Image with valid Triangles from a vector
void Image::setTriangles(vector<Triangle> &tris)
{
  //this loop runs through each triangle in the vector
  for(int i = 0; i < tris.size(); i++)
  {
    //this double loop is used to iterate through each Pixel in the 2d array
    for(int j = 0; j < aHeader.getHeight(); j++)
    {
      for(int k = 0; k < aHeader.getWidth(); k++)
      {
        //for barycentric coordinates
        double a, b, c;
        
        /*The next 3 blocks of code are calculating the barycentric coordinates
          using points from each of the triangles in the vector and the point
          of the pixel that is currently */
        a = ((tris.at(i).getBy() - tris.at(i).getCy()) * 
          (Pixels[j][k].getPoint().getX() - tris.at(i).getCx()) + 
          (tris.at(i).getCx() - tris.at(i).getBx()) * 
          (Pixels[j][k].getPoint().getY() - tris.at(i).getCy())) / 
          ((tris.at(i).getBy() - tris.at(i).getCy()) * (tris.at(i).getAx() 
          - tris.at(i).getCx()) + (tris.at(i).getCx() - tris.at(i).getBx()) 
          *(tris.at(i).getAy() - tris.at(i).getCy()));

        b = ((tris.at(i).getCy() - tris.at(i).getAy()) * 
          (Pixels[j][k].getPoint().getX() - tris.at(i).getCx()) + 
          (tris.at(i).getAx() - tris.at(i).getCx()) * 
          (Pixels[j][k].getPoint().getY() - tris.at(i).getCy())) / 
          ((tris.at(i).getBy() - tris.at(i).getCy()) * (tris.at(i).getAx() - 
          tris.at(i).getCx()) + (tris.at(i).getCx() - tris.at(i).getBx()) * 
          (tris.at(i).getAy() - tris.at(i).getCy()));
	
        c = 1 - a - b;
        
        /*for the points that fall within the triangle according to the
          barycentric coordinates the color of the triangle is passed to
          the pixel*/
        if((a <= 1 && a >= 0) && (b <= 1 && b >= 0) && (c <= 1 && c >= 0))
        {
          Pixels[j][k].setColor(tris.at(i).getColor());
        } 
      }
    }
  }
}

//Populates the Image with valid Circles from a vector
void Image::setCircles(vector<Circle> &circs)
{
  /*If three circles with the same center but different sizes are given, 
    then the circles will be stacked on top of each other with different 
    colors according to their size*/
  if(circs.size() == 3)
  {  cout << "check one" << endl;
    //checking to see if centers of the circle are the same
    if((circs.at(0).getCx() == circs.at(1).getCx()) && 
      (circs.at(1).getCx() == circs.at(2).getCx()) &&
      (circs.at(0).getCy() == circs.at(1).getCy()) &&
      (circs.at(1).getCy() == circs.at(2).getCy()))
    {  cout << "check two" << endl;
      //selection sort used on circles with their radii
      for(int i = 0; i < 3; i++)
      {
        int max = i;
        
        for(int j = i + 1; j < 3; j++)
        {  
          //sets new max if current circle is bigger than the current max
          if(circs.at(j).getRadius() > circs.at(max).getRadius())
          {
            max = j;
          }
        }
        
        //swapping biggest circle with circle i
        if(max != i)
        { cout << "check three" << endl;
          Circle temp = circs.at(i);
          circs.at(i) = circs.at(max);
          circs.at(max) = temp;
        }  
      }
      
      Color white(255, 255, 255);
      //center circle set to white
      circs.at(1).setColor(white);
    }
  }
  
  for(int i = 0; i < circs.size(); i++)
  {
    for(int j = 0; j < aHeader.getHeight(); j++)
    {
      for(int k = 0; k < aHeader.getWidth(); k++)
      {
        double d;
    
        d = sqrt(pow((Pixels[j][k].getPoint().getX() - 
          circs.at(i).getCx()), 2) + pow((Pixels[j][k].getPoint().getY() - 
          circs.at(i).getCy()), 2));
          
        if(d < (double)circs.at(i).getRadius())
        {
          Pixels[j][k].setColor(circs.at(i).getColor());
        }
      }
    }
  }
}

//Populates the Image with valid Quads from a vector
void Image::setQuadrilaterals(vector<Quadrilateral> &quads)
{
  //this loop runs through each quad in the vector
  for(int i = 0; i < quads.size(); i++)
  {
    //this double loop is used to iterate through each Pixel in the 2d array
    for(int j = 0; j < aHeader.getHeight(); j++)
    {
      for(int k = 0; k < aHeader.getWidth(); k++)
      {
        //for barycentric coordinates
        double a[3], b[3], c[3];
        
        a[0] = ((quads.at(i).getBy() - quads.at(i).getCy()) * 
          (Pixels[j][k].getPoint().getX() - quads.at(i).getCx()) + 
          (quads.at(i).getCx() - quads.at(i).getBx()) * 
          (Pixels[j][k].getPoint().getY() - quads.at(i).getCy())) / 
          ((quads.at(i).getBy() - quads.at(i).getCy()) * (quads.at(i).getAx() 
          - quads.at(i).getCx()) + (quads.at(i).getCx() - quads.at(i).getBx()) 
          *(quads.at(i).getAy() - quads.at(i).getCy()));

        b[0] = ((quads.at(i).getCy() - quads.at(i).getAy()) * 
          (Pixels[j][k].getPoint().getX() - quads.at(i).getCx()) + 
          (quads.at(i).getAx() - quads.at(i).getCx()) * 
          (Pixels[j][k].getPoint().getY() - quads.at(i).getCy())) / 
          ((quads.at(i).getBy() - quads.at(i).getCy()) * (quads.at(i).getAx() - 
          quads.at(i).getCx()) + (quads.at(i).getCx() - quads.at(i).getBx()) * 
          (quads.at(i).getAy() - quads.at(i).getCy()));
	
        c[0] = 1 - a[0] - b[0];
        
        a[1] = ((quads.at(i).getBy() - quads.at(i).getDy()) * 
          (Pixels[j][k].getPoint().getX() - quads.at(i).getDx()) + 
          (quads.at(i).getDx() - quads.at(i).getBx()) * 
          (Pixels[j][k].getPoint().getY() - quads.at(i).getDy())) / 
          ((quads.at(i).getBy() - quads.at(i).getDy()) * (quads.at(i).getAx() 
          - quads.at(i).getDx()) + (quads.at(i).getDx() - quads.at(i).getBx()) 
          *(quads.at(i).getAy() - quads.at(i).getDy()));

        b[1] = ((quads.at(i).getDy() - quads.at(i).getAy()) * 
          (Pixels[j][k].getPoint().getX() - quads.at(i).getDx()) + 
          (quads.at(i).getAx() - quads.at(i).getDx()) * 
          (Pixels[j][k].getPoint().getY() - quads.at(i).getDy())) / 
          ((quads.at(i).getBy() - quads.at(i).getDy()) * (quads.at(i).getAx() - 
          quads.at(i).getDx()) + (quads.at(i).getDx() - quads.at(i).getBx()) * 
          (quads.at(i).getAy() - quads.at(i).getDy()));
	
        c[1] = 1 - a[0] - b[0];
        
        a[2] = ((quads.at(i).getCy() - quads.at(i).getDy()) * 
          (Pixels[j][k].getPoint().getX() - quads.at(i).getDx()) + 
          (quads.at(i).getDx() - quads.at(i).getCx()) * 
          (Pixels[j][k].getPoint().getY() - quads.at(i).getDy())) / 
          ((quads.at(i).getCy() - quads.at(i).getDy()) * (quads.at(i).getAx() 
          - quads.at(i).getDx()) + (quads.at(i).getDx() - quads.at(i).getCx()) 
          *(quads.at(i).getAy() - quads.at(i).getDy()));

        b[2] = ((quads.at(i).getDy() - quads.at(i).getAy()) * 
          (Pixels[j][k].getPoint().getX() - quads.at(i).getDx()) + 
          (quads.at(i).getAx() - quads.at(i).getDx()) * 
          (Pixels[j][k].getPoint().getY() - quads.at(i).getDy())) / 
          ((quads.at(i).getCy() - quads.at(i).getDy()) * (quads.at(i).getAx() - 
          quads.at(i).getDx()) + (quads.at(i).getDx() - quads.at(i).getCx()) * 
          (quads.at(i).getAy() - quads.at(i).getDy()));
	
        c[2] = 1 - a[2] - b[2];
        
        for(int m = 0; m < 3; m++)
        {  
          if((a[m] <= 1 && a[m] >= 0) && (b[m] <= 1 && b[m] >= 0) && 
            (c[m] <= 1 && c[m] >= 0))
          {
            Pixels[j][k].setColor(quads.at(i).getColor());
          }
        }   
      }
    }
  }
}

//Returns the header of the image
Header Image::getHeader()
{
  return aHeader;
}

/*Prints the header of the image by calling the getter function of the
  Header class, passing the output file for it to print to*/
void Image::printHeader(ofstream& output)
{
	aHeader.printHeader(output);
}

/*Prints contents of the 2d pixel array to output file. It uses a 2d array to
  go through each individual and call the printRGB function*/
void Image::printPixels(ofstream& output)
{
  for(int i = 0; i < aHeader.getHeight(); i++)
  {
    for(int j = 0; j < aHeader.getWidth(); j++)
    {
      Pixels[i][j].printRGB(output);
    }
  }
}
