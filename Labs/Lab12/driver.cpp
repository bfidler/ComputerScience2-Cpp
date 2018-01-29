/***********************
	Brayden Fidler
	bfidler
	Lab 12
	Lab Section 1
	Nick Glyder
***********************/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "functions.h"

using namespace std;

int main( int argc, char* argv[] )
{
    //create a file pointer
    // Using the command line arguments check for a valid input file
    // If there is not one, give the user a message and exit the program
	
	  ifstream input;
	  if(argc == 2)
  	{	
	  	input.open(argv[1]);
	  	if(input.fail())
  		{
	  		cout << "Error opening file. Exiting." << endl;
	  		exit(0);
	  	}
  	}
	  else
  	{
  		cout << "Error opening file. Exiting." << endl;
  		exit(0);
	  }


    // Assuming there is a valid input file, read the first item
    // The first item represents the number of items in the file

	  int arraySize;
	  input >> arraySize;

    /*Dynamically allocate the memory for the array that is going to
     *hold the numbers be read in*/

    int *intArray = new int[arraySize];

    /*Read in the numbers from the file storing them in array*/

	  for(int i = 0; i < arraySize; i++)
	  {
	  	input >> intArray[i];
	  }

    /* Close the file you are reading.*/

  	input.close();	

    /*Print the array to make sure you read in all the values correctly*/

  	print_array(intArray, arraySize);

    /*Using the quicksort function sort the array.*/

    quickSort(intArray, 0, arraySize - 1);

    /*Now Print the sorted array to make sure it is sorted*/

    print_array(intArray, arraySize);

    /*To test the binary search algorithm ask the user for a number.
     *Call the binary search function.  If the number was found tell the
     *user you found the number and at what index it was found.*/

    int search;
    cout << "Enter a search value: ";
    cin >> search;
    
    int position = binarySearch(intArray, 0, arraySize - 1, search);
    if(position == -1)
    {
      cout << search << " was not found" << endl;
    }
    else
    {
      cout << search << " was found at index: " << position << endl;
    }

     //delete dynamically allocated array
	  delete [] intArray;

    return 0;
}
